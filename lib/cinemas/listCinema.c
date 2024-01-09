#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "cinema.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListCinema(nodeCinema list){
	return list == NULL;
}

/**
 * @function addNewNodeCinema: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeCinema(nodeCinema* head, cinema x){
    struct NodeCinema* p = (struct NodeCinema*)malloc(sizeof(struct NodeCinema));
    p->data = x;
    p->next = NULL;
    if(checkEmptyListCinema(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeCinema(nodeCinema* head, cinema x){
    if(checkEmptyListCinema(*head)){
        addNewNodeCinema(head, x);
    }else{
        struct NodeCinema* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct NodeCinema* p = (struct NodeCinema*)malloc(sizeof(struct NodeCinema));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}


int searchCimema(nodeCinema head, char name[])
{
    if (checkEmptyListCinema(head))
    {
        return 0;
    }
    else
    {
        struct NodeCinema *p = head;
        while (p != NULL)
        {
            if (strcmp(name, p->data.name) == 0)
            {
                return p->data.id;
            }
            p = p->next;
        }
    }
    return -1;
}

char *displayCinema(nodeCinema head)
{
    if (checkEmptyListCinema(head))
    {
        printf("Empty list\n");
        return "Empty list\n";
    }
    else
    {
        struct NodeCinema *p = head;
        int bufferSize = 2048; // Tùy thuộc vào yêu cầu của bạn
        char *message = (char *)malloc(bufferSize * sizeof(char));



        // Khởi tạo chuỗi message
        strcpy(message, "");

        // Duyệt danh sách và thêm thông tin từ mỗi node vào chuỗi message

        while (p != NULL)
        {
            // Nối thông tin từ mỗi node vào chuỗi message
            char temp[512]; // Kích thước tùy thuộc vào yêu cầu của bạn
            sprintf(temp, "%ld %s\n", p->data.id, p->data.name);
            strcat(message, temp);

            // Chuyển đến node tiếp theo
            p = p->next;
        }

        return message;
    }
}


