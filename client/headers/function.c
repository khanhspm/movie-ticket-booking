#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"
#include "menu.h"

void clearKeyboardBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Đọc và loại bỏ các ký tự còn lại trong bộ đệm bàn phím
    }
}

void handleSearchByTitle(int sockfd, char *title, char *message);
void handleRequestUser(int sockfd, char *username, char *password, char *message, int *login_status);
void handleRequestAdmin(int sockfd, char *username, char *password, char *message, int *login_status);
void handleChangePassword(int sockfd, char *username, char *message);

void handleLogin(int sockfd, char *username, char *password, char *message, int *login_status){
    viewLogin(username, password);
    makeLoginMessage(username, password, message);
    sendMessage(sockfd, message);
    *login_status = recvResult(sockfd);
}

void handleSearchByTitle(int sockfd, char *title, char *message){
    title = (char *)malloc(255 * sizeof(char));
    free(message);
    message = (char *)malloc(255 * sizeof(char));
    getTitleFilm(title);
    makeSearchFilmByTitleMessage(title, message);
    printf("%s\n", message);
    sendMessage(sockfd, message);
}

void handleRequestUser(int sockfd, char *username, char *password, char *message, int *login_status){
    int user_choice;
    do{
        viewUser();
        printf("Choice: ");
        scanf("%d", &user_choice);
        clearKeyboardBuffer();
        switch(user_choice) {
            case 2:{
                char *title;
                handleSearchByTitle(sockfd, title, message);
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
            case 4: {
                // admin_choice = handleLogout(sockfd, message);
                // printf("%d\n", admin_choice);
                break;
            }
        }
    } while(admin_choice != 0);
}

void handleChangePassword(int sockfd, char *username, char *message){
    char *oldPassword, *newPassword;
    oldPassword = (char *)malloc(255 * sizeof(char));
    newPassword = (char *)malloc(255 * sizeof(char));
    viewChangePassword(oldPassword, newPassword);
    makeChangePasswordMessage(username, oldPassword, newPassword, message);
    sendMessage(sockfd, message);
    printf("%s\n", message);

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