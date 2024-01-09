#ifndef LISTPREMIERED_H
#define LISTPREMIERED_H

#include "premieredTime.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListPremieredTime(nodePremieredTime list);

/**
 * @function addNewNodePremieredTime: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodePremieredTime(nodePremieredTime* head, premieredTime x);

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodePremieredTime(nodePremieredTime* head, premieredTime x);

#endif