#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "premieredTimeFilm.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListPremieredTimeFilm(nodePremieredTimeFilm list){
	return list == NULL;
}

/**
 * @function addNewNodePremieredTimeFilm: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodePremieredTimeFilm(nodePremieredTimeFilm* head, premieredTimeFilm x){
    struct NodePremieredTimeFilm* p = (struct NodePremieredTimeFilm*)malloc(sizeof(struct NodePremieredTimeFilm));
    p->data = x;
    p->next = NULL;
    if(checkEmptyListPremieredTimeFilm(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodePremieredTimeFilm(nodePremieredTimeFilm* head, premieredTimeFilm x){
    if(checkEmptyListPremieredTimeFilm(*head)){
        addNewNodePremieredTimeFilm(head, x);
    }else{
        struct NodePremieredTimeFilm* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct NodePremieredTimeFilm* p = (struct NodePremieredTimeFilm*)malloc(sizeof(struct NodePremieredTimeFilm));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}
