#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"
#include "queryUser.h"
#include "queryFilm.h"
#include "queryCategory.h"
#include "function.h"
#include "queryCinema.h"
#include "queryPremieredTime.h"
#include "queryPremieredTimeFilm.h"

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

/**
 * @function handleRequest: handle request from client
 * 
 * @param conn : connection to connect to mysql
 * @param type : type of request
 * @param connfd : the socket to connect
 * @param username : username of client
 * @param password : password of client
 * @param arr : array of logined account
 * @param h : node of list user
 * @param f : node of list film
 * @param c : node of list category
 * @param ci : node of list cinema
 * @param pt : node of list premiere time
 * @param ptf : node of list premiere time film
 */
void handleRequest(MYSQL *conn, char *type, int connfd, char **username, char *password, listLoginedAccount *arr, node h, nodeFilm f, nodeCategory c, nodeCinema ci, nodePremieredTime pt, nodePremieredTimeFilm ptf){
    if(strcmp(type, "LOGIN") == 0){
        handleLogin(connfd, arr, h, username, password);
        printf("username: %s\n", *username);
    }else if(strcmp(type, "LOGOUT") == 0){
        printf("username: %s\n", *username);
        handleLogout(connfd, arr, username);
    }else if (strcmp(type, "REGISTER") == 0)
    {
        handleRegister(conn, connfd, &h);
    }else if (strcmp(type, "SHOW_CATEGORY") == 0)
    {
        sendMessage(connfd, displayCategory(c));
    }
    else if (strcmp(type, "SHOW_CINEMA") == 0)
    {
        sendMessage(connfd,displayCinema(ci));
    }
    else if (strcmp(type, "SHOW_PREMIERED_TIME") == 0)
    {
        sendMessage(connfd,displayPremieredTime(pt));
    }
    else if(strcmp(type, "SHOW_POST_FILM") == 0){
        sendMessage(connfd, displayFilm(f));
        sendMessage(connfd, displayCinema(ci));
        sendMessage(connfd, displayPremieredTime(pt));
    }
    else if (strcmp(type, "NEW_FILM") == 0)
    {
        handleAddNewFilm(conn, connfd, f, c);
    }
    else if (strcmp(type, "BROWSE_CATEGORY") == 0){
        handleBrowseFollowCategory(connfd, f, c);
    }
    else if (strcmp(type,"BROWSE_CINEMA") == 0)
    {
        handleBrowseFollowCinema(connfd, f, ci, ptf);
    }
    else if (strcmp(type, "BROWSE_PREMIERED_TIME") == 0){
        handleBrowseFollowPremieredTime(connfd, f, pt, ptf);
    }
    else if (strcmp(type, "POST_FILM") == 0)
    {
        handleAnnouncingFilm(conn, connfd, f, ci, pt, ptf);
    }
    else if (strcmp(type, "EDIT") == 0)
    {
    }
    else if (strcmp(type, "TITLE") == 0)
    {
        handleSearchFilm(connfd, f, c);
    }
    else if (strcmp(type, "CHANGE_PASSWORD") == 0)
    {
        handleChangePassword(connfd, conn, &h);
    }
}

/**
 * @function hanldeLogin: handle request login from user
 * 
 * @param connfd : the socket to connect
 * @param arr : array of logined account
 * @param h : node of list user
 * @param username : username of client
 * @param password : password of client
 */
void handleLogin(int connfd, listLoginedAccount *arr, node h, char **username, char *password){
    getLoginMessage(username, &password);
    int check = checkLogin(h, username, password, arr);
    if(check == 0){
        sendResult(connfd, LOGIN_FAIL);   
    }else if(check == 1){
        addToListLoginedAccount(arr, username);
        sendResult(connfd, LOGIN_SUCCESS_ADMIN);
    }else if(check == 2){
        addToListLoginedAccount(arr, username);
        sendResult(connfd, LOGIN_SUCCESS_USER);
    }else{
        sendResult(connfd, LOGIN_ALREADY);
    }
}

/**
 * @function handleLogout: handle logout request from user
 * 
 * @param connfd : the socket to connect
 * @param arr : array of logined account
 * @param username : username of client
 */
void handleLogout(int connfd, listLoginedAccount *arr, char **username){
    deleteFromListLoginedAccount(arr, username);
    sendResult(connfd, LOGOUT_SUCCESS);
}

