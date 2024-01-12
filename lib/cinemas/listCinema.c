#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
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

/**
 * @function searchCinema: Search for a cinema by name in the list.
 * 
 * @param head: Head of the cinema list.
 * @param name: Name of the cinema to search for.
 * 
 * @return: ID of the cinema if found, -1 otherwise.
*/
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

/**
 * @function displayCinema: Display information about cinemas in the list.
 * 
 * @param head: Head of the cinema list.
*/
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
        int bufferSize = 2048; 
        char *message = (char *)malloc(bufferSize * sizeof(char));

        strcpy(message, "");

        while (p != NULL)
        {
            char temp[512]; 
            sprintf(temp, "%ld %s\n", p->data.id, p->data.name);
            strcat(message, temp);

            p = p->next;
        }

        return message;
    }
}