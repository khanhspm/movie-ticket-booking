#include <stdio.h>
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

void makeRegisterMessage(char *name,char *username, char *password, char *message){
    strcpy(message, "REGISTER\r\n");
    strcat(message, name);
    strcat(message, "\r\n");
    strcat(message, username);
    strcat(message, "\r\n");
    strcat(message, password);
    strcat(message, "\r\n");
}

void getRegisterMessage(char **name, char **username, char **password){
    *name = strtok(NULL, "\r\n");
    *username = strtok(NULL, "\r\n");
    *password = strtok(NULL, "\r\n");
}

void makeChangePasswordMessage(char *username, char *oldPassword, char *newPassword, char *message) {
    strcpy(message, "CHANGE_PASSWORD\r\n");
    strcat(message, username);
    strcat(message, "\r\n");
    strcat(message, oldPassword);
    strcat(message, "\r\n");
    strcat(message, newPassword);
    strcat(message, "\r\n");
}

void getChangePasswordMessage(char **username, char **oldPassword, char **newPassword) {
    *username = strtok(NULL, "\r\n");
    *oldPassword = strtok(NULL, "\r\n");
    *newPassword = strtok(NULL, "\r\n");
}

void makeLogoutMessage(char *message){
    strcpy(message, "LOGOUT\r\n");
}

void makeShowCategoryMessage(char *message){
    strcpy(message, "SHOW_CATEGORY\r\n");
}

void makeShowCinemaMessage(char *message){
    strcpy(message, "SHOW_CINEMA\r\n");
}

void makeShowPremieredTimeMessage(char *message){
    strcpy(message, "SHOW_PREMIERED_TIME\r\n");
}

void makeShowPostFilmMessage(char *message){
    strcpy(message, "SHOW_POST_FILM\r\n");
}

void makeAddNewFilmMessage(char *title, char *category_id, char *show_time, char *description ,char *message){
    strcpy(message, "NEW_FILM\r\n"); 
    strcat(message, title);
    strcat(message, "\r\n");
    strcat(message, category_id);
    strcat(message, "\r\n");
    strcat(message, show_time);
    strcat(message, "\r\n");
    strcat(message, description);
    strcat(message, "\r\n");
}

void makeAnnounceFilmMessage(char *film_id, char *cinema_id, char *premiered_time_id, char *date, char *message){
    strcpy(message, "POST_FILM\r\n");
    strcat(message, film_id);
    strcat(message, "\r\n");
    strcat(message, cinema_id);
    strcat(message, "\r\n");
    strcat(message, premiered_time_id);
    strcat(message, "\r\n");
    strcat(message, date);
    strcat(message, "\r\n");
}

void getAddNewFilmMessage(char **title, char **category_id, char **show_time, char **description){
    *title = strtok(NULL, "\r\n");
    *category_id = strtok(NULL, "\r\n");
    *show_time = strtok(NULL, "\r\n");
    *description = strtok(NULL, "\r\n");
}

void getAnnounceFilmMessage(char **film_id, char **cinema_id, char **premiered_time_id, char **date){
    *film_id = strtok(NULL, "\r\n");
    *cinema_id = strtok(NULL, "\r\n");
    *premiered_time_id = strtok(NULL, "\r\n");
    *date = strtok(NULL, "\r\n");
}

void makeSearchFilmByTitleMessage(char *title, char *message){
    strcpy(message, "TITLE\r\n");
    strcat(message, title);
    strcat(message, "\r\n");
}

void getSearchFilmByTitleMessage(char **title){
    *title = strtok(NULL, "\r\n");
}

void makeBrowseFollowCategoryMessage(char *category_id, char *message){
    strcpy(message, "BROWSE_CATEGORY\r\n");
    strcat(message, category_id);
    strcat(message, "\r\n");
}

void makeBrowseFollowCinemaMessage(char *cinema_id, char *message){
    strcpy(message, "BROWSE_CINEMA\r\n");
    strcat(message, cinema_id);
    strcat(message, "\r\n");
}

void makeBrowseFollowPremieredTimeMessage(char *premiered_time_id, char *message){
    strcpy(message, "BROWSE_PREMIERED_TIME\r\n");
    strcat(message, premiered_time_id);
    strcat(message, "\r\n");
}

void getCategoryIDMessage(char **category_id){
    *category_id = strtok(NULL, "\r\n");
}

void getCinemaIDMessage(char **cinema_id){
    *cinema_id = strtok(NULL, "\r\n");
}

void getPremieredTimeIDMessage(char **premiered_time_id){
    *premiered_time_id = strtok(NULL, "\r\n");
}