/**
 * @function handleRegister: handle register request from user
 * 
 * @param conn : connection to mysql
 * @param connfd : the socket to connect
 * @param h : node of list user
 */
void handleRegister(MYSQL *conn, int connfd, node *h){
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

    addNode(h, newUser); // Thêm vào danh sách liên kết

    // Gọi hàm đăng ký và xử lý kết quả
    int result = registerUser(conn, newUser);
    if (result == 1)
    {
        sendResult(connfd, REGISTER_SUCCESS);
    }
    else
    {
        sendResult(connfd, REGISTER_FAIL);
    }
}

/**
 * @function handleChangePassword: handle change password request from user
 * 
 * @param connfd : the socket to connect
 * @param conn : connection to mysql
 * @param h : node of list user
 */
void handleChangePassword(int connfd, MYSQL *conn, node *h){
    char *username, *oldPassword, *newPassword;
    username = (char *)malloc(255 * sizeof(char));
    oldPassword = (char *)malloc(255 * sizeof(char));
    newPassword = (char *)malloc(255 * sizeof(char));
    getChangePasswordMessage(&username, &oldPassword, &newPassword); // Hàm này cần được viết để phân tích tin nhắn

    int result = changePassword(conn, username, oldPassword, newPassword);
    printf("%d\n", result);
    if (result == 1)
    {
        changeNodePassword(h, username, newPassword);
        sendResult(connfd, CHANGE_PASSWORD_SUCCESS);
    }
    else
    {
        sendResult(connfd, CHANGE_PASSWORD_FAIL);
    }
}

/**
 * @function handleSearchFilm: handle search film request follow title 
 * 
 * @param connfd : the socket to connect
 * @param f : node of list film
 * @param c : node of list categories
 */
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
    }
}

/**
 * @function handleAddNewFilm: handle add new film request from admin
 * 
 * @param conn : connection to mysql
 * @param connfd : the socket to connect
 * @param f : node of list film
 * @param c : node of list categories
 */
void handleAddNewFilm(MYSQL *conn, int connfd, nodeFilm f, nodeCategory c)
{   
    displayCategory(c);

    char *title, *category_id, *show_time, *description;
    title = (char *)malloc(255 * sizeof(char));
    category_id = (char *)malloc(255 * sizeof(char));
    show_time = (char *)malloc(255 * sizeof(char));
    description = (char *)malloc(2048 * sizeof(char));
    getAddNewFilmMessage(&title, &category_id, &show_time, &description);

    nodeFilm addf = NULL;
    int seru = searchTitle(f, title, &addf);
    if (addf != NULL || seru > 0)
    {
        sendResult(connfd, ADD_FILM_FAIL);
    }
    else
    {
        film newFilm;

        strcpy(newFilm.title, title);
        newFilm.category_id = atol(category_id);
        newFilm.show_time = atol(show_time);
        strcpy(newFilm.description, description);

        addFilm(conn, newFilm);

        addNodeFilm(&f, newFilm);

        sendResult(connfd, ADD_FILM_SUCCESS);
    }
}

/**
 * @function handleAnnouncingFilm: handle the announcement of film request
 * 
 * @param conn : connection to mysql
 * @param connfd : the socket to connect
 * @param f : node of list film
 * @param ci : node of list cinema
 * @param pt : node of list premiered time
 * @param ptf : node of list premiered time film
 */
void handleAnnouncingFilm(MYSQL *conn, int connfd, nodeFilm f, nodeCinema ci, nodePremieredTime pt, nodePremieredTimeFilm ptf)
{   
    char *film_id, *cinema_id, *premiered_time_id, *date;
    film_id = (char *)malloc(255 * sizeof(char));
    cinema_id = (char *)malloc(255 * sizeof(char));
    premiered_time_id = (char *)malloc(255 * sizeof(char));
    date = (char *)malloc(255 * sizeof(char));
    getAnnounceFilmMessage(&film_id, &cinema_id, &premiered_time_id, &date);
    printf("%s\n", date);

    unsigned long film_id_search = strtoul(film_id, NULL, 10);
    unsigned long cinema_id_search = strtoul(cinema_id, NULL, 10);
    unsigned long premiered_time_search = strtoul(premiered_time_id, NULL, 10);

    int seru = searchPremieredTimeFilmToPost(ptf, film_id_search, cinema_id_search, premiered_time_search, date);
    if (seru != 0)
    {
        sendResult(connfd, POST_FILM_FAIL);
    }
    else
    {
        premieredTimeFilm newPremieredTimeFilm;

        newPremieredTimeFilm.film_id = film_id_search;
        newPremieredTimeFilm.cinema_id = cinema_id_search;
        newPremieredTimeFilm.premiered_time_id = premiered_time_search;
        strcpy(newPremieredTimeFilm.date, date);

        addNodePremieredTimeFilm(&ptf, newPremieredTimeFilm);

        addPremieredTimeFilm(conn, newPremieredTimeFilm);

        sendResult(connfd, POST_FILM_SUCCESS);
    }
}

