#include <string.h>
#include "../../lib/user.h"

#define LOGIN_SUCCESS_USER "1100"
#define LOGIN_SUCCESS_ADMIN "1110"
#define LOGIN_FAIL "2100"
#define LOGIN_ALREADY "2101"

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
int checkLogin(int socketfd, node head, char *username, char *password, int total_account_logined, char *list_account_logined[]){

    // Check account have loggined in different address or yet
    if(total_account_logined != 0){
        for(int i = 0; i < total_account_logined; i++){
            if(strcmp(list_account_logined[i], username) == 0){
                printf("%s\n", LOGIN_ALREADY);
                send(socketfd, LOGIN_ALREADY, sizeof(LOGIN_ALREADY), 0);
                return 2;
            }
        }
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
