#include <string.h>
#include <stdio.h>
#include <mysql/mysql.h>
#include "queryUser.h"
#include "queryFilm.h"
#include "queryCategory.h"
#include "queryCinema.h"
#include "queryPremieredTime.h"
#include "queryPremieredTimeFilm.h"

char *selectPostedFilm(MYSQL *connection){
    mysql_query(connection, "SELECT films.*, premiered_time.*, cinemas.* FROM films JOIN premiered_time_film ON films.id = premiered_time_film.film_id JOIN premiered_time ON premiered_time_film.premiered_time_id = premiered_time.id JOIN cinemas ON premiered_time_film.cinema_id = cinemas.id");
    MYSQL_RES *result = mysql_store_result(connection);
    if(result == NULL){
        return "Have not any film posted";
    }
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    char *content;
    content = malloc(10000 * 1048576 * sizeof(char));
    int a = 0;
    char str_a[10000];
    while ((row = mysql_fetch_row(result))) {
        a++;
        sprintf(str_a, "%d", a);
        strcat(content, "\nSTT: ");
        strcat(content, str_a);
        strcat(content, "\nFilm: ");
        strcat(content, row[1]);
        strcat(content, "\nDescription: ");
        strcat(content, row[4]);
        strcat(content, "\nStart time: ");
        strcat(content, row[6]);
        strcat(content, "\nFinish time: ");
        strcat(content, row[7]);
        strcat(content, "\nCinema: ");
        strcat(content, row[9]);
        strcat(content, "\nAddress: ");
        strcat(content, row[10]);
        strcat(content, "\n");
    }

    mysql_free_result(result);

    return content;

}