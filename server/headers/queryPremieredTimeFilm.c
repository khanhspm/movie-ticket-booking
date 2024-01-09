#include <mysql/mysql.h>
#include <string.h>
#include "../../lib/premieredTimeFilm/listPremieredTimeFilm.h"

void selectPremieredTimeFilm(MYSQL *connection, nodePremieredTimeFilm* h, premieredTimeFilm x){
    mysql_query(connection, "SELECT * FROM premiered_time_film");
    MYSQL_RES *result = mysql_store_result(connection);
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        x.id = strtoul(row[0], NULL, 10);
        x.film_id = strtoul(row[1], NULL, 10);
        x.premiered_time_id = strtoul(row[2], NULL, 10);
        x.cinema_id = strtoul(row[3], NULL, 10);

        addNodePremieredTimeFilm(h, x);
    }

    mysql_free_result(result);
}