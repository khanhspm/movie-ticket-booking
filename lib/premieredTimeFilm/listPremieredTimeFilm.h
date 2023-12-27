#ifndef LISTROOM_H
#define LISTROOM_H

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListPremieredTimeFilm(nodePremieredTimeFilm list);

/**
 * @function addNewNodePremieredTimeFilm: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodePremieredTimeFilm(nodePremieredTimeFilm* head, premieredTimeFilm x);

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodePremieredTimeFilm(nodePremieredTimeFilm* head, premieredTimeFilm x);

#endif