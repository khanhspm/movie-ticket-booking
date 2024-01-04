#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "headers/function.h"
#include "headers/menu.h"

#define BUFSIZE 1024

int main(int argc, char **argv) {
    if(argc != 3){
        printf("Usage: ./client_out <ip address> <number port>\n");
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("\nERROR: ");
        return 0;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("\nERROR: ");
        return 0;
    }

    char conn_mess[1024];
    recv(sockfd, conn_mess, sizeof(conn_mess), 0);
    printf("\n\n%s\n\n", conn_mess);
    int choice;
    int *login_status = 0;
    login_status = (int *)malloc(sizeof(int));
    while (1) {
        
        do{
            viewWelcome();
            printf("Choice: ");
            scanf("%d", &choice);
            clearKeyboardBuffer();
            switch (choice) {
                case 1: {
                    char *username, *password, *message;
                    message = (char *)malloc(255 * sizeof(char));
                    username = (char *)malloc(255 * sizeof(char));
                    password = (char *)malloc(255 * sizeof(char));
                    handleLogin(sockfd, username, password, message, login_status);
                    if(*login_status == LOGIN_SUCCESS_USER){
                        handleRequestUser(sockfd, username, password, message, login_status);
                    }else if(*login_status == LOGIN_SUCCESS_ADMIN){
                        handleRequestAdmin(sockfd, username, password, message, login_status);
                    }
                    break;
                }
                case 2: {
                    handleRegister(sockfd);
                    break;
                }
                case 3: {
                    printf("\n\nThanks for coming to HTV-SPM!!\n\n");
                    sendMessage(sockfd, "EXIT");
                    close(sockfd);
                    return 0;
                    exit(0);
                }
                default: {
                    printf("Unknown request type!\n\n");
                    break;
                }
            }
        }while(choice != 0);

    }

    close(sockfd);
    return 0;
}
