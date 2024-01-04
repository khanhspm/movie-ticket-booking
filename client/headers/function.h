#ifndef FUNCTIONCLIENT_H
#define FUNCTIONCLIENT_H

#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"
#include "menu.h"

void clearKeyboardBuffer();
void handleLogin(int sockfd, char *username, char *password, char *message, int *login_status);
void handleSearchByTitle(int sockfd, char *title, char *message);
void handleRequestUser(int sockfd, char *username, char *password, char *message, int *login_status);
void handleRequestAdmin(int sockfd, char *username, char *password, char *message, int *login_status);
void handleRegister(int sockfd);
void handleChangePassword(int sockfd, char *username, char *message);

#endif