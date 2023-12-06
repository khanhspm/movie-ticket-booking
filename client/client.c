#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

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

    printf("Connected to server\n");

    while (1) {
        printf("Enter message: ");
        fgets(sendBuff, BUFSIZE, stdin);

        if(strlen(sendBuff) == 1){
            break;
        }

        send(sockfd, sendBuff, strlen(sendBuff), 0);

        n = recv(sockfd, rcvBuff, BUFSIZE, 0);
        if (n <= 0) {
            printf("Connection closed\n");
            break;
        }

        rcvBuff[n] = '\0';
        printf("Received: %s\n", rcvBuff);
    }

    close(sockfd);
    return 0;
}
