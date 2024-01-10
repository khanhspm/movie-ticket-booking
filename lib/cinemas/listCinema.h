#ifndef LISTCINEMA_H
#define LISTCINEMA_H

#include "cinema.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListCinema(nodeCinema list);

/**
 * @function addNewNodeCinema: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeCinema(nodeCinema* head, cinema x);

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeCinema(nodeCinema* head, cinema x);

int searchCimema(nodeCinema head, char name[]);

char *displayCinema(nodeCinema head);

char *searchCinemaNameById(nodeCinema head, unsigned long id);
#endif