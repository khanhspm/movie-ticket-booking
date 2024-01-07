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
