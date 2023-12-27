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
