#include <mysql/mysql.h>
#include <string.h>
#include "../../lib/categories/listCategory.h"

/**
 * @funtion selectCategory: select all categories
 * 
 * @param connection : connection of mysql
 * @param h : node category
 * @param x : category
 */
void selectCategory(MYSQL *connection, nodeCategory* h, category x){
    mysql_query(connection, "SELECT * FROM categories");
    MYSQL_RES *result = mysql_store_result(connection);
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        x.id = strtoul(row[0], NULL, 10);
        strcpy(x.name, row[1]);

        addNodeCategory(h, x);
    }

    mysql_free_result(result);
}