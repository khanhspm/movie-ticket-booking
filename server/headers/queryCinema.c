#include <mysql/mysql.h>
#include <string.h>
#include "../../lib/cinemas/listCinema.h"

/**
 * @function selectCinema: select all Cinemas
 * 
 * @param connection : connection of mysql
 * @param h : node pointer cinema
 * @param x : node cinema
 */
void selectCinema(MYSQL *connection, nodeCinema* h, cinema x){
    mysql_query(connection, "SELECT * FROM cinemas");
    MYSQL_RES *result = mysql_store_result(connection);
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        x.id = strtoul(row[0], NULL, 10);
        strcpy(x.name, row[1]);

        addNodeCinema(h, x);
    }

    mysql_free_result(result);
}