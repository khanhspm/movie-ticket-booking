#ifndef SOCKET_H
#define SOCKET_H

void sendMessage(int fd, char *message);
void recvMessage(int fd, char *message);
void sendResult(int fd, int result);
int recvResult(int fd);

#endif