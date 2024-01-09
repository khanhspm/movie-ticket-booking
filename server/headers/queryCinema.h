#ifndef QUERYCINEMA_H
#define QUERYCIMEMA_H

#include <mysql/mysql.h>
#include "../../lib/cinemas/listCinema.h"

void selectCinema(MYSQL *connection, nodeCinema* h, cinema x);

#endif