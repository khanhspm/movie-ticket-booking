#include <mysql/mysql.h>
#include <string.h>
#include "../../lib/films/listFilm.h"

void selectFilm(MYSQL *connection, nodeFilm* h, film x){
    mysql_query(connection, "SELECT * FROM films");
    MYSQL_RES *result = mysql_store_result(connection);
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        x.id = strtoul(row[0], NULL, 10);
        strcpy(x.title, row[1]);
        x.category_id =  strtoul(row[2], NULL, 10);
        x.show_time = strtoul(row[3], NULL, 10);

        addNodeFilm(h, x);

    }

    mysql_free_result(result);
}