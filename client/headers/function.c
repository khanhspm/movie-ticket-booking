#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"
#include "menu.h"

void clearKeyboardBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

void handleLogout(int sockfd);
void handleSearchByTitle(int sockfd, char *title, char *message);
void handleRequestUser(int sockfd, char *username, char *password, char *message, int *login_status);
void handleRequestAdmin(int sockfd, char *username, char *password, char *message, int *login_status);
void handleChangePassword(int sockfd, char *username, char *message);
void handleBrowseFilm(int sockfd);

void handleLogin(int sockfd, char *username, char *password, char *message, int *login_status){
    viewLogin(username, password);
    makeLoginMessage(username, password, message);
    sendMessage(sockfd, message);
    *login_status = recvResult(sockfd);
    if(*login_status == LOGIN_FAIL){
        printf("%s\n", LOGIN_FAIL_MESSAGE);
    }else if(*login_status == LOGIN_ALREADY){
        printf("%s\n", LOGIN_ALREADY_MESSAGE);
    }else{
        printf("%s\n", LOGIN_SUCCESS_MESSAGE);
    }
}

void handleRequestUser(int sockfd, char *username, char *password, char *message, int *login_status){
    int user_choice;
    do{
        viewUser();
        printf("Choice: ");
        scanf("%d", &user_choice);
        clearKeyboardBuffer();
        switch(user_choice) {
            case 1:{
                handleBrowseFilm(sockfd);
                break;
            }
            case 2:{
                char *title;
                handleSearchByTitle(sockfd, title, message);
                break;
            }
            case 3:{
                //handleBookTicket();
                break;
            }
            case 4:{
                handleLogout(sockfd);
                user_choice = 0;
                break;
            }
            case 5:{
                printf("%s\n", username);
                handleChangePassword(sockfd, username, message);
                break;
            }
        }
    }while(user_choice != 0);
}

void handleRequestAdmin(int sockfd, char *username, char *password, char *message, int *login_status){
    int admin_choice;
    do{
        viewAdmin();
        printf("Choice: ");
        scanf("%d", &admin_choice);
        clearKeyboardBuffer();
        switch(admin_choice) {
            case 1:{
                //handleAddNewFilm();
                break;
            }
            case 2:{
                //handleAnnouncingFilm();
                break;
            }
            case 3:{
                //handleEditAnnouncedFilm();
                break;
            }
            case 4: {
                handleLogout(sockfd);
                admin_choice = 0;
                break;
            }
        }
    } while(admin_choice != 0);
}

void handleLogout(int sockfd){
    char *message;
    message = (char *)malloc(255 * sizeof(char));
    makeLogoutMessage(message);
    sendMessage(sockfd, message);
    int result = recvResult(sockfd);
    printf("%d\n", result);
    printf(LOGOUT_SUCCESS_MESSAGE);
}

void handleChangePassword(int sockfd, char *username, char *message){
    char *oldPassword, *newPassword;
    oldPassword = (char *)malloc(255 * sizeof(char));
    newPassword = (char *)malloc(255 * sizeof(char));
    viewChangePassword(oldPassword, newPassword);
    makeChangePasswordMessage(username, oldPassword, newPassword, message);
    sendMessage(sockfd, message);

    int result = recvResult(sockfd);
    printf("%d\n", result);
    if (result == CHANGE_PASSWORD_SUCCESS) {
        printf(CHANGE_PASSWORD_SUCCESS_MESSAGE);
    } else {
        printf(CHANGE_PASSWORD_FAIL_MESSAGE);
    }

    free(oldPassword);
    free(newPassword);

}

void handleRegister(int sockfd){
    char *newName, *newUsername, *newPassword, *message;
    newName = (char *)malloc(255 * sizeof(char));
    newUsername = (char *)malloc(255 * sizeof(char));
    newPassword = (char *)malloc(255 * sizeof(char));
    message = (char *)malloc(255 * sizeof(char));

    viewRegister(newName, newUsername, newPassword);
    makeRegisterMessage(newName, newUsername, newPassword, message);
    sendMessage(sockfd, message);

    int result = recvResult(sockfd);
    if (result == REGISTER_SUCCESS) {
        printf(REGISTER_SUCCESS_MESSAGE);
    } else {
        printf(REGISTER_FAIL_MESSAGE);
    }

    free(newName);
    free(newUsername);
    free(newPassword);
    free(message);
}

void handleSearchByTitle(int sockfd, char *title, char *message){
    title = (char *)malloc(255 * sizeof(char));
    message = (char *)malloc(255 * sizeof(char));
    getTitleFilm(title);
    makeSearchFilmByTitleMessage(title, message);
    printf("%s\n", message);
    sendMessage(sockfd, message);

    int result = recvResult(sockfd);
    if(result == FIND_FILM_SUCCESS){
        printf("%s\n", FIND_FILM_SUCCESS_MESSAGE);
        message = (char *)malloc(255 * sizeof(char));
        recvMessage(sockfd, message);
        printf("%s\n", message);
    }else if(result == FIND_FILM_FAIL){
        printf("%s\n", FIND_FILM_FAIL_MESSAGE);
    }
}

void handleBrowseFilm(int sockfd){
    int browse_choose;
    do{
        browseFilm();
        printf("Choice: ");
        scanf("%d", &browse_choose);
        clearKeyboardBuffer();
        switch(browse_choose){
            case 1:{
                //handleBrowseFollowCategory();
                break;
            }
            case 2:{
                //handleBrowseFollowCinema();
                break;
            }
            case 3:{
                //handleBrowseFollowShowTime();
                break;
            }
            case 4:{
                browse_choose = 0;
                break;
            }
        }
    }while(browse_choose != 0);
}