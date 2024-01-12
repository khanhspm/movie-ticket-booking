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
int searchTitle(nodeFilm head, char title[], nodeFilm* addf){
    int a = 0;
    if(checkEmptyListFilm(head)){
        printf("No data!\n");
        return -1;
    }else{
        struct NodeFilm* p = head;
        while(p != NULL){
            if(strstr(p->data.title, title) != NULL){
                a++;
                addNodeFilm(addf, p->data);
            }
            p = p->next;
        }
    }
    return a;
}

/**
 * @function searchFilmFollowCategoryID: Search for films based on category ID.
 * 
 * @param head: Head of the film list.
 * @param category_id: Category ID to search for.
*/
char *searchFilmFollowCategoryID(nodeFilm head, int category_id)
{
    if (checkEmptyListFilm(head))
    {
        printf("No data!\n");
        return "No data!\n";
    }
    else
    {
        struct NodeFilm *p = head;
        int bufferSize = 1048576; 
        char *message = (char *)malloc(bufferSize * sizeof(char));

        int a = 0;

        while (p != NULL)
        {
            if (p->data.category_id == category_id)
            {
                a++;
                char temp[4096];
                sprintf(temp, "STT: %d\n", a);
                sprintf(temp + strlen(temp), "Title: %s\n", p->data.title);
                sprintf(temp + strlen(temp), "Show time: %ld\n", p->data.show_time);
                sprintf(temp + strlen(temp), "Description: %s\n\n", p->data.description);
                strcat(message, temp);
            }
            p = p->next;
        }

        return message;
    }
}

/**
 * @function searchFilmFollowID: Search for a film based on its ID.
 * 
 * @param head: Head of the film list.
 * @param id: Film ID to search for.
*/
char *searchFilmFollowID(nodeFilm head, int id)
{
    if (checkEmptyListFilm(head))
    {
        printf("No data!\n");
        return "No data!\n";
    }
    else
    {
        struct NodeFilm *p = head;
        int bufferSize = 1048576;
        char *message = (char *)malloc(bufferSize * sizeof(char));


        int a = 0;

        while (p != NULL)
        {
            if (p->data.id == id)
            {
                a++;
                char temp[4096];
                sprintf(temp, "STT: %d\n", a);
                sprintf(temp + strlen(temp), "Title: %s\n", p->data.title);
                sprintf(temp + strlen(temp), "Show time: %ld\n", p->data.show_time);
                sprintf(temp + strlen(temp), "Description: %s\n\n", p->data.description);
                strcat(message, temp);
            }
            p = p->next;
        }

        return message;
    }
}

/**
 * @function displayFilm: Display information about all films in the list.
 * 
*/
char *displayFilm(nodeFilm head)
{
    if (checkEmptyListFilm(head))
    {
        printf("Empty list\n");
        return "Empty list\n";
    }
    else
    {
        struct NodeFilm *p = head;
        int bufferSize = 1048576; 
        char *message = (char *)malloc(bufferSize * sizeof(char));

        strcpy(message, "STT\tTitle\tShow time\tDescription\n");

        while (p != NULL)
        {
            char temp[4096]; 
            sprintf(temp, "%ld\t%s\t%ld\t%s\n", p->data.id, p->data.title, p->data.show_time, p->data.description);
            strcat(message, temp);

            p = p->next;
        }

        return message;
    }
}