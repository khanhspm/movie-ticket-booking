#ifndef LISTROOM_H
#define LISTROOM_H

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListTicket(nodeTicket list);

/**
 * @function addNewNodeTicket: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeTicket(nodeTicket* head, ticket x);

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeTicket(nodeTicket* head, ticket x);

#endif