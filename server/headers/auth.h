#include <string.h>
#include "../../lib/user.h"
#include "../../lib/loginedUser.h"

#define LOGIN_SUCCESS_USER "1100"
#define LOGIN_SUCCESS_ADMIN "1110"
#define LOGIN_FAIL "2100"
#define LOGIN_ALREADY "2101"
#define LOGOUT_SUCCESS "1102"
#define LOGOUT_FAIL "2103"
#define REGISTER_SUCCESS "1101"
#define REGISTER_FAIL "2102"


listLoginedAccount createListLoginedUser(listLoginedAccount arr){
    freeListLoginedAccount(&arr);
    return createListLoginedAccount();
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
int checkLogin(int socketfd, node head, char *username, char *password, listLoginedAccount arr){

    // Check account have loggined in different address or yet
    int check_logined = searchListLoginedAccount(&arr, username);
    if(check_logined > 0){
        return 2;
    }

    struct Node* p = head;
    if(p == NULL) printf("err\n");
    while(p != NULL){
        printf("%s\n", p->data.username);
        if((strcmp(username, p->data.username) == 0) && (strcmp(password, p->data.password) == 0)){
            if(p->data.role == 1){
                printf("%s\n", LOGIN_SUCCESS_ADMIN);
                send(socketfd, LOGIN_SUCCESS_ADMIN, sizeof(LOGIN_SUCCESS_ADMIN), 0);
            }else if(p->data.role == 0){
                printf("%s\n", LOGIN_SUCCESS_USER);
                send(socketfd, LOGIN_SUCCESS_USER, sizeof(LOGIN_SUCCESS_USER), 0);
            }
            
            return 1;
        }
        p = p->next;
    }

    printf("%s\n", LOGIN_FAIL);
    send(socketfd, LOGIN_FAIL, sizeof(LOGIN_FAIL), 0);
    return 0;
}

// Add a function to check if a username already exists
int checkUsernameExistence(char *username) {
    FILE *fp = fopen("data/account.txt", "r");
    if (fp == NULL) {
        perror("Error opening file: ");
        return 0; // fail
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char existingUsername[256];
        sscanf(line, "%s", existingUsername);

        if (strcmp(existingUsername, username) == 0) {
            fclose(fp);
            return 1; // Username already exists
        }
    }

    fclose(fp);
    return 0; // Username does not exist
}

// Chức năng đăng ký với mã trả lời thích hợp
int handleRegister(char *username, char *password, char *resultMessage) {
    FILE *fp = fopen("data/account.txt", "a");
    if (fp == NULL) {
        perror("Error opening file: ");
        return 0; // fail
    }

    //check thong diep tra ve tu server
    printf("server response: %s\n", resultMessage);

    // Validate username and password
    if (username == NULL || password == NULL) {
        printf("Invalid input parameters\n");
        fclose(fp);
        return 0; // fail
    }

    // Check if the username already exists in the file
    if (checkUsernameExistence(username)) {
        printf("Username already exists\n");
        fclose(fp);
        strcpy(resultMessage, "REGISTER_FAIL Username already exists");
        return 0; // fail
    }

    // Write user information to file
    fprintf(fp, "%s\t%s\t%d\n", username, password, 0);

    if (!checkUsernameExistence(username)) {
    // Dọn dẹp và đóng
    fclose(fp);

    strcpy(resultMessage, "REGISTER_SUCCESS You have successfully registered");
    return 1; // Thành công
    }

    // // Clean up and close 
    // fclose(fp);

    // strcpy(resultMessage, "REGISTER_SUCCESS You have successfully registered");
    // return 1; // successful
}



