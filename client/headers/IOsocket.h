
#define LOGIN_SUCCESS_USER 1010
#define LOGIN_SUCCESS_ADMIN 1011
#define LOGIN_FAIL 2011
#define LOGIN_ALREADY 2012
#define LOGOUT_SUCCESS 1102
#define REGISTER_SUCCESS 1101
#define REGISTER_FAIL 2102
#define ADD_FILM_SUCCESS 1200
#define ADD_FILM_FAIL 2200
#define POST_FILM_SUCCESS 1201
#define POST_FILM_FAIL 2201
#define EDIT_FILM_SUCCESS 1202
#define EDIT_FILM_FAIL 2202
#define NO_EDIT_FILM 2203
#define BROWSE_CATEGORY_SUCCESS 1301
#define BROWSE_THEATER_SUCCESS 1302
#define BROWSE_TIME_SUCCESS 1303
#define BROWSE_FAIL 2300
#define FIND_FILM_SUCCESS 1304
#define FIND_FILM_FAIL 2301
#define VIEW_CHAIR_SUCCESS 1305
#define VIEW_CHAIR_FAIL 2302
#define CHOOSE_CHAIR_SUCCESS 1306
#define CHOOSE_CHAIR_FAIL 2303
#define BOOK_TICKET_SUCCESS 1307
#define BOOK_TICKET_FAIL 2304
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
#define CHANGE_PASSWORD_SUCCESS_MESSAGE "Changed password successfully\n"
#define CHANGE_PASSWORD_FAIL_MESSAGE "Changed password fail!!\n" 


int getResultRequest(int socketfd){

    int result = recvResult(socketfd);

    if((result == LOGIN_SUCCESS_USER) || (result == LOGIN_SUCCESS_ADMIN)){
        printf("%s\n", LOGIN_SUCCESS_MESSAGE);
    }else if(result == LOGIN_FAIL){
        printf("%s\n", LOGIN_FAIL_MESSAGE);
    }else if(result == LOGIN_ALREADY){
        printf("%s\n", LOGIN_ALREADY_MESSAGE);
    }else if(result == LOGOUT_SUCCESS){
        printf("%s\n", LOGOUT_SUCCESS_MESSAGE);
    }else if(result == REGISTER_SUCCESS){
        printf("%s\n", REGISTER_SUCCESS_MESSAGE);
    }else if(result == REGISTER_FAIL){
        printf("%s\n", REGISTER_FAIL_MESSAGE);
    }else if(result == ADD_FILM_SUCCESS){
        printf("%s\n", ADD_FILM_SUCCESS_MESSAGE);
    }else if(result == ADD_FILM_FAIL){
        printf("%s\n", ADD_FILM_FAIL_MESSAGE);
    }else if(result == POST_FILM_SUCCESS){
        printf("%s\n", POST_FILM_SUCCESS_MESSAGE);
    }else if(result == POST_FILM_FAIL){
        printf("%s\n", POST_FILM_FAIL_MESSAGE);
    }else if(result == EDIT_FILM_SUCCESS){
        printf("%s\n", EDIT_FILM_SUCCESS_MESSAGE);
    }else if(result == EDIT_FILM_FAIL){
        printf("%s\n", EDIT_FILM_FAIL_MESSAGE);
    }else if(result == NO_EDIT_FILM){
        printf("%s\n", NO_EDIT_FILM_MESSAGE);
    }else if(result == BROWSE_CATEGORY_SUCCESS){
        printf("%s\n", BROWSE_CATEGORY_SUCCESS_MESSAGE);
    }else if(result == BROWSE_THEATER_SUCCESS){
        printf("%s\n", BROWSE_THEATER_SUCCESS_MESSAGE);
    }else if(result == BROWSE_TIME_SUCCESS){
        printf("%s\n", BROWSE_TIME_SUCCESS_MESSAGE);
    }else if(result == BROWSE_FAIL){
        printf("%s\n", BROWSE_FAIL_MESSAGE);
    }else if(result == FIND_FILM_SUCCESS){
        printf("%s\n", FIND_FILM_SUCCESS_MESSAGE);
    }else if(result == FIND_FILM_FAIL){
        printf("%s\n", FIND_FILM_FAIL_MESSAGE);
    }else if(result == VIEW_CHAIR_SUCCESS){
        printf("%s\n", VIEW_CHAIR_SUCCESS_MESSAGE);
    }else if(result == VIEW_CHAIR_FAIL){
        printf("%s\n", VIEW_CHAIR_FAIL_MESSAGE);
    }else if(result == CHOOSE_CHAIR_SUCCESS){
        printf("%s\n", CHOOSE_CHAIR_SUCCESS_MESSAGE);
    }else if(result == CHOOSE_CHAIR_FAIL){
        printf("%s\n", CHOOSE_CHAIR_FAIL_MESSAGE);
    }else if(result == BOOK_TICKET_SUCCESS){
        printf("%s\n", BOOK_TICKET_SUCCESS_MESSAGE);
    }else if(result == BOOK_TICKET_FAIL){
        printf("%s\n", BOOK_TICKET_FAIL_MESSAGE);
    }else{
        printf("%s\n", INVALID_MESSAGE_MESSAGE);
    }

    return result;
}