#ifndef QUERYUSER_H
#define QUERYUSER_H
#include <mysql/mysql.h>
#include "../../lib/loginedUser.h"
#include "../../lib/users/listUser.h"

void selectUser(MYSQL *connection, node* h, user x);

listLoginedAccount createListLoginedAccount();
void addToListLoginedAccount(listLoginedAccount *arr, const char *value);
void freeListLoginedAccount(listLoginedAccount *arr);
int searchListLoginedAccount(const listLoginedAccount *arr, const char *value);
listLoginedAccount createListLoginedUser(listLoginedAccount arr);

int checkLogin(node head, char *username, char *password, listLoginedAccount arr);
int registerUser(MYSQL *connection, user newUser);
int changePassword(MYSQL *connection, char *username, char *oldPassword, char *newPassword);
#endif