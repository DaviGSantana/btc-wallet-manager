#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"

// Defina seus dados de acesso RPC aqui
#define RPC_USER "usuario"
#define RPC_PASSWORD "senha"
#define RPC_URL "http://127.0.0.1:8332/"

struct string {
    char *ptr;
    size_t len;
};

void init_string(struct string *s) {
    s->len = 0;
    s->ptr = malloc(1);
    s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s) {
    size_t new_len = s->len + size * nmemb;
    s->ptr = realloc(s->ptr, new_len + 1);
    memcpy(s->ptr + s->len, ptr, size * nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;
    return size * nmemb;
}

const char* rpc_call(const char* method, const char* params_json) {
    CURL *curl = curl_easy_init();
    struct string response;
    init_string(&response);

    if (!params_json) params_json = "[]";

    char postdata[1024];
    snprintf(postdata, sizeof(postdata),
        "{ \"jsonrpc\": \"1.0\", \"id\":\"btcwallet\", \"method\": \"%s\", \"params\": %s }",
        method, params_json);

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, RPC_URL);
        curl_easy_setopt(curl, CURLOPT_USERNAME, RPC_USER);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, RPC_PASSWORD);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    cJSON *json = cJSON_Parse(response.ptr);
    cJSON *result = cJSON_GetObjectItem(json, "result");
    char *out = cJSON_PrintUnformatted(result);

    cJSON_Delete(json);
    free(response.ptr);

    return out;
}
