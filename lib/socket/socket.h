#ifndef SOCKET_H
#define SOCKET_H

/**
 * @function sendMessage: send a message to a socket
 * 
 * @param fd : the socket to send message
 * @param message : the message to send
 */
void sendMessage(int fd, char *message);

/**
 * @function recvMessage: receive a message from a socket
 * 
 * @param fd : the socket to receive messages
 * @param message : the message to be received
 */
void recvMessage(int fd, char *message);

/**
 * @function sendResult: send result to client
 * 
 * @param fd : the socket to send result
 * @param result : the result to send
 */
void sendResult(int fd, int result);

/**
 * @function recvResult: recv result from server
 * 
 * @param fd : the socket to receive result
 * @return int 
 */
int recvResult(int fd);

#endif