#include <string.h>
#include "../../lib/user.h"
#include "../../lib/loginedUser.h"

#define LOGIN_SUCCESS_USER "1100"
#define LOGIN_SUCCESS_ADMIN "1110"
#define LOGIN_FAIL "2100"
#define LOGIN_ALREADY "2101"
#define LOGOUT_SUCCESS "1102"
#define LOGOUT_FAIL "2103"

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

int handleRegister(char *username, char *password) {
    FILE *fp = fopen("data/account.txt", "a"); 
    if (fp == NULL) {
        perror("Error: ");
        return 0; // fail
    }

    
    fprintf(fp, "%s\t%s\t%d\n", username, password, 0); 
    fclose(fp);
    return 1; // successful
}

// void logout(int *login_status, int socketfd, char *username, int total_account_loggined,  char *list_account_logined[]){
//     if(*login_status == 0){
//         printf("%s\n", LOGOUT_FAIL);
//         send(socketfd, LOGOUT_FAIL, sizeof(LOGOUT_FAIL), 0);
//     }else{
//         for(int i = 0; i < total_account_loggined; i++){
//             if(strcmp(list_account_logined[i], username) == 0){
//                 for(int j = i; j < total_account_loggined; j++){
//                     list_account_logined[j] = list_account_logined[i+1];
//                 }
//             }
//         }
//         total_account_loggined--;
//         *login_status = 0;
//         printf("%s\n", LOGOUT_SUCCESS);
//         send(socketfd, LOGOUT_SUCCESS, sizeof(LOGOUT_SUCCESS), 0);
//     }
// }
