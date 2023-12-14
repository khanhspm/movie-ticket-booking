#define LOGIN "LOGIN"
#define REGISTER "REGISTER"
#define LOGOUT "LOGOUT"
#define NEW_FILM "NEW_FILM"
#define POST "POST"
#define EDIT "EDIT"
#define CATEGORY "CATEGORY"
#define LOCATION "LOCATION"
#define TIME "TIME"
#define TITLE "TITLE"
#define VIEWCHAIR "VIEWCHAIR"
#define CHOOSE "CHOOSE"
#define TICKET "TICKET"
#define REGISTER_SUCCESS "1101"
#define REGISTER_FAIL_EXIST "2102"


int getTypeRequest(int socketfd, char request[]){
    int rec_u = recv(socketfd, request, 1024, 0); // received REQUEST from client

    if(rec_u < 0){
        perror("Error: ");
    }else if(rec_u == 0){
        return 0;
    }
    request[rec_u-1] = '\0';
    char *type;
    type = strtok(request, " ");
    if(strcmp(type, LOGIN) == 0){
        return 1;
    }else if(strcmp(type, REGISTER) == 0){
        return 2;
    }else if(strcmp(type, NEW_FILM) == 0){
        return 3;
    }else if(strcmp(type, POST) == 0){
        return 4;
    }else if(strcmp(type, EDIT) == 0){
        return 5;
    }else if(strcmp(type, CATEGORY) == 0){
        return 6;
    }else if(strcmp(type, LOCATION) == 0){
        return 7;
    }else if(strcmp(type, TIME) == 0){
        return 8;
    }else if(strcmp(type, TITLE) == 0){
        return 9;
    }else if(strcmp(type, VIEWCHAIR) == 0){
        return 10;
    }else if(strcmp(type, CHOOSE) == 0){
        return 11;
    }else if(strcmp(type, TICKET) == 0){
        return 12;
    }else{
        return 13;
    }
}