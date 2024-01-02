#include <mysql/mysql.h>
#include <string.h>
#include "../../lib/films/listFilm.h"

void selectFilmByTitle(MYSQL *connection, nodeFilm h, film x, char *title){
    mysql_query(connection, "SELECT * FROM films WHERE title = '%s'", title);
    MYSQL_RES *result = mysql_store_result(connection);
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        x.id = strtoul(row[0], NULL, 10);
        strcpy(x.title, row[1]);
        strcpy(x.category_id, row[2]);
        strcpy(x.show_time, row[3]);

        addNode(h, x);

    }

    mysql_free_result(result);
}