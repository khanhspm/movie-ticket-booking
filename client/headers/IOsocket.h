#define LOGIN_SUCCESS_USER "1100"
#define LOGIN_SUCCESS_ADMIN "1110"
#define LOGIN_FAIL "2100"
#define LOGIN_ALREADY "2101"
#define LOGOUT_SUCCESS "1102"
#define LOGOUT_FAIL "2103"
#define REGISTER_SUCCESS "1101"
#define REGISTER_FAIL "2102"
#define ADD_FILM_SUCCESS "1200"
#define ADD_FILM_FAIL "2200"
#define POST_FILM_SUCCESS "1201"
#define POST_FILM_FAIL "2201"
#define EDIT_FILM_SUCCESS "1202"
#define EDIT_FILM_FAIL "2202"
#define NO_EDIT_FILM "2203"
#define BROWSE_CATEGORY_SUCCESS "1301"
#define BROWSE_THEATER_SUCCESS "1302"
#define BROWSE_TIME_SUCCESS "1303"
#define BROWSE_FAIL "2300"
#define FIND_FILM_SUCCESS "1304"
#define FIND_FILM_FAIL "2301"
#define VIEW_CHAIR_SUCCESS "1305"
#define VIEW_CHAIR_FAIL "2302"
#define CHOOSE_CHAIR_SUCCESS "1306"
#define CHOOSE_CHAIR_FAIL "2303"
#define BOOK_TICKET_SUCCESS "1307"
#define BOOK_TICKET_FAIL "2304"

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
#define BROWSE_CATEGORY_SUCCESS_MESSAGE "Browse follow category "
#define BROWSE_THEATER_SUCCESS_MESSAGE "Browse follow theater "
#define BROWSE_TIME_SUCCESS_MESSAGE "Browse follow time "
#define BROWSE_FAIL_MESSAGE "No film has been found!!\n"
#define FIND_FILM_SUCCESS_MESSAGE "Find film follow title "
#define FIND_FILM_FAIL_MESSAGE "No film has been found!!\n"
#define VIEW_CHAIR_SUCCESS_MESSAGE "MAP CHAIR\n"
#define VIEW_CHAIR_FAIL_MESSAGE "Has not empty chair in map\n"
#define CHOOSE_CHAIR_SUCCESS_MESSAGE "Choose successfully "
#define CHOOSE_CHAIR_FAIL_MESSAGE "This chair is not empty chair. Please choose again!!\n"
#define BOOK_TICKET_SUCCESS_MESSAGE "Booking ticket successfully!!\n"
#define BOOK_TICKET_FAIL_MESSAGE "Booking ticket failed!!\n"
#define INVALID_MESSAGE_MESSAGE "The request is invalid!!\n"


