#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>
#include "../../lib/loginedUser.h"
#include "../../lib/users/listUser.h"

#define LOGIN_SUCCESS_USER "1100"
#define LOGIN_SUCCESS_ADMIN "1110"
#define LOGIN_FAIL "2100"
#define LOGIN_ALREADY "2101"
#define LOGOUT_SUCCESS "1102"
#define LOGOUT_FAIL "2103"
#define REGISTER_SUCCESS "1101"
#define REGISTER_FAIL "2102"

void selectUser(MYSQL *connection, node* h, user x){
    mysql_query(connection, "SELECT * FROM users");
    MYSQL_RES *result = mysql_store_result(connection);
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        x.id = strtoul(row[0], NULL, 10);
        strcpy(x.name, row[1]);
        strcpy(x.username, row[2]);
        strcpy(x.password, row[3]);
        x.role_id = strtoul(row[4], NULL, 10);

        addNode(h, x);

    }

    mysql_free_result(result);
}

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


listLoginedAccount createListLoginedUser(listLoginedAccount arr){
    freeListLoginedAccount(&arr);
    arr = createListLoginedAccount();
    return arr;
}

/**
 * @function checkLogin: check login status
 * 
 * @param socketfd : socket to connect
 * @param head : node of the head
 * @param username : username to login
 * @param password : password to login
 * @param total_account_logined : total account logged in
 * @param list_account_logined : list account logged in
 * @return int 
 */
int checkLogin(node head, char *username, char *password, listLoginedAccount arr){

    // Check account have loggined in different address or yet
    int check_logined = searchListLoginedAccount(&arr, username);
    if(check_logined > 0){
        return 2;
    }

    struct Node* p = head;
    while(p != NULL){
        printf("%s\n", p->data.username);
        if((strcmp(username, p->data.username) == 0) && (strcmp(password, p->data.password) == 0)){
            if(p->data.role_id == 1){
                printf("%s\n", LOGIN_SUCCESS_ADMIN);
            }else if(p->data.role_id == 0){
                printf("%s\n", LOGIN_SUCCESS_USER);
            }
            
            return 1;
        }
        p = p->next;
    }

    printf("%s\n", LOGIN_FAIL);
    return 0;
}
