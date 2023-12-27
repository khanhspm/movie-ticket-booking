#ifndef LISTFILM_H
#define LISTFILM_H

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListFilm(nodeFilm list);

/**
 * @function addNewNodeFilm: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeFilm(nodeFilm* head, film x);

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeFilm(nodeFilm* head, film x);

/**
 * @function Title: search the film has title
 * 
 * @param head : node head of list
 * @param title : the title needed to search
 */
void searchTitle(nodeFilm head, char title[]);

#endif