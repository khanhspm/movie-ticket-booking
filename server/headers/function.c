#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"
#include "queryUser.h"
#include "queryFilm.h"
#include "queryCategory.h"
#include "function.h"

#define LOGIN_SUCCESS_USER 1010
#define LOGIN_SUCCESS_ADMIN 1011
#define LOGIN_FAIL 2011
#define LOGIN_ALREADY 2012
#define LOGOUT_SUCCESS 1030
#define REGISTER_SUCCESS 1020
#define REGISTER_FAIL 2021
#define ADD_FILM_SUCCESS 1040
#define ADD_FILM_FAIL 2041
#define POST_FILM_SUCCESS 1050
#define POST_FILM_FAIL 2051
#define EDIT_FILM_SUCCESS 1060
#define EDIT_FILM_FAIL 2061
#define NO_EDIT_FILM 2062
#define BROWSE_CATEGORY_SUCCESS 1070
#define BROWSE_THEATER_SUCCESS 1071
#define BROWSE_TIME_SUCCESS 1072
#define BROWSE_FAIL 2071
#define FIND_FILM_SUCCESS 1073
#define FIND_FILM_FAIL 2072
#define VIEW_CHAIR_SUCCESS 1080
#define VIEW_CHAIR_FAIL 2081
#define CHOOSE_CHAIR_SUCCESS 1090
#define CHOOSE_CHAIR_FAIL 2091
#define BOOK_TICKET_SUCCESS 1100
#define BOOK_TICKET_FAIL 2101
#define CHANGE_PASSWORD_SUCCESS 1110
#define CHANGE_PASSWORD_FAIL 2110

void handleRequest(MYSQL *conn, char *type, int connfd, listLoginedAccount arr, node h, nodeFilm f, nodeCategory c){
    char *username, *password;
    if(strcmp(type, "LOGIN") == 0){
        username = (char *)malloc(255 * sizeof(char));
        password = (char *)malloc(255 * sizeof(char));
        handleLogin(connfd, arr, h, username, password);
    }else if(strcmp(type, "LOGOUT") == 0){
        handleLogout(connfd, arr, username, password);
    }else if(strcmp(type, "REGISTER") == 0){
        handleRegister(conn, connfd);
    }else if(strcmp(type, "NEW_FILM") == 0){

    }else if(strcmp(type, "POST") == 0){

    }else if(strcmp(type, "EDIT") == 0){

    }else if(strcmp(type, "TITLE") == 0){
        handleSearchFilm(connfd, f, c);
    }else if (strcmp(type, "CHANGE_PASSWORD") == 0){
        handleChangePassword(connfd, conn);
    }
}

void handleLogin(int connfd, listLoginedAccount arr, node h, char *username, char *password){
    getLoginMessage(&username, &password);
    int check = checkLogin(h, username, password, arr);
    printf("%d\n", check);
    if(check == 0){
        sendResult(connfd, LOGIN_FAIL);   
    }else if(check == 1){
        addToListLoginedAccount(&arr, username);
        sendResult(connfd, LOGIN_SUCCESS_ADMIN);
    }else if(check == 2){
        addToListLoginedAccount(&arr, username);
        sendResult(connfd, LOGIN_SUCCESS_USER);
    }else{
        sendResult(connfd, LOGIN_ALREADY);
    }
}

void handleLogout(int connfd, listLoginedAccount arr, char *username, char *password){
    deleteFromListLoginedAccount(&arr, username);
    free(username);
    free(password);
    username = NULL;
    password = NULL;
    sendResult(connfd, LOGOUT_SUCCESS);
}

void handleRegister(MYSQL *conn, int connfd){
    char *name, *username, *password;
    name = (char *)malloc(255 * sizeof(char));
    username = (char *)malloc(255 * sizeof(char));
    password = (char *)malloc(255 * sizeof(char));
    getRegisterMessage(&name, &username, &password);

    // Thiết lập newUser
    user newUser;
    strcpy(newUser.name, name);
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    newUser.role_id = 2; // Mặc định là user

    // Gọi hàm đăng ký và xử lý kết quả
    int result = registerUser(conn, newUser);
    printf("KQ %d",result);
    if (result == 1){
        sendResult(connfd, REGISTER_SUCCESS);
    }else{
        sendResult(connfd, REGISTER_FAIL);
    }
}

void handleChangePassword(int connfd, MYSQL *conn){
    char *username, *oldPassword, *newPassword;
    username = (char *)malloc(255 * sizeof(char));
    oldPassword = (char *)malloc(255 * sizeof(char));
    newPassword = (char *)malloc(255 * sizeof(char));
    getChangePasswordMessage(&username, &oldPassword, &newPassword); // Hàm này cần được viết để phân tích tin nhắn

    int result = changePassword(conn, username, oldPassword, newPassword);
    printf("%d\n", result);
    if (result == 1){
        sendResult(connfd, CHANGE_PASSWORD_SUCCESS);
    }
    else{
        sendResult(connfd, CHANGE_PASSWORD_FAIL);
    }
}

void handleSearchFilm(int connfd, nodeFilm f, nodeCategory c){
    char *title;
    title = (char *)malloc(255 * sizeof(char));
    getSearchFilmByTitleMessage(&title);
    nodeFilm addf = NULL;
    int seru = searchTitle(f, title, &addf);
    if(addf == NULL || seru <= 0){
        sendResult(connfd, FIND_FILM_FAIL);
    }else{
        sendResult(connfd,FIND_FILM_SUCCESS);
        int a = 0;
        char *message = (char *)malloc(20480 * sizeof(char));
        while(addf != NULL){
            a++;
            sprintf(message, "STT: %d\n", a);
            sprintf(message + strlen(message), "Title: %s\n", addf->data.title);
            sprintf(message + strlen(message), "Category: %s\n", getCategory(addf->data.category_id, c));
            sprintf(message + strlen(message), "Show time: %ld\n", addf->data.show_time);
            sprintf(message + strlen(message), "Description: %s\n", addf->data.description);
            addf = addf->next;
        }
        sendMessage(connfd, message);
        free(message);
    }
}