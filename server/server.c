#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define BACKLOG 20  // Number of allowed connections
#define BUFF_SIZE 1024




// Function to receive request from client then reply to the client and echo code result 
void *echo(void *);

int main(int argc, char **argv){

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

    int connfd = *((int*) arg);
    int sent_bytes, received_bytes;
    char buff[BUFF_SIZE + 1];

    connfd = *((int*) arg);
    free(arg);
    pthread_detach(pthread_self());

    while(1){
        received_bytes = recv(connfd, buff, BUFF_SIZE, 0);
    if(received_bytes < 0){
        perror("\nError: ");
    }else if(received_bytes == 0){
        printf("Conection closed\n");
        break;
    }else{
        sent_bytes = send(connfd, buff, received_bytes, 0);
        if(sent_bytes < 0){
            perror("\nError: ");
        }
    }
    }

    close(connfd);
}