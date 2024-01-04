#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "film.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListFilm(nodeFilm list){
	return list == NULL;
}

/**
 * @function addNewNodeFilm: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeFilm(nodeFilm* head, film x){
    struct NodeFilm* p = (struct NodeFilm*)malloc(sizeof(struct NodeFilm));
    p->data = x;
    p->next = NULL;
    if(checkEmptyListFilm(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeFilm(nodeFilm* head, film x){
    if(checkEmptyListFilm(*head)){
        addNewNodeFilm(head, x);
    }else{
        struct NodeFilm* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct NodeFilm* p = (struct NodeFilm*)malloc(sizeof(struct NodeFilm));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}

/**
 * @function Title: search the film has title
 * 
 * @param head : node head of list
 * @param title : the title needed to search
 */
void searchTitle(nodeFilm head, char title[]){
    int a = 0;
    if(checkEmptyListFilm(head)){
        printf("No data!\n");
        return;
    }else{
        struct NodeFilm* p = head;
        while(p != NULL){
            if(strcmp(title, p->data.title) == 0){
                a++;
                printf("%d. %s %ld %ld\n", a, p->data.title, p->data.category_id, p->data.show_time);
            }
            p = p->next;
        }
    }
    if(a == 0) printf("The film you need search is not exist!\n");
}