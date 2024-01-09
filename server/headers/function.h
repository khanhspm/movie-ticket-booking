#ifndef FUNCTION_H
#define FUNCTION_H

#include <mysql/mysql.h>
#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"
#include "queryUser.h"
#include "queryFilm.h"
#include "queryCategory.h"

void handleRequest(MYSQL *conn, char *type, int connfd, char **username, char *password, listLoginedAccount *arr, node h, nodeFilm f, nodeCategory c);

void handleLogin(int connfd, listLoginedAccount *arr, node h, char **username, char *password);

void handleRegister(MYSQL *conn, int connfd);

void handleChangePassword(int connfd, MYSQL *conn);

void handleLogout(int connfd, listLoginedAccount *arr, char **username);

void handleSearchFilm(int connfd, nodeFilm f, nodeCategory c);

#endif