#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "seat.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListSeat(nodeSeat list){
	return list == NULL;
}

/**
 * @function addNewNodeSeat: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeSeat(nodeSeat* head, seat x){
    struct NodeSeat* p = (struct NodeSeat*)malloc(sizeof(struct NodeSeat));
    p->data = x;
    p->next = NULL;
    if(checkEmptyListSeat(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeSeat(nodeSeat* head, seat x){
    if(checkEmptyListSeat(*head)){
        addNewNodeSeat(head, x);
    }else{
        struct NodeSeat* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct NodeSeat* p = (struct NodeSeat*)malloc(sizeof(struct NodeSeat));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}
