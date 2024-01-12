#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>
#include "../../lib/loginedUser.h"
#include "../../lib/users/listUser.h"

#define LOGIN_SUCCESS_USER "1010"
#define LOGIN_SUCCESS_ADMIN "1011"
#define LOGIN_FAIL "2011"
#define LOGIN_ALREADY "2101"
#define LOGOUT_SUCCESS "1102"
#define LOGOUT_FAIL "2103"
#define REGISTER_SUCCESS "1101"
#define REGISTER_FAIL "2102"

/**
 * @brief select all users
 * 
 * @param connection : connection of mysql
 * @param h : node user
 * @param x : user
 */
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

/**
 * @brief Create a List Logined Account object
 * 
 * @return listLoginedAccount 
 */
listLoginedAccount createListLoginedAccount() {
    listLoginedAccount arr;
    arr.data = malloc(INITIAL_CAPACITY * sizeof(char *));
    arr.size = 0;
    arr.capacity = INITIAL_CAPACITY;
    return arr;
}

/**
 * @brief add a logined account to the list of logined  accounts
 * 
 * @param arr : listLoginedAccount
 * @param value : loginedAccount
 */
void addToListLoginedAccount(listLoginedAccount *arr, char **value) {
    if (arr->size >= arr->capacity) {
        arr->capacity += INCREMENT;
        arr->data = realloc(arr->data, arr->capacity * sizeof(char *));
    }
    arr->data[arr->size] = malloc((strlen(*value) + 1) * sizeof(char));
    strcpy(arr->data[arr->size], *value);
    arr->size++;
}

/**
 * @brief frees memory allocated
 * 
 * @param arr : list to free
 */
void freeListLoginedAccount(listLoginedAccount *arr) {
    for (size_t i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr->data);
    arr->size = 0;
    arr->capacity = 0;
}

/**
 * @brief search for a logined account
 * 
 * @param arr : list of logined accounts
 * @param value : value to search
 * @return int 
 */
int searchListLoginedAccount(const listLoginedAccount *arr, char **value) {
    for (size_t i = 0; i < arr->size; i++) {
        if (strcmp(arr->data[i], *value) == 0) {
            return i; 
        }
    }
    return -1; 
}

/**
 * @brief deletes the account from the list of logined accounts
 * 
 * @param arr : list of logined accounts
 * @param value : account to be deleted
 */
void deleteFromListLoginedAccount(listLoginedAccount *arr, char **value) {
    int index = searchListLoginedAccount(arr, value);

    if (index != -1) {
        free(arr->data[index]);  
        arr->data[index] = arr->data[arr->size - 1];  
        arr->size--;
    }

}

/**
 * @brief Create a List Logined User object
 * 
 * @param arr 
 * @return listLoginedAccount 
 */
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
int checkLogin(node head, char **username, char *password, listLoginedAccount *arr){

    // Check account have loggined in different address or yet
    int check_logined = searchListLoginedAccount(arr, username);
    if(check_logined >= 0){
        return 3;
    }

    struct Node* p = head;
    while(p != NULL){
        if((strcmp(*username, p->data.username) == 0) && (strcmp(password, p->data.password) == 0)){
            if(p->data.role_id == 1){
                printf("%s\n", LOGIN_SUCCESS_ADMIN);
                return 1;
            }else if(p->data.role_id == 2){
                printf("%s\n", LOGIN_SUCCESS_USER);
                return 2;
            }            
        }
        p = p->next;
    }

    printf("%s\n", LOGIN_FAIL);
    return 0;
}

/**
 * @brief add a user to the database
 * 
 * @param connection : connection of mysql
 * @param newUser : new user
 * @return int 
 */
int registerUser(MYSQL *connection, user newUser) {
    char query[1024];

    // Kiểm tra xem username đã tồn tại chưa
    sprintf(query, "SELECT username FROM users WHERE username = '%s'", newUser.username);
    mysql_query(connection, query);
    MYSQL_RES *result = mysql_store_result(connection);
    if (mysql_num_rows(result) > 0) { // Nếu tìm thấy username
        mysql_free_result(result);
        return 0; // Đăng ký thất bại do trùng tên người dùng
    }
    mysql_free_result(result);

    // Thực hiện thêm người dùng mới
sprintf(query, "INSERT INTO users (name, username, password, role_id) VALUES ('%s','%s', '%s', %ld)", newUser.name, newUser.username, newUser.password, newUser.role_id);
    if (mysql_query(connection, query)) {
        fprintf(stderr, "Register Error: %s\n", mysql_error(connection));
        return 0; // Thất bại
    } else {
        return 1; // Thành công
    }
}

/**
 * @brief change the password  in the database
 * 
 * @param connection : connection of mysql
 * @param username : username of the account
 * @param oldPassword : old password of the account
 * @param newPassword : new password of the account
 * @return int 
 */
int changePassword(MYSQL *connection, char *username, char *oldPassword, char *newPassword) {
    char query[1024];
    sprintf(query, "SELECT password FROM users WHERE username = '%s'", username);
    mysql_query(connection, query);
    MYSQL_RES *result = mysql_store_result(connection);
    MYSQL_ROW row = mysql_fetch_row(result);
    if (!row || strcmp(row[0], oldPassword) != 0) {
        mysql_free_result(result);
        return 0;
    }
    printf("%s",row[0]);
    mysql_free_result(result);

    sprintf(query, "UPDATE users SET password = '%s' WHERE username = '%s'", newPassword, username);
    if (mysql_query(connection, query)) {
        printf("kkk");
        return 0; // failed
    }

    return 1; // success
}