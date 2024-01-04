#ifndef FUNCTION_H
#define FUNCTION_H

#include <mysql/mysql.h>
#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"
#include "queryUser.h"

void handleRequest(MYSQL *conn, char *type, int connfd, listLoginedAccount arr, node h);

void handleLogin(int connfd, listLoginedAccount arr, node h, char *username, char *password);

void handleRegister(MYSQL *conn, int connfd);

void handleChangePassword(int connfd, MYSQL *conn);

void handleLogout(int connfd, listLoginedAccount arr, char *username, char *password);

// void hanldeSearchByTitle();

#endif