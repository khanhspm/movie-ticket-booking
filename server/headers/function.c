#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"
#include "queryUser.h"

#define LOGIN_SUCCESS_USER 1100
#define LOGIN_SUCCESS_ADMIN 1110
#define LOGIN_FAIL 2100
#define LOGIN_ALREADY 2101
#define LOGOUT_SUCCESS 1102
#define REGISTER_SUCCESS 1101
#define REGISTER_FAIL 2102
#define ADD_FILM_SUCCESS 1200
#define ADD_FILM_FAIL 2200
#define POST_FILM_SUCCESS 1201
#define POST_FILM_FAIL 2201
#define EDIT_FILM_SUCCESS 1202
#define EDIT_FILM_FAIL 2202
#define NO_EDIT_FILM 2203
#define BROWSE_CATEGORY_SUCCESS 1301
#define BROWSE_THEATER_SUCCESS 1302
#define BROWSE_TIME_SUCCESS 1303
#define BROWSE_FAIL 2300
#define FIND_FILM_SUCCESS 1304
#define FIND_FILM_FAIL 2301
#define VIEW_CHAIR_SUCCESS 1305
#define VIEW_CHAIR_FAIL 2302
#define CHOOSE_CHAIR_SUCCESS 1306
#define CHOOSE_CHAIR_FAIL 2303
#define BOOK_TICKET_SUCCESS 1307
#define BOOK_TICKET_FAIL 2304



void handleRequest(char *type, int connfd, listLoginedAccount *arr, node h, MYSQL *connection, user x){
    if(strcmp(type, "LOGIN") == 0){
        char *username, *password;
        username = (char *)malloc(255 * sizeof(char));
        password = (char *)malloc(255 * sizeof(char));
        getLoginMessage(&username, &password);
        int check = checkLogin(h, username, password, arr);
        if(check == 0){
            sendResult(connfd, LOGIN_FAIL);   
        }else if(check == 1){
            addToListLoginedAccount(arr, username);
            printf("1\n");
            sendResult(connfd, LOGIN_SUCCESS_ADMIN);
        }else if(check == 2){
            addToListLoginedAccount(arr, username);
            sendResult(connfd, LOGIN_SUCCESS_USER);
        }else{
            printf("3\n");
            sendResult(connfd, LOGIN_ALREADY);
        }
    }else if(strcmp(type, "LOGOUT") == 0){

    }else if(strcmp(type, "REGISTER") == 0){

    }else if(strcmp(type, "NEW_FILM") == 0){

    }else if(strcmp(type, "POST") == 0){

    }else if(strcmp(type, "EDIT") == 0){

    }
}