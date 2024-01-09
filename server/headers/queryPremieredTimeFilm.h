#ifndef QUERYPREMIEREDTIMEFILM_H
#define QUERYPREMIEREDTIMEFILM_H

#include <mysql/mysql.h>
#include "../../lib/premieredTimeFilm/listPremieredTimeFilm.h"

void selectPremieredTimeFilm(MYSQL *connection, nodePremieredTimeFilm* h, premieredTimeFilm x);

#endif