#include <string.h>

char* getTypeMessage(char *message){
    return strtok(message, "\r\n");
}

void makeLoginMessage(char *username, char *password, char *message){
    strcpy(message, "LOGIN\r\n");
    strcat(message, username);
    strcat(message, "\r\n");
    strcat(message, password);
    strcat(message, "\r\n");
}

void getLoginMessage(char **username, char **password){
    *username = strtok(NULL, "\r\n");
    *password = strtok(NULL, "\r\n");
}

void makeRegisterMessage(char *username, char *password, char *message){
    strcpy(message, "REGISTER\r\n");
    strcat(message, username);
    strcat(message, "\r\n");
    strcat(message, password);
    strcat(message, "\r\n");
}

void getRegisterMessage(char **username, char **password){
    *username = strtok(NULL, "\r\n");
    *password = strtok(NULL, "\r\n");
}

void makeLogoutMessage(char *message){
    strcpy(message, "LOGOUT\r\n");
}

void makeAddNewFilmMessage(char *title, char *category, char *show_time, char *message){
    strcpy(message, "NEW_FILM\r\n"); 
    strcat(message, title);
    strcat(message, "\r\n");
    strcat(message, category);
    strcat(message, "\r\n");
    strcat(message, show_time);
    strcat(message, "\r\n");
}

void getAddNewFilmMessage(char **title, char **category, char **show_time){
    *title = strtok(NULL, "\r\n");
    *category = strtok(NULL, "\r\n");
    *show_time = strtok(NULL, "\r\n");
}

void makeSearchFilmByTitleMessage(char *title, char *message){
    strcpy(message, "TITLE\r\n");
    strcat(message, title);
    strcat(message, "\r\n");
}

void getSearchFilmByTitleMessage(char **title){
    *title = strtok(NULL, "\r\n");
}