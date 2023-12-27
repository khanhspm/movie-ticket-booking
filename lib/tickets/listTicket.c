#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "ticket.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListTicket(nodeTicket list){
	return list == NULL;
}

/**
 * @function addNewNodeTicket: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeTicket(nodeTicket* head, ticket x){
    struct NodeTicket* p = (struct NodeTicket*)malloc(sizeof(struct NodeTicket));
    p->data = x;
    p->next = NULL;
    if(checkEmptyListTicket(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeTicket(nodeTicket* head, ticket x){
    if(checkEmptyListTicket(*head)){
        addNewNodeTicket(head, x);
    }else{
        struct NodeTicket* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct NodeTicket* p = (struct NodeTicket*)malloc(sizeof(struct NodeTicket));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}
