#include <string.h>

#define LOGIN_SUCCESS_MESSAGE "You have logged in successfully!!\n"
#define LOGIN_FAIL_MESSAGE "Your username or password is incorrect!!\n"
#define LOGIN_ALREADY_MESSAGE "Your account is being used in another address!!\n"
#define LOGOUT_SUCCESS_MESSAGE "You have been successfully logged out!!\n"
#define LOGOUT_FAIL_MESSAGE "You have not logined yet!!\n"

/**
 * @function handleLogin: handle the login process
 * 
 * @param socketfd : socket to connect 
 * @param username : username to login
 * @param password : password to login
 * @param message : message to send to the socket
 * @return : result of the login process
 */
int handleLogin(int socketfd, char *username, char *password, char message[]){
    //message = LOGIN + username + password
    strcpy(message, "LOGIN");
    strcat(message, " ");
    strcat(message, username);
    strcat(message, " ");
    strcat(message, password);
    send(socketfd, message, 255, 0);

    message[0] = '\0';
    int recv_lent = recv(socketfd, message, 1024, 0);
    message[recv_lent] = '\0';

    if(strcmp(message, "1100") == 0){
        printf("%s\n", LOGIN_SUCCESS_MESSAGE);
        return 1100;
    }else if(strcmp(message, "1110") == 0){
        printf("%s\n", LOGIN_SUCCESS_MESSAGE);
        return 1100;
    }else if(strcmp(message, "2100") == 0){
        printf("%s\n", LOGIN_FAIL_MESSAGE);
        return 2100;
    }else if(strcmp(message, "2101") == 0){
        printf("%s\n", LOGIN_ALREADY_MESSAGE);
        return 2101;
    }
}

int handleLogout(int socketfd, char *username, char message[]){
    send(socketfd, "LOGOUT", 255, 0);

    message[0] = '\0';
    int recv_lent = recv(socketfd, message, 1024, 0);
    message[recv_lent] = '\0';
}