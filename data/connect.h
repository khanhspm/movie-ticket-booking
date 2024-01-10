#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "mvk652002"
#define DATABASE "ticketbooking"

void connectDatabase(MYSQL **connection) {
    // Initialize a MYSQL object
    *connection = mysql_init(NULL);

    // Check if initialization was successful
    if (*connection == NULL) {
        printf("Couldn't connect to database\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the MySQL server
    mysql_real_connect(*connection, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);

}
