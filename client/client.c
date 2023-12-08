#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "headers/menu.h"
#include "headers/auth.h"

#define BUFSIZE 1024

void clearKeyboardBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Đọc và loại bỏ các ký tự còn lại trong bộ đệm bàn phím
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <Server IP> <Server Port>\n", argv[0]);
        return 1;
    }

    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendBuff[BUFSIZE], rcvBuff[BUFSIZE];

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
    while (1) {
        
        do{
            viewWelcome();
            printf("Choice: ");
            scanf("%d", &choice);
            clearKeyboardBuffer();
            switch (choice) {
                case 1: {
                    char username[BUFSIZE], password[BUFSIZE], message[BUFSIZE];
                    memset(&username, 0, sizeof(username));
                    memset(&password, 0, sizeof(password));
                    viewLogin(username, password);
                    handleLogin(sockfd, username, password, message);
                    break;
                }
                case 2:
                case 3: exit(1);
            }
        }while(choice != 0);

    }

    close(sockfd);
    return 0;
}
