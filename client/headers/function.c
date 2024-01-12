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
void handleAddNewFilm(int sockfd);
void handleAnnouncingFilm(int sockfd);

/**
 * @function handleLogin: Handles the login process.
 * 
 * @param sockfd: Socket file descriptor for communication.
 * @param username: User-entered username.
 * @param password: User-entered password.
 * @param message: Message buffer for communication.
 * @param login_status: Pointer to the variable storing login status.
 */
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

/**
 * @function handleRequestUser: Handles user requests after successful login.
 * 
 * @param sockfd: Socket file descriptor for communication.
 * @param username: User-entered username.
 * @param password: User-entered password.
 * @param message: Message buffer for communication.
 * @param login_status: Pointer to the variable storing login status.
 */
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

/**
 * @function handleRequestAdmin: Handles the request and actions for an admin user.
 * 
 * @param sockfd: Socket file descriptor for communication.
 * @param username: Admin username.
 * @param password: Admin password.
 * @param message: Message buffer for communication.
 * @param login_status: Status of admin login.
 */
void handleRequestAdmin(int sockfd, char *username, char *password, char *message, int *login_status){
    int admin_choice;
    do{
        viewAdmin();
        printf("Choice: ");
        scanf("%d", &admin_choice);
        clearKeyboardBuffer();
        switch(admin_choice) {
            case 1:{
                handleAddNewFilm(sockfd);
                break;
            }
            case 2:{
                handleAnnouncingFilm(sockfd);
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

/**
 * @function handleLogout: Handles the logout process.
 * @param sockfd: Socket file descriptor for communication.
 */
void handleLogout(int sockfd){
    char *message;
    message = (char *)malloc(255 * sizeof(char));
    makeLogoutMessage(message);
    sendMessage(sockfd, message);
    int result = recvResult(sockfd);
    printf("%d\n", result);
    printf(LOGOUT_SUCCESS_MESSAGE);
}

/**
 * @function handleChangePassword: Handles the process of changing the password.
 * 
 * @param sockfd: Socket file descriptor for communication.
 * @param username: User's username.
 * @param message: Message buffer for communication.
 */
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

/**
 * @function handleRegister: Handles the user registration process.
 * 
 * @param sockfd: Socket file descriptor for communication.
 */
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

/**
 * @function handleSearchByTitle: Handles the search for films by title.
 * 
 * @param sockfd: Socket file descriptor for communication.
 * @param title: Title of the film to search for.
 * @param message: Message buffer for communication.
 */
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

/**
 * @function handleAddNewFilm: Handles the process of adding a new film.
 * 
 * @param sockfd: Socket file descriptor for communication.
 */
void handleAddNewFilm(int sockfd){
    char *title, *category_id, *show_time, *description, *message;

    title = (char *)malloc(255 * sizeof(char));
    category_id = (char *)malloc(255 * sizeof(char));
    show_time = (char *)malloc(255 * sizeof(char));
    description = (char *)malloc(2048 * sizeof(char));
    message = (char *)malloc(255 * sizeof(char));

    addNewFilm(sockfd, title, category_id, show_time, description);
    makeAddNewFilmMessage(title, category_id, show_time, description, message);
    sendMessage(sockfd, message);

    int result = recvResult(sockfd);
    if(result == ADD_FILM_SUCCESS){
        printf("%s\n", ADD_FILM_SUCCESS_MESSAGE);
    }else if(result == ADD_FILM_FAIL){
        printf("%s\n", ADD_FILM_FAIL_MESSAGE);
    }
}

/**
 * @function handleAnnouncingFilm: Handles the process of announcing a film for screening.
 * 
 * @param sockfd: Socket file descriptor for communication.
 */
void handleAnnouncingFilm(int sockfd) {
        char *film_id, *cinema_id, *premiered_time_id, *day, *month, *year, *date, *message;
        film_id = (char *)malloc(255 * sizeof(char));
        cinema_id = (char *)malloc(255 * sizeof(char));
        premiered_time_id = (char *)malloc(255 * sizeof(char));
        day = (char *)malloc(255 * sizeof(char));
        month = (char *)malloc(255 * sizeof(char));
        year = (char *)malloc(255 * sizeof(char));
        date = (char *)malloc(255 * sizeof(char));
        message = (char *)malloc(255 * sizeof(char));

        makeShowPostFilmMessage(message);
        sendMessage(sockfd, message);

        recvMessage(sockfd, message);
        printf("%s", message);
        getAnnouncementFilmID(film_id);

        recvMessage(sockfd, message);
        printf("%s", message);
        getAnnouncementCinemaID(cinema_id);

        recvMessage(sockfd, message);
        printf("%s", message);
        getAnnouncementPreTimeID(premiered_time_id);

        getAnnouncementDate(day, month, year, date);

        printf("%s\n", date);

        makeAnnounceFilmMessage(film_id, cinema_id, premiered_time_id, date, message);
        printf("%s\n", message);
        sendMessage(sockfd, message);

        int result = recvResult(sockfd);
        if(result == POST_FILM_SUCCESS){
            printf("%s\n", POST_FILM_SUCCESS_MESSAGE);
        }else if(result == POST_FILM_FAIL){
            printf("%s\n", POST_FILM_FAIL_MESSAGE);
        }
    }

/**
 * @function handleBrowseFollowCategory: Handles browsing movies by category.
 * 
 * @param sockfd: Socket file descriptor for communication.
 */
void handleBrowseFollowCategory(int sockfd){
    char *category_id, *message;
    category_id = (char *)malloc(255 * sizeof(char));
    message = (char *)malloc(255 * sizeof(char));

    //in ra danh sach cac category
    makeShowCategoryMessage(message);
    sendMessage(sockfd, message);
    recvMessage(sockfd, message);
    printf("%s\n", message);

    getCategoryID(&category_id);
    printf("%ld\n", strlen(category_id));
    makeBrowseFollowCategoryMessage(category_id, message);
    printf("%s\n", message);
    sendMessage(sockfd, message);



    int result = recvResult(sockfd);
    if(result == BROWSE_CATEGORY_SUCCESS){
        printf("%s\n", BROWSE_CATEGORY_SUCCESS_MESSAGE);
        free(message);
        message = (char *)malloc(255 * sizeof(char));
        recvMessage(sockfd, message); 

        printf("%s\n", message);         //print list of movies by category
    }else if(result == BROWSE_FAIL){
        printf("%s\n", BROWSE_FAIL_MESSAGE);
    }
}

/**
 * @function handleBrowseFollowCinema: Handles browsing movies by cinema.
 * 
 * @param sockfd: Socket file descriptor for communication.
 */
void handleBrowseFollowCinema(int sockfd){
    char *cinema_id, *message;
    cinema_id = (char *)malloc(255 * sizeof(char));
    message = (char *)malloc(255 * sizeof(char));

    //Print out the list of theaters
    makeShowCinemaMessage(message);
    sendMessage(sockfd, message);
    recvMessage(sockfd, message);
    printf("%s\n", message);

    getCinemaID(&cinema_id);
    printf("%ld\n", strlen(cinema_id));

    makeBrowseFollowCinemaMessage(cinema_id, message);
    printf("%s\n", message);
    sendMessage(sockfd, message);


    int result = recvResult(sockfd);
    if(result == BROWSE_THEATER_SUCCESS){
        printf("%s\n", BROWSE_THEATER_SUCCESS_MESSAGE);
        free(message);
        message = (char *)malloc(255 * sizeof(char));
        recvMessage(sockfd, message); 

        printf("%s\n", message); // print list of movies by cinema
    }else if(result == BROWSE_FAIL){
        printf("%s\n", BROWSE_FAIL_MESSAGE);
    }
}

/**
 * @function handleBrowseFollowShowTime: Handles browsing movies by showtime.
 * 
 * @param sockfd: Socket file descriptor for communication.
 */
void handleBrowseFollowShowTime(int sockfd){
    char *premiered_time_id, *message;
    premiered_time_id = (char *)malloc(255 * sizeof(char));
    message = (char *)malloc(255 * sizeof(char));

    //Print out a list of show times
    makeShowPremieredTimeMessage(message);
    sendMessage(sockfd, message);
    recvMessage(sockfd, message);
    printf("%s\n", message);

    getPremieredTimeID(&premiered_time_id);
    printf("%ld\n", strlen(premiered_time_id));

    makeBrowseFollowPremieredTimeMessage(premiered_time_id, message);
    printf("%s\n", message);
    sendMessage(sockfd, message);

    int result = recvResult(sockfd);
    if(result == BROWSE_TIME_SUCCESS){
        printf("%s\n", BROWSE_TIME_SUCCESS_MESSAGE);
        free(message);
        message = (char *)malloc(255 * sizeof(char));
        recvMessage(sockfd, message); 

        printf("%s\n", message); //printf list of movies and showtimes
    }else if(result == BROWSE_FAIL){
        printf("%s\n", BROWSE_FAIL_MESSAGE);
    }
}

/**
 * @function handleBrowseFilm: Handles the overall process of browsing movies by category, cinema, or showtime.
 * 
 * @param sockfd: Socket file descriptor for communication.
 */
void handleBrowseFilm(int sockfd){
    int browse_choose;
    do{
        browseFilm();
        printf("Choice: ");
        scanf("%d", &browse_choose);
        clearKeyboardBuffer();
        switch(browse_choose){
            case 1:{
                handleBrowseFollowCategory(sockfd);
                break;
            }
            case 2:{
                handleBrowseFollowCinema(sockfd);
                break;
            }
            case 3:{
                handleBrowseFollowShowTime(sockfd);
                break;
            }
            case 4:{
                browse_choose = 0;
                break;
            }
        }
    }while(browse_choose != 0);
}