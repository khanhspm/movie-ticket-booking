#include <string.h>

void handleLogin(int socketfd, char *username, char *password, char message[]){
    strcpy(message, "LOGIN");
    strcat(message, " ");
    strcat(message, username);
    strcat(message, " ");
    strcat(message, password);
    send(socketfd, message, 255, 0);

    message[0] = '\0';
    recv(socketfd, message, 1024, 0);
    printf("%s", message);
}