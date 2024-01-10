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

void handleEditAnnouncedFilm(int sockfd);

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
                handleAddNewFilm(sockfd);
                break;
            }
            case 2:{
                handleAnnouncingFilm(sockfd);   // bat dau 23h
                break;
            }
            case 3:{
                handleEditAnnouncedFilm(sockfd);    // bat dau 8h30
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
    free(message);
    message = (char *)malloc(255 * sizeof(char));
    getTitleFilm(title);
    makeSearchFilmByTitleMessage(title, message);
    printf("%s\n", message);
    sendMessage(sockfd, message);

    int result = recvResult(sockfd);
    if(result == FIND_FILM_SUCCESS){
        printf("%s\n", FIND_FILM_SUCCESS_MESSAGE);
        free(message);
        message = (char *)malloc(255 * sizeof(char));
        recvMessage(sockfd, message);
        printf("%s\n", message);
    }else if(result == FIND_FILM_FAIL){
        printf("%s\n", FIND_FILM_FAIL_MESSAGE);
    }
}

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

void handleEditAnnouncedFilm(int sockfd){
    // Gửi yêu cầu lấy thông tin suất chiếu hiện có
    char *message;
    message = (char *)malloc(100 * 1048576 * sizeof(char));

    makeShowPostedFilmMessage(message);
    sendMessage(sockfd, message);

    // Nhận và hiển thị danh sách suất chiếu
    recvMessage(sockfd, message);
    printf("%s", message);
    
    int choice_edit;
    do{
        viewEditPremieredTimeFilm();
        printf("Choice Edit: ");
        scanf("%d", &choice_edit);
        clearKeyboardBuffer();
        switch(choice_edit) {
            case 1:{
                // hanldeEditFilmPremiered(sockfd); 
                break;
            }
            case 2:{
                //handleEditCinemaPremiered(sockfd);
                break;
            }
            case 3:{
                //handleEditTimePremiered(sockfd);
                break;
            }
            case 4:{
                //handleEditDatePremiered(sockfd);
                break;
            }case 5: {
                choice_edit = 0;
                break;
            }
        }
    }while(choice_edit != 0);

}




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
    printf("ccc: %s\n", category_id);
    printf("%ld\n", strlen(category_id));
    makeBrowseFollowCategoryMessage(category_id, message);
    printf("%s\n", message);
    sendMessage(sockfd, message);
    printf("send%s\n", message);


    int result = recvResult(sockfd);
    printf("gui di %d\n", result);
    if(result == BROWSE_CATEGORY_SUCCESS){
        printf("%s\n", BROWSE_CATEGORY_SUCCESS_MESSAGE);
        free(message);
        message = (char *)malloc(255 * sizeof(char));
        recvMessage(sockfd, message); 

        printf("%s\n", message); //in list film theo category
    }else if(result == BROWSE_FAIL){
        printf("%s\n", BROWSE_FAIL_MESSAGE);
    }
}

void handleBrowseFollowCinema(int sockfd){
    char *cinema_id, *message;
    cinema_id = (char *)malloc(255 * sizeof(char));
    message = (char *)malloc(255 * sizeof(char));

    //in ra danh sach cac rap
    makeShowCinemaMessage(message);
    sendMessage(sockfd, message);
    recvMessage(sockfd, message);
    printf("%s\n", message);

    getCinemaID(&cinema_id);
    printf("ccc: %s\n", cinema_id);
    printf("%ld\n", strlen(cinema_id));

    makeBrowseFollowCinemaMessage(cinema_id, message);
    printf("%s\n", message);
    sendMessage(sockfd, message);
    printf("send%s\n", message);

    int result = recvResult(sockfd);
    printf("gui di %d\n", result);
    if(result == BROWSE_THEATER_SUCCESS){
        printf("%s\n", BROWSE_THEATER_SUCCESS_MESSAGE);
        free(message);
        message = (char *)malloc(255 * sizeof(char));
        recvMessage(sockfd, message); 

        printf("%s\n", message); //in list film theo 
    }else if(result == BROWSE_FAIL){
        printf("%s\n", BROWSE_FAIL_MESSAGE);
    }
}

void handleBrowseFollowShowTime(int sockfd){
    char *premiered_time_id, *message;
    premiered_time_id = (char *)malloc(255 * sizeof(char));
    message = (char *)malloc(255 * sizeof(char));

    //in ra danh sach cac khung jo chieu
    makeShowPremieredTimeMessage(message);
    sendMessage(sockfd, message);
    recvMessage(sockfd, message);
    printf("%s\n", message);

    getPremieredTimeID(&premiered_time_id);
    printf("ccc: %s\n", premiered_time_id);
    printf("%ld\n", strlen(premiered_time_id));

    makeBrowseFollowPremieredTimeMessage(premiered_time_id, message);
    printf("%s\n", message);
    sendMessage(sockfd, message);
    printf("send%s\n", message);

    int result = recvResult(sockfd);
    printf("gui di %d\n", result);
    if(result == BROWSE_TIME_SUCCESS){
        printf("%s\n", BROWSE_TIME_SUCCESS_MESSAGE);
        free(message);
        message = (char *)malloc(255 * sizeof(char));
        recvMessage(sockfd, message); 

        printf("%s\n", message); //in list film theo
    }else if(result == BROWSE_FAIL){
        printf("%s\n", BROWSE_FAIL_MESSAGE);
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
                handleBrowseFollowCategory(sockfd);
                break;
            }
            case 2:{
                handleBrowseFollowCinema(sockfd);   //16h30 9/1/2023 bat dau lam.
                break;
            }
            case 3:{
                handleBrowseFollowShowTime(sockfd);    // bat dau 19h45
                break;
            }
            case 4:{
                browse_choose = 0;
                break;
            }
        }
    }while(browse_choose != 0);
}