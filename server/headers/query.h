#ifndef QUERY_H
#define QUERY_H

#include "queryUser.h"
#include "queryFilm.h"
#include "queryCategory.h"
#include "queryCinema.h"
#include "queryPremieredTime.h"
#include "queryPremieredTimeFilm.h"

char *selectPostedFilm(MYSQL *connection);

#endif