#ifndef MENU_H
#define MENU_H

#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"

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

#define LOGIN_SUCCESS_MESSAGE "You have logged in successfully!!\n"
#define LOGIN_FAIL_MESSAGE "Your username or password is incorrect!!\n"
#define LOGIN_ALREADY_MESSAGE "Your account is being used in another address!!\n"
#define REGISTER_SUCCESS_MESSAGE "You have registered successfully!!\n"
#define REGISTER_FAIL_MESSAGE "Username has been existed!!\n"
#define LOGOUT_SUCCESS_MESSAGE "You have been successfully logged out!!\n"
#define ADD_FILM_SUCCESS_MESSAGE "Add new film successfully!!\n"
#define ADD_FILM_FAIL_MESSAGE "The title of the film has already been exist!!\n"
#define POST_FILM_SUCCESS_MESSAGE "Post new film successfully!!\n"
#define POST_FILM_FAIL_MESSAGE "The time to show the film has already been exist!!\n"
#define EDIT_FILM_SUCCESS_MESSAGE "Edit information of the film successfully!!\n"
#define EDIT_FILM_FAIL_MESSAGE "Edit fail because the show time of the film has already been exist!!\n"
#define NO_EDIT_FILM_MESSAGE "Edit fail because no information change!!\n"
#define BROWSE_CATEGORY_SUCCESS_MESSAGE "Browse follow category successfully!!\n"
#define BROWSE_THEATER_SUCCESS_MESSAGE "Browse follow theater successfully!!\n"
#define BROWSE_TIME_SUCCESS_MESSAGE "Browse follow time "
#define BROWSE_FAIL_MESSAGE "No film has been found!!\n"
#define FIND_FILM_SUCCESS_MESSAGE "The information of the film you need search:\n"
#define FIND_FILM_FAIL_MESSAGE "No film has been found!!\n"
#define VIEW_CHAIR_SUCCESS_MESSAGE "MAP CHAIR\n"
#define VIEW_CHAIR_FAIL_MESSAGE "Has not empty chair in map\n"
#define CHOOSE_CHAIR_SUCCESS_MESSAGE "Choose seat successfully!!\n"
#define CHOOSE_CHAIR_FAIL_MESSAGE "This chair is not empty chair. Please choose again!!\n"
#define BOOK_TICKET_SUCCESS_MESSAGE "Booking ticket successfully!!\n"
#define BOOK_TICKET_FAIL_MESSAGE "Booking ticket failed!!\n"
#define INVALID_MESSAGE_MESSAGE "The request is invalid!!\n"
#define CHANGE_PASSWORD_SUCCESS_MESSAGE "Changed password successfully\n"
#define CHANGE_PASSWORD_FAIL_MESSAGE "Changed password fail!!\n" 

void viewWelcome();
void viewLogin(char username[], char password[]);
void viewRegister(char *name, char *username, char *password);
void viewAdmin();
void viewUser();
void addNewFilm(int sockfd, char title[], char category_id[], char show_time[], char description[]);
void browseFilm();
void getTitleFilm(char title[]);
void viewChangePassword(char *oldPassword, char *newPassword);

void getCategoryID(char **category_id);
void getCinemaID(char **cinema_id);

void getPremieredTimeID (char **premiered_time_id);

void getAnnouncementFilmID(char film_id[]);
void getAnnouncementCinemaID(char cinema_id[]);
void getAnnouncementPreTimeID(char premiered_time_id[]);
void getAnnouncementDate(char day[], char month[], char year[], char date[]);

#endif