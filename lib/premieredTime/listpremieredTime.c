#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "premieredTime.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListPremieredTime(nodePremieredTime list){
	return list == NULL;
}

/**
 * @function addNewNodePremieredTime: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodePremieredTime(nodePremieredTime* head, premieredTime x){
    struct NodePremieredTime* p = (struct NodePremieredTime*)malloc(sizeof(struct NodePremieredTime));
    p->data = x;
    p->next = NULL;
    if(checkEmptyListPremieredTime(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodePremieredTime(nodePremieredTime* head, premieredTime x){
    if(checkEmptyListPremieredTime(*head)){
        addNewNodePremieredTime(head, x);
    }else{
        struct NodePremieredTime* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct NodePremieredTime* p = (struct NodePremieredTime*)malloc(sizeof(struct NodePremieredTime));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}
/**
 * @brief display the premiered time
 * 
 * @param head : the head of the list
 * @return char* 
 */
char *displayPremieredTime(nodePremieredTime head)
{
    if (checkEmptyListPremieredTime(head))
    {
        printf("Empty list\n");
        return "Empty list\n";
    }
    else
    {
        struct NodePremieredTime *p = head;
        int bufferSize = 2048; 
        char *message = (char *)malloc(bufferSize * sizeof(char));



        strcpy(message, "STT\t  Start time\tEnd time\n");


        while (p != NULL)
        {
            char temp[4096]; 
            sprintf(temp, "%ld\t%10s\t%s\n", p->data.id, p->data.start_time, p->data.finish_time);
            strcat(message, temp);

            p = p->next;
        }

        return message;
    }
}
