#ifndef LISTROOM_H
#define LISTROOM_H

#include "room.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListRoom(nodeRoom list);

/**
 * @function addNewNodeRoom: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeRoom(nodeRoom* head, room x);

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeRoom(nodeRoom* head, room x);

#endif