int getResultRequest(int socketfd, char *message){
    send(socketfd, message, 255, 0);

    message[0] = '\0';
    int recv_len = recv(socketfd, message, sizeof(message), 0);
    message[recv_len] = '\0';

    if(strcmp(message, LOGIN_SUCCESS_USER) == 0){
        printf("%s\n", LOGIN_SUCCESS_MESSAGE);
        return 1100;
    }else if(strcmp(message, LOGIN_SUCCESS_ADMIN) == 0){
        printf("%s\n", LOGIN_SUCCESS_MESSAGE);
        return 1110;
    }else if(strcmp(message, LOGIN_FAIL) == 0){
        printf("%s\n", LOGIN_FAIL_MESSAGE);
        return 2100;
    }else if(strcmp(message, LOGIN_ALREADY) == 0){
        printf("%s\n", LOGIN_ALREADY_MESSAGE);
        return 2101;
    }else if(strcmp(message, LOGOUT_SUCCESS) == 0){
        printf("%s\n", LOGOUT_SUCCESS_MESSAGE);
        return 1102;
    }else if(strcmp(message, LOGOUT_FAIL) == 0){
        printf("%s\n", LOGOUT_FAIL_MESSAGE);
        return 2103;
    }else if(strcmp(message, REGISTER_SUCCESS) == 0){
        printf("%s\n", REGISTER_SUCCESS_MESSAGE);
        return 1101;
    }else if(strcmp(message, REGISTER_FAIL) == 0){
        printf("%s\n", REGISTER_FAIL_MESSAGE);
        return 2102;
    }else if(strcmp(message, ADD_FILM_SUCCESS) == 0){
        printf("%s\n", ADD_FILM_SUCCESS_MESSAGE);
        return 1200;
    }else if(strcmp(message, ADD_FILM_FAIL) == 0){
        printf("%s\n", ADD_FILM_FAIL_MESSAGE);
        return 2200;
    }else if(strcmp(message, POST_FILM_SUCCESS) == 0){
        printf("%s\n", POST_FILM_SUCCESS_MESSAGE);
        return 1201;
    }else if(strcmp(message, POST_FILM_FAIL) == 0){
        printf("%s\n", POST_FILM_FAIL_MESSAGE);
        return 2201;
    }else if(strcmp(message, EDIT_FILM_SUCCESS) == 0){
        printf("%s\n", EDIT_FILM_SUCCESS_MESSAGE);
        return 1202;
    }else if(strcmp(message, EDIT_FILM_FAIL) == 0){
        printf("%s\n", EDIT_FILM_FAIL_MESSAGE);
        return 2202;
    }else if(strcmp(message, NO_EDIT_FILM) == 0){
        printf("%s\n", NO_EDIT_FILM_MESSAGE);
        return 2203;
    }else if(strcmp(message, BROWSE_CATEGORY_SUCCESS) == 0){
        printf("%s\n", BROWSE_CATEGORY_SUCCESS_MESSAGE);
        return 1301;
    }else if(strcmp(message, BROWSE_THEATER_SUCCESS) == 0){
        printf("%s\n", BROWSE_THEATER_SUCCESS_MESSAGE);
        return 1302;
    }else if(strcmp(message, BROWSE_TIME_SUCCESS) == 0){
        printf("%s\n", BROWSE_TIME_SUCCESS_MESSAGE);
        return 1303;
    }else if(strcmp(message, BROWSE_FAIL) == 0){
        printf("%s\n", BROWSE_FAIL_MESSAGE);
        return 2300;
    }else if(strcmp(message, FIND_FILM_SUCCESS) == 0){
        printf("%s\n", FIND_FILM_SUCCESS_MESSAGE);
        return 1304;
    }else if(strcmp(message, FIND_FILM_FAIL) == 0){
        printf("%s\n", FIND_FILM_FAIL_MESSAGE);
        return 2301;
    }else if(strcmp(message, VIEW_CHAIR_SUCCESS) == 0){
        printf("%s\n", VIEW_CHAIR_SUCCESS_MESSAGE);
        return 1305;
    }else if(strcmp(message, VIEW_CHAIR_FAIL) == 0){
        printf("%s\n", VIEW_CHAIR_FAIL_MESSAGE);
        return 2302;
    }else if(strcmp(message, CHOOSE_CHAIR_SUCCESS) == 0){
        printf("%s\n", CHOOSE_CHAIR_SUCCESS_MESSAGE);
        return 1306;
    }else if(strcmp(message, CHOOSE_CHAIR_FAIL) == 0){
        printf("%s\n", CHOOSE_CHAIR_FAIL_MESSAGE);
        return 2303;
    }else if(strcmp(message, BOOK_TICKET_SUCCESS) == 0){
        printf("%s\n", BOOK_TICKET_SUCCESS_MESSAGE);
        return 1307;
    }else if(strcmp(message, BOOK_TICKET_FAIL) == 0){
        printf("%s\n", BOOK_TICKET_FAIL_MESSAGE);
        return 2304;
    }else{
        printf("%s\n", INVALID_MESSAGE_MESSAGE);
        return 3000;
    }
}