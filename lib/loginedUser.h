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
