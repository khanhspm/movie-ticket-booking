#ifndef LISTUSER_H
#define LISTUSER_H

#include "user.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyList(node list);

/**
 * @function addNewNode: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNode(node* head, user x);

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNode(node* head, user x);

#endif