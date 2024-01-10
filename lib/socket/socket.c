#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void sendMessage(int fd, char *message){
    int length = htonl(strlen(message));
    send(fd, &length, sizeof(length), 0);
    send(fd, message, strlen(message), 0);
}

void recvMessage(int fd, char *message){
    int length = 0;
    char *buffer;
    buffer = malloc(10000 * 1048576 * sizeof(char));
    recv(fd, &length, sizeof(length), 0);
    recv(fd, buffer, ntohl(length), 0);
    strcpy(message, buffer);
}

void sendResult(int fd, int result){
    int message = htonl(result);
    send(fd, &message, sizeof(message), 0);
}

int recvResult(int fd){
    int result;
    recv(fd, &result, sizeof(result), 0);
    return ntohl(result);
}