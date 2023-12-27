#ifndef LISTSEAT_H
#define LISTSEAT_H

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListSeat(nodeSeat list);

/**
 * @function addNewNodeSeat: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeSeat(nodeSeat* head, seat x);

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeSeat(nodeSeat* head, seat x);

#endif