/**
 * @function handleBrowseFollowCategory: handle the browse film follows category request
 * 
 * @param connfd : the socket to connect
 * @param f : node of list film
 * @param c : node of list category
 */
void handleBrowseFollowCategory(int connfd, nodeFilm f, nodeCategory c){
    //chuyen kieu char ve unsigned long
    char *category_id;
    category_id = (char *)malloc(255 * sizeof(char));
    getCategoryIDMessage(&category_id);
    printf("%s\n", category_id);

    unsigned long category_id_search;
    category_id_search = strtoul(category_id, NULL, 10);
    printf("%ld\n", category_id_search);

    char *message;
    message = (char *)malloc(20480 * sizeof(char));
    strcpy(message, searchFilmFollowCategoryID(f , category_id_search));

    if (strcmp(message,"No data!\n") == 0){
        sendResult(connfd, BROWSE_FAIL);
    }else{
        sendResult(connfd, BROWSE_CATEGORY_SUCCESS);
        sendMessage(connfd, message);
        free(message);
    }


}

/**
 * @function handleBrowseFollowCinema: handle browse film follow cinema request
 * 
 * @param connfd : the socket to connect
 * @param f : node of list film
 * @param c : node of list category
 * @param ptf : node of list premiered time film
 */
void handleBrowseFollowCinema(int connfd, nodeFilm f, nodeCinema c, nodePremieredTimeFilm ptf){
    //chuyen kieu char ve unsigned long
    char *cinema_id;
    cinema_id = (char *)malloc(255 * sizeof(char));
    getCinemaIDMessage(&cinema_id);
    printf("%s\n", cinema_id);

    unsigned long cinema_id_search;
    cinema_id_search = strtoul(cinema_id, NULL, 10);
    printf("%ld\n", cinema_id_search);

    int* arr = (int*)malloc(sizeof(int));
    arr = searchPremieredTimeFilm(ptf, cinema_id_search);
    if(arr == NULL){
        sendResult(connfd, BROWSE_FAIL);
    }else{
        char *message;
        message = (char *)malloc(20480 * sizeof(char));
        for(int y = 0; y < sizeof(arr); y++){
            strcat(message, searchFilmFollowID(f , arr[y]));
        }

        printf("new %s\n", message);

        sendResult(connfd, BROWSE_THEATER_SUCCESS);
        sendMessage(connfd, message);
        free(message);
    }

}

/**
 * @function handleBrowseFollowPremieredTime: handle browse film follow time request
 * 
 * @param connfd : the socket to connect
 * @param f : node of list film
 * @param pt : node of list premiered time
 * @param ptf : node of list premiered time film
 */
void handleBrowseFollowPremieredTime(int connfd, nodeFilm f, nodePremieredTime pt, nodePremieredTimeFilm ptf){
    //chuyen kieu char ve unsigned long
    char *premiered_time_id;
    premiered_time_id = (char *)malloc(255 * sizeof(char));
    getPremieredTimeIDMessage(&premiered_time_id);
    printf("%s\n", premiered_time_id);

    unsigned long premiered_time_id_search;
    premiered_time_id_search = strtoul(premiered_time_id, NULL, 10);
    printf("%ld\n", premiered_time_id_search);

    int* arr = (int*)malloc(sizeof(int));
    arr = searchPremieredTimeFilm(ptf, premiered_time_id_search);
    if(arr == NULL){
        sendResult(connfd, BROWSE_FAIL);
    }else{
        char *message;
        message = (char *)malloc(20480 * sizeof(char));
        for(int y = 0; y < sizeof(arr); y++){
            strcat(message, searchFilmFollowID(f , arr[y]));
        }

        printf("new %s\n", message);

        sendResult(connfd, BROWSE_TIME_SUCCESS);
        sendMessage(connfd, message);
        free(message);
    }
}