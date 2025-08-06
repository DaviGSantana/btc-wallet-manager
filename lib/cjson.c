#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cjson.h"

static const char *error_ptr = NULL;

const char *cJSON_GetErrorPtr(void) {
    return error_ptr;
}

cJSON *cJSON_Parse(const char *value) {
    // Exemplo fictício para demonstração
    // Use a versão completa da biblioteca para parsing real
    if (strstr(value, "\"result\"") != NULL) {
        cJSON *item = malloc(sizeof(cJSON));
        item->type = cJSON_Object;
        item->string = strdup("result");
        item->valuestring = strdup("ok");
        item->next = item->prev = NULL;
        return item;
    }

    error_ptr = value;
    return NULL;
}

void cJSON_Delete(cJSON *item) {
    if (!item) return;
    if (item->string) free(item->string);
    if (item->valuestring) free(item->valuestring);
    free(item);
}

cJSON *cJSON_GetObjectItem(const cJSON *object, const char *string) {
    if (object && object->string && strcmp(object->string, string) == 0) {
        return (cJSON *)object;
    }
    return NULL;
}

const char *cJSON_Print(const cJSON *item) {
    if (!item) return NULL;
    return item->valuestring;
}
