#ifndef FUNCTION_H
#define FUNCTION_H

#include "../../lib/socket/socket.h"
#include "../../lib/messages/message.h"
#include "queryUser.h"

void handleRequest(char *type, int connfd, listLoginedAccount arr, node h, MYSQL *connection, user x);

#endif