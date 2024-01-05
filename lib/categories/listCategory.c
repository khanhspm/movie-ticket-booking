#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "category.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListCategory(nodeCategory list){
	return list == NULL;
}

/**
 * @function addNewNodeCategory: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeCategory(nodeCategory* head, category x){
    struct NodeCategory* p = (struct NodeCategory*)malloc(sizeof(struct NodeCategory));
    p->data = x;
    p->next = NULL;
    if(checkEmptyListCategory(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeCategory(nodeCategory* head, category x){
    if(checkEmptyListCategory(*head)){
        addNewNodeCategory(head, x);
    }else{
        struct NodeCategory* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct NodeCategory* p = (struct NodeCategory*)malloc(sizeof(struct NodeCategory));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}

int searchCategory(nodeCategory head, char name[]){
    if(checkEmptyListCategory(head)){
        return 0;
    }else{
        struct NodeCategory* p = head;
        while(p != NULL){
            if(strcmp(name, p->data.name) == 0){
                return p->data.id;
            }
            p = p->next;
        }
    }
    return -1;
}