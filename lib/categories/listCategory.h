#ifndef LISTCATEGORY_H
#define LISTCATEGORY_H

#include "category.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListCategory(nodeCategory list);

/**
 * @function addNewNodeCategory: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeCategory(nodeCategory* head, category x);

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeCategory(nodeCategory* head, category x);

int searchCategory(nodeCategory head, char name[]);

#endif