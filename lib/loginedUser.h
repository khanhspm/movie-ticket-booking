#include <string.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5
#define INCREMENT 5

struct ListLoginedAccount{
    char **data;
    size_t size;
    size_t capacity;
};

typedef struct ListLoginedAccount listLoginedAccount;

listLoginedAccount createListLoginedAccount() {
    listLoginedAccount arr;
    arr.data = malloc(INITIAL_CAPACITY * sizeof(char *));
    arr.size = 0;
    arr.capacity = INITIAL_CAPACITY;
    return arr;
}

void addToListLoginedAccount(listLoginedAccount *arr, const char *value) {
    if (arr->size >= arr->capacity) {
        arr->capacity += INCREMENT;
        arr->data = realloc(arr->data, arr->capacity * sizeof(char *));
    }
    arr->data[arr->size] = malloc((strlen(value) + 1) * sizeof(char));
    strcpy(arr->data[arr->size], value);
    arr->size++;
}

void freeListLoginedAccount(listLoginedAccount *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr->data);
    arr->size = 0;
    arr->capacity = 0;
}

int searchListLoginedAccount(const listLoginedAccount *arr, const char *value) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->data[i], value) == 0) {
            return i; 
        }
    }
    return -1; 
}
