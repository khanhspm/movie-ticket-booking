#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include "headers/auth.h"
#include "headers/IOsocket.h"

#define CONNECT_SUCCESS "Connected to HTV_SPM server\n"
#define BACKLOG 20  // Number of allowed connections
#define BUFF_SIZE 1024

listLoginedAccount myArray;

// Function to receive request from client then reply to the client and echo code result 
void *echo(void *);
int main(int argc, char **argv){

    myArray = createListLoginedUser(myArray);

    if(argc != 2){
        printf("Usage: ./server <number port>\n");
        exit(1);
    }

    int listenfd, *connfd;
    struct sockaddr_in server; // Server's address information
    struct sockaddr_in *client; // Client's address information
    socklen_t sin_size = sizeof(struct sockaddr_in);
    pthread_t tid;

    //Step 1: Construct socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("\nError: ");
        return 0;
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY puts your IP address automatically

    if (bind(listenfd, (struct sockaddr*)&server, sizeof(server)) == -1) {
        perror("\nError: ");
        return 0;
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("\nError: ");
        return 0;
    }

    client = malloc(sin_size);

    while (1) {
        connfd = malloc(sizeof(int));
        *connfd = accept(listenfd, (struct sockaddr*) client, &sin_size);
        if (*connfd == -1) {
            perror("\nError: ");
        }

        // For each client, spawn a thread, and the thread handles the new client
        pthread_create(&tid, NULL, &echo, connfd);
    }

    close(listenfd);

    return 0;
}

void *echo(void* arg) {
    node h = NULL;
    char string[1024];
    FILE *fp = fopen("data/account.txt", "r");
    if(fp == NULL){
        perror("Error: ");
        exit(EXIT_FAILURE);
    }

    //get data from the file account.txt
    while(fgets(string, 255, fp) != NULL){
        user x;
        if(sscanf(string, "%s\t%s\t%d\n", x.username, x.password, &x.role) == 3){
            addNode(&h, x);
        }
    }

    fclose(fp);

    node l = h;
    // print all account to screen
    while(l != NULL){
        printf("%s\t%s\t%d\n", l->data.username, l->data.password, l->data.role);
        l = l->next;
    }
    if(h == NULL) {
        printf("Can not get data!!\n");
        exit(EXIT_FAILURE);
    }
    
    int connfd = *((int*) arg);

    free(arg);
    pthread_detach(pthread_self());

    send(connfd, CONNECT_SUCCESS, sizeof(CONNECT_SUCCESS), 0);
    printf("1000\n");

    int *login_status = 0;
    login_status = (int *) malloc(sizeof(int));

    while(1){
        char message[1024];
        char resultMessage[1024];
        int type_request = getTypeRequest(connfd, message);
        char *username, *password;
        username = (char *)malloc(255 * sizeof(char));
        password = (char *)malloc(255 * sizeof(char));

        if(type_request == 1){
            username = strtok(NULL, " ");
            password = strtok(NULL, " ");
            int check = checkLogin(connfd, h, username, password, myArray);
            printf("%d\n", check);
            if(check == 1){
                addToListLoginedAccount(&myArray, username);
                *login_status = 1;
            }
        }else if(type_request == 2){
           //register
            username = strtok(NULL, " ");
            password = strtok(NULL, " ");
            int registerResult = handleRegister(username, password, resultMessage);
            printf("%d\n", registerResult);

            // feedback to client
            if (registerResult == 1) {
                send(connfd, REGISTER_SUCCESS, sizeof(REGISTER_SUCCESS), 0);
            } else {
                send(connfd, REGISTER_FAIL, sizeof(REGISTER_FAIL), 0);
            }
        }
        
    }

    close(connfd);
}