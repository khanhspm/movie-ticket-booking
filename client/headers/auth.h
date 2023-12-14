#include <string.h>
#include "IOsocket.h"

#define LOGIN_SUCCESS_MESSAGE "You have logged in successfully!!\n"
#define LOGIN_FAIL_MESSAGE "Your username or password is incorrect!!\n"
#define LOGIN_ALREADY_MESSAGE "Your account is being used in another address!!\n"
#define LOGOUT_SUCCESS_MESSAGE "You have been successfully logged out!!\n"
#define LOGOUT_FAIL_MESSAGE "You have not logined yet!!\n"
#define REGISTER_SUCCESS "1101"
#define REGISTER_FAIL "2102"
#define BUFSIZE 1024

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

    return getResultRequest(socketfd, message);
}

// Chức năng đăng ký trả lời theo mã trả lời từ server
void handleRegister(int sockfd, char *username, char *password, char *message) {
    strcpy(message, "REGISTER");
    strcat(message, " ");
    strcat(message, username);
    strcat(message, " ");
    strcat(message, password);

    // Gửi yêu cầu đăng ký đến server
    send(sockfd, message, strlen(message), 0);

    // Nhận mã trả lời từ server
    recv(sockfd, message, sizeof(message), 0);

    // tach chuoi nhan dc thanh username va password
    char *response = strtok(message, " ");
    char *result = strtok(NULL, " ");
    
    // Kiểm tra mã trả lời và in ra thông báo tương ứng
    if (strcmp(message, REGISTER_SUCCESS) == 0) {
        printf("Registration successful!\n");
    } else if (strcmp(message, REGISTER_FAIL) == 0) {
        printf("Registration failed. Username already exists!\n");
    } else {
        printf("Unexpected response from the server.\n");
    }
}


int handleLogout(int socketfd, char message[]){
    message[0] = '\0';
    strcpy(message, "LOGOUT");

    printf("%s\n", message);

    int result = getResultRequest(socketfd, message);

    printf("%d\n", result);

    if(result == 1102){
        return 0;
    }else if(result == 2103){
        return 6;
    }
}