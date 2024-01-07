#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "hoantv2002"
#define DATABASE "ticketbooking"

void connectDatabase(MYSQL **connection) {
    *connection = mysql_init(NULL);

    if (*connection == NULL) {
        printf("Couldn't connect to database\n");
        exit(EXIT_FAILURE);
    }
    mysql_real_connect(*connection, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);

}
