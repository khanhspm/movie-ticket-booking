
#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>
#include "../../lib/films/listFilm.h"
#include "../../lib/categories/category.h"

/**
 * @function selectFilm: select all film
 * 
 * @param connection : connection of mysql
 * @param h : node pointer film
 * @param x : film
 */
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
        strcpy(x.description, row[4]);

        addNodeFilm(h, x);
    }

    mysql_free_result(result);
}

/**
 * @brief Get the Category object
 * 
 * @param id : id to get the category
 * @param head : head to get the category
 * @return char* 
 */
char* getCategory(int id, nodeCategory head){
    struct NodeCategory* p = head;
    while(p != NULL){
        if(p->data.id == id){
            return p->data.name;
        }
    }
    return NULL;
}

/**
 * @brief add a film to database
 * 
 * @param connection : connection of mysql
 * @param x : film to add
 */
void addFilm(MYSQL *connection, film x)
{
    char query[4096];
    snprintf(query, sizeof(query), "INSERT INTO films(title, category_id, show_time, description) VALUES('%s', %ld, %ld, '%s')", x.title, x.category_id, x.show_time, x.description);
    mysql_query(connection, query);
}