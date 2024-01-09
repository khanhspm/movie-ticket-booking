#ifndef FUNCTION_H
#define FUNCTION_H

#include <mysql/mysql.h>
#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"
#include "queryUser.h"
#include "queryFilm.h"
#include "queryCategory.h"
#include "queryCinema.h"
#include "queryPremieredTime.h"
#include "queryPremieredTimeFilm.h"

void handleRequest(MYSQL *conn, char *type, int connfd, listLoginedAccount arr, node h, nodeFilm f, nodeCategory c, nodeCinema ci, nodePremieredTime pt, nodePremieredTimeFilm ptf);

void handleLogin(int connfd, listLoginedAccount arr, node h, char *username, char *password);

void handleRegister(MYSQL *conn, int connfd, node* h);

void handleChangePassword(int connfd, MYSQL *conn, node *h);

void handleLogout(int connfd, listLoginedAccount arr, char *username, char *password);

void handleSearchFilm(int connfd, nodeFilm f, nodeCategory c);

void handleAddNewFilm(MYSQL *conn, int connfd, nodeFilm f, nodeCategory c);

void handleBrowseFollowCategory(int connfd, nodeFilm f, nodeCategory c);

void handleBrowseFollowCinema(int connfd, nodeFilm f, nodeCinema c, nodePremieredTimeFilm ptf);
#endif