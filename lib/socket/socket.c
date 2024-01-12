#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 255

/**
 * @function sendMessage: send a message to a socket
 * 
 * @param fd : the socket to send message
 * @param message : the message to send
 */
void sendMessage(int fd, char *message){
    int length = htonl(strlen(message));
    send(fd, &length, sizeof(length), 0);
    send(fd, message, strlen(message), 0);
}

/**
 * @function recvMessage: receive a message from a socket
 * 
 * @param fd : the socket to receive messages
 * @param message : the message to be received
 */
void recvMessage(int fd, char *message){
    int length = 0;
    char buffer[BUFSIZE];
    memset(&buffer, 0, BUFSIZE);
    recv(fd, &length, sizeof(length), 0);
    recv(fd, buffer, ntohl(length), 0);
    strcpy(message, buffer);
}

/**
 * @function sendResult: send result to client
 * 
 * @param fd : the socket to send result
 * @param result : the result to send
 */
void sendResult(int fd, int result){
    int message = htonl(result);
    send(fd, &message, sizeof(message), 0);
}

/**
 * @function recvResult: recv result from server
 * 
 * @param fd : the socket to receive result
 * @return int 
 */
int recvResult(int fd){
    int result;
    recv(fd, &result, sizeof(result), 0);
    return ntohl(result);
}