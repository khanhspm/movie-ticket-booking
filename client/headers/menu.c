#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"

void viewWelcome(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Login to HTV-SPM\n");
    printf("2. Register for HTV-SPM\n");
    printf("3. Exit HTV-SPM\n\n");
    printf("---------------------------------------------------\n");
}

/**
 * @function viewLogin: view the login information
 * 
 * @param username : the username to login
 * @param password : the password to login
 */
void viewLogin(char username[], char password[]){
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
}

void viewRegister(char *name, char *username, char *password) {
    printf("Registration\n");
    printf("Full Name: ");
    memset(name, 0, 255);
    fgets(name, 255, stdin);    // lay ca dau cach
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
}

void viewAdmin(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Add new film\n");
    printf("2. Announcing film \n");
    printf("3. Edit announced film\n");
    printf("4. Logout\n\n");
    printf("---------------------------------------------------\n");
}

void viewUser(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Browse film catalogs\n");
    printf("2. Search film \n");
    printf("3. Book ticket\n");
    printf("4. Logout\n");
    printf("5. Change Password\n");
    printf("---------------------------------------------------\n");
}

/**
 * @function addNewFilm: add new film to database
 * 
 * @param title : name of new film
 * @param category : category of new film
 * @param show_time : show time of new film
 */
void addNewFilm(int sockfd, char title[], char category_id[], char show_time[], char description[]){
    printf("Title: ");
    title[0] = '\0';
    fgets(title, 255, stdin);

    char *message = (char *)malloc(255 * sizeof(char));
    makeShowCategoryMessage(message);
    sendMessage(sockfd, message);
    recvMessage(sockfd, message);

    printf("Category: \n");
    printf("%s\n", message);
    printf("Choice: ");
    category_id[0] = '\0';
    fgets(category_id, 255, stdin);


    printf("Show time: ");
    show_time[0] = '\0';
    fgets(show_time, 255, stdin);    
    
    printf("Description: ");
    description[0] = '\0';
    fgets(description, 2048, stdin);
    
}

void getAnnouncementFilmID(char film_id[]) {
    printf("Film ID: ");
    film_id[0] = '\0';
    fgets(film_id, 255, stdin);
}

void getAnnouncementCinemaID(char cinema_id[]){
    printf("Cinema ID: ");
    cinema_id[0] = '\0';
    fgets(cinema_id, 255, stdin);
}

void getAnnouncementPreTimeID(char premiered_time_id[]){
    printf("Premiered Time ID: ");
    premiered_time_id[0] = '\0';
    fgets(premiered_time_id, 255, stdin);
}

void getAnnouncementDate(char day[], char month[], char year[], char date[]){
    day[0] = '\0';
    month[0] = '\0';
    year[0] = '\0';
    date[0] = '\0';
    printf("Day: ");
    fgets(day, 255, stdin);
    day[strcspn(day, "\n")] = '\0';
    strcpy(date, day);
    strcat(date, "/");
    printf("Month: ");
    fgets(month, 255, stdin);
    month[strcspn(month, "\n")] = '\0';
    strcat(date, month);
    strcat(date, "/");
    printf("Year: ");
    fgets(year, 255, stdin);
    year[strcspn(year, "\n")] = '\0';
    strcat(date, year);
}

void browseFilm(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Browse film follow category\n");
    printf("2. Browse film follow theater\n");
    printf("3. Browse film follow show time\n");
    printf("4. Return\n\n");
    printf("---------------------------------------------------\n");
}

void viewEditPremieredTimeFilm(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Edit film  \n");
    printf("2. Edit cinema \n");
    printf("3. Edit premiered time \n");
    printf("4. Edit date \n");
    printf("5. Return\n\n");
    printf("---------------------------------------------------\n");
}

// Begin duyet phim
void getCategoryID(char **category_id){
    printf("Choice : ");
    *category_id = (char *)malloc(255 * sizeof(char));
    fgets(*category_id, 255, stdin);
}

void getCinemaID(char **cinema_id){
    printf("Choice : ");
    *cinema_id = (char *)malloc(255 * sizeof(char));
    fgets(*cinema_id, 255, stdin);
}

void getPremieredTimeID (char **premiered_time_id){
    printf("Choice : ");
    *premiered_time_id = (char *)malloc(255 * sizeof(char));
    fgets(*premiered_time_id, 255, stdin);
}

//end duyet phim

void getTitleFilm(char title[]){
    printf("Title: ");
    title[0] = '\0';
    fgets(title, 255, stdin);
}

void viewChangePassword(char *oldPassword, char *newPassword) {
    printf("Change Password\n");
    printf("Old Password: ");
    scanf("%s", oldPassword);
    printf("New Password: ");
    scanf("%s", newPassword);
}
