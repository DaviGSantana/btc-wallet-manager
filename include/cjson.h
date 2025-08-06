#ifndef CJSON_H
#define CJSON_H

typedef enum {
    cJSON_False = 0,
    cJSON_True,
    cJSON_NULL,
    cJSON_Number,
    cJSON_String,
    cJSON_Array,
    cJSON_Object
} cJSON_Type;

typedef struct cJSON {
    cJSON_Type type;
    char *string;
    union {
        char *valuestring;
        double valuedouble;
        struct cJSON *child;
    };
    struct cJSON *next;
    struct cJSON *prev;
} cJSON;

cJSON *cJSON_Parse(const char *value);
void cJSON_Delete(cJSON *item);
const char *cJSON_GetErrorPtr(void);
cJSON *cJSON_GetObjectItem(const cJSON *object, const char *string);
const char *cJSON_Print(const cJSON *item);

#endif
