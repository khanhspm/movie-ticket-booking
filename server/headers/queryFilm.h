#ifndef QUERYFILM_H
#define QUERYFILM_H

#include<mysql/mysql.h>
#include "../../lib/films/listFilm.h"
#include "../../lib/categories/listCategory.h"

void selectFilm(MYSQL *connection, nodeFilm* h, film x);
char* getCategory(int id, nodeCategory head);

void addFilm(MYSQL *connection, film x);
#endif