#ifndef QUERYFILM_H
#define QUERYFILM_H

#include<mysql/mysql.h>
#include "../../lib/films/listFilm.h"

void selectFilm(MYSQL *connection, nodeFilm* h, film x);

#endif