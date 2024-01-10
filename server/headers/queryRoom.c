#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>
#include "../../lib/rooms/listRoom.h"

void selectRoom(MYSQL *connection, nodeRoom* h, room x){
    mysql_query(connection, "SELECT * FROM rooms");
    MYSQL_RES *result = mysql_store_result(connection);
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        x.id = strtoul(row[0], NULL, 10);
        strcpy(x.name, row[1]);
        x.quantity_seats = strtoul(row[2], NULL, 10);
        x.cinema_id = strtoul(row[3], NULL, 10);
        x.status = strtoul(row[4], NULL, 10);

        addNodeRoom(h, x);

    }

    mysql_free_result(result);
}