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

/**
 * @function viewRegister: Displays the registration form.
 * 
 * @param name: Full name of the user.
 * @param username: Username for registration.
 * @param password: Password for registration.
 */
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

/**
 * @function viewAdmin: Displays the admin menu of HTV-SPM.
 */
void viewAdmin(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Add new film\n");
    printf("2. Announcing film \n");
    printf("3. Edit announced film\n");
    printf("4. Logout\n\n");
    printf("---------------------------------------------------\n");
}

/**
 * @function viewUser: Displays the user menu of HTV-SPM.
 */
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
 * @function addNewFilm: Adds a new film to the database.
 * 
 * @param sockfd: Socket file descriptor for communication.
 * @param title: Name of the new film.
 * @param category_id: Category of the new film.
 * @param show_time: Show time of the new film.
 * @param description: Description of the new film.
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

/**
 * @function getAnnouncementFilmID: Gets the film ID for announcing a film.
 * 
 * @param film_id: Array to store the film ID.
 */
void getAnnouncementFilmID(char film_id[]) {
    printf("Film ID: ");
    film_id[0] = '\0';
    fgets(film_id, 255, stdin);
}

/**
 * @function getAnnouncementCinemaID: Gets the cinema ID for announcing a film.
 * 
 * @param cinema_id: Array to store the cinema ID.
 */
void getAnnouncementCinemaID(char cinema_id[]){
    printf("Cinema ID: ");
    cinema_id[0] = '\0';
    fgets(cinema_id, 255, stdin);
}

/**
 * @function getAnnouncementPreTimeID: Gets the premiered time ID for announcing a film.
 * 
 * @param premiered_time_id: Array to store the premiered time ID.
 */
void getAnnouncementPreTimeID(char premiered_time_id[]){
    printf("Premiered Time ID: ");
    premiered_time_id[0] = '\0';
    fgets(premiered_time_id, 255, stdin);
}

/**
 * @function getAnnouncementDate: Gets the date components for announcing a film.
 * 
 * @param day: Array to store the day.
 * @param month: Array to store the month.
 * @param year: Array to store the year.
 * @param date: Array to store the complete date.
 */
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

/**
 * @function browseFilm: Displays the menu for browsing films.
 */
void browseFilm(){
    printf("--------------Welcome to HTV-SPM------------------\n\n");
    printf("1. Browse film follow category\n");
    printf("2. Browse film follow theater\n");
    printf("3. Browse film follow show time\n");
    printf("4. Return\n\n");
    printf("---------------------------------------------------\n");
}


/**
 * @function getCategoryID: Gets the category ID for browsing films.
 * 
 * @param category_id: Pointer to store the category ID.
 */
void getCategoryID(char **category_id){
    printf("Choice : ");
    *category_id = (char *)malloc(255 * sizeof(char));
    fgets(*category_id, 255, stdin);
}

/**
 * @function getCinemaID: Gets the cinema ID for browsing films.
 * 
 * @param cinema_id: Pointer to store the cinema ID.
 */
void getCinemaID(char **cinema_id){
    printf("Choice : ");
    *cinema_id = (char *)malloc(255 * sizeof(char));
    fgets(*cinema_id, 255, stdin);
}

/**
 * @function getPremieredTimeID: Gets the premiered time ID for browsing films.
 * 
 * @param premiered_time_id: Pointer to store the premiered time ID.
 */
void getPremieredTimeID (char **premiered_time_id){
    printf("Choice : ");
    *premiered_time_id = (char *)malloc(255 * sizeof(char));
    fgets(*premiered_time_id, 255, stdin);
}

/**
 * @function getTitleFilm: Gets the title of the film.
 * 
 * @param title: Array to store the title.
 */
void getTitleFilm(char title[]){
    printf("Title: ");
    title[0] = '\0';
    fgets(title, 255, stdin);
}

/**
 * @function viewChangePassword: Displays the menu for changing the password.
 * 
 * @param oldPassword: Array to store the old password.
 * @param newPassword: Array to store the new password.
 */
void viewChangePassword(char *oldPassword, char *newPassword) {
    printf("Change Password\n");
    printf("Old Password: ");
    scanf("%s", oldPassword);
    printf("New Password: ");
    scanf("%s", newPassword);
}
