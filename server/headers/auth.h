#include <string.h>
#include "../../lib/user.h"

#define LOGIN_SUCCESS 1100
#define LOGIN_SUCCESS_MESSAGE "You have logged in successfully!!\n"
#define LOGIN_FAIL 2100
#define LOGIN_FAIL_MESSAGE "Your username or password is incorrect!!\n"
#define LOGIN_ALREADY 2101
#define LOGIN_ALREADY_MESSAGE "Your account is being used in another address\n"

/**
 * @function checkLogin: checking account exist and is bannedned.
 * 
 * @param head: Node 
 * @param username: A input string.
 * 
*/
int checkLogin(int socketfd, node head, char *username, char *password, int total_account_logined, char *list_account_logined[]){

    // Check account have loggined in different address or yet
    if(total_account_logined != 0){
        for(int i = 0; i < total_account_logined; i++){
            if(strcmp(list_account_logined[i], username) == 0){
                printf("%d\n", LOGIN_ALREADY);
                send(socketfd, LOGIN_ALREADY_MESSAGE, sizeof(LOGIN_ALREADY_MESSAGE), 0);
                return 2;
            }
        }
    }

    struct Node* p = head;
    if(p == NULL) printf("err\n");
    while(p != NULL){
        printf("%s\n", p->data.username);
        if((strcmp(username, p->data.username) == 0) && (strcmp(password, p->data.password) == 0)){
            printf("%d\n", LOGIN_SUCCESS);
            send(socketfd, LOGIN_SUCCESS_MESSAGE, sizeof(LOGIN_SUCCESS_MESSAGE), 0);
            return 1;
        }
        p = p->next;
    }

    printf("%d\n", LOGIN_FAIL);
    send(socketfd, LOGIN_FAIL_MESSAGE, sizeof(LOGIN_FAIL_MESSAGE), 0);
    return 0;
}
