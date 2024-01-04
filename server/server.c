#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include "../lib/socket/socket.h"
#include "../lib/messages/message.h"
#include "headers/queryUser.h"
#include "../data/connect.h"

#define REGISTER_SUCCESS 1101
#define REGISTER_FAIL 2102
#define BACKLOG 20

void *handleRequest(void *);

listLoginedAccount myArray;

node h = NULL;

MYSQL *conn;
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./server_out <number port>\n");
        exit(1);
    }

    myArray = createListLoginedUser(myArray);

    connectDatabase(&conn);

    user x;
    printf("Server started !\n");

    selectUser(conn, &h, x);
    printf("Connected SQL\n");

    int listenfd, *connfd;
    struct sockaddr_in server;  // Server's address information
    struct sockaddr_in *client; // Client's address information
    socklen_t sin_size = sizeof(struct sockaddr_in);
    pthread_t tid;

    // Step 1: Construct socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("\nError: ");
        return 0;
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY puts your IP address automatically

    if (bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("\nError: ");
        return 0;
    }

    if (listen(listenfd, BACKLOG) == -1)
    {
        perror("\nError: ");
        return 0;
    }

    client = malloc(sin_size);

    while (1)
    {
        connfd = malloc(sizeof(int));
        *connfd = accept(listenfd, (struct sockaddr *)client, &sin_size);

        if (*connfd == -1)
        {
            perror("\nError: ");
        }

        // For each client, spawn a thread, and the thread handles the new client
        pthread_create(&tid, NULL, &handleRequest, connfd);
    }

    close(listenfd);


    return 0;
}

void *handleRequest(void *arg)
{
    int connfd = *((int *)arg);
    free(arg);
    pthread_detach(pthread_self());
    if (connfd == -1)
    {
        perror("\nError: ");
        return NULL;
    }
    else
    {
        printf("1000\n");
        send(connfd, "1000", 255, 0);
    }

    printf("Connected with client.\n");

    while (1)
    {
        char *message, *type;
        message = (char *)malloc(255 * sizeof(char));
        type = (char *)malloc(255 * sizeof(char));
        recvMessage(connfd, message);
        if (strcmp(message, "EXIT") == 0)
        {
            break;
        }
        // printf("%s\n", message);
        type = getTypeMessage(message);
        // printf("%s\n", type);
        if (strcmp(type, "LOGIN") == 0)
        {
            char *username, *password;
            username = (char *)malloc(255 * sizeof(char));
            password = (char *)malloc(255 * sizeof(char));
            getLoginMessage(&username, &password);
            int check = checkLogin(h, username, password, myArray);
            if (check == 0)
            {
                sendResult(connfd, 2011);
            }
            else if (check == 1)
            {
                addToListLoginedAccount(&myArray, username);
                sendResult(connfd, 1011);
            }
            else if (check == 2)
            {
                addToListLoginedAccount(&myArray, username);
                sendResult(connfd, 1010);
            }
            else
            {
                sendResult(connfd, 2012);
            }
        }
        // Trong phần xử lý "REGISTER"
        else if (strcmp(type, "REGISTER") == 0)
        {
            // Lấy thông tin người dùng từ thông điệp
            char *name, *username, *password;
            name = (char *)malloc(255 * sizeof(char));
            username = (char *)malloc(255 * sizeof(char));
            password = (char *)malloc(255 * sizeof(char));
            getRegisterMessage(&name, &username, &password);

            // Thiết lập newUser
            user newUser;
            strcpy(newUser.name, name);
            strcpy(newUser.username, username);
            strcpy(newUser.password, password);
            newUser.role_id = 2; // Mặc định là user

            // Gọi hàm đăng ký và xử lý kết quả
            int result = registerUser(conn, newUser);
            if (result == 1)
            {
                sendResult(connfd, REGISTER_SUCCESS);
            }
            else
            {
                sendResult(connfd, REGISTER_FAIL);
            }

            
        }

    }

    close(connfd);
    return NULL;
}