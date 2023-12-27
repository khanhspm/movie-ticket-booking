#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../lib/socket/socket.h"
#include "../lib/messages/message.h"
#include "headers/menu.h"
// #include "headers/auth.h"

#define BUFSIZE 1024

void clearKeyboardBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Đọc và loại bỏ các ký tự còn lại trong bộ đệm bàn phím
    }
}

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
    // int *login_status = 0;
    while (1) {
        
        do{
            viewWelcome();
            printf("Choice: ");
            scanf("%d", &choice);
            clearKeyboardBuffer();
            switch (choice) {
                case 1: {
                    char *username, *password, *message;
                    username = (char *)malloc(255 * sizeof(char));
                    password = (char *)malloc(255 * sizeof(char));
                    message = (char *)malloc(255 * sizeof(char));
                    viewLogin(username, password);
                    makeLoginMessage(username, password, message);
                    printf("%s\n", message);
                    sendMessage(sockfd, message);
                    // login_status = (int *)malloc(sizeof(int));

                    // // if user login
                    // if(*login_status == 1100){
                    //     int user_choice;
                    //     do{
                    //         viewUser();
                    //         printf("Choice: ");
                    //         scanf("%d", &user_choice);
                    //         clearKeyboardBuffer();
                    //     }while(user_choice != 0);
                    // }else if(*login_status == 1110){   // if admin login
                    //     int admin_choice;
                    //     do{
                    //         viewAdmin();
                    //         printf("Choice: ");
                    //         scanf("%d", &admin_choice);
                    //         clearKeyboardBuffer();
                    //         switch(admin_choice) {
                    //             case 4: {
                    //                 admin_choice = handleLogout(sockfd, message);
                    //                 printf("%d\n", admin_choice);
                    //                 break;
                    //             }
                    //         }
                    //     }while(admin_choice != 0);
                    // }
                    break;
                }
                // case 2: {
                //     char *newUsername, *newPassword, message[BUFSIZE];
                //     newUsername = (char *)malloc(255 * sizeof(char));
                //     newPassword = (char *)malloc(255 * sizeof(char));
                //     viewRegister(newUsername, newPassword);
                //     handleRegister(sockfd, newUsername, newPassword, message);
                //     break;
                // }
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
