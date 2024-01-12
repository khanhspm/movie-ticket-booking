#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "category.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListCategory(nodeCategory list){
	return list == NULL;
}

/**
 * @function addNewNodeCategory: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeCategory(nodeCategory* head, category x){
    struct NodeCategory* p = (struct NodeCategory*)malloc(sizeof(struct NodeCategory));
    p->data = x;
    p->next = NULL;
    if(checkEmptyListCategory(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeCategory(nodeCategory* head, category x){
    if(checkEmptyListCategory(*head)){
        addNewNodeCategory(head, x);
    }else{
        struct NodeCategory* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct NodeCategory* p = (struct NodeCategory*)malloc(sizeof(struct NodeCategory));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}

/**
 * @function searchCategory: Search for a category by name in the list.
 * 
 * @param head: Head of the list.
 * @param name: Name of the category to search for.
 * 
 * @return: ID of the category if found, -1 otherwise.
*/
int searchCategory(nodeCategory head, char name[]){
    if(checkEmptyListCategory(head)){
        return 0;
    }else{
        struct NodeCategory* p = head;
        while(p != NULL){
            if(strcmp(name, p->data.name) == 0){
                return p->data.id;
            }
            p = p->next;
        }
    }
    return -1;
}


/**
 * @function displayCategory: Display information about categories in the list.
 * 
 * @param head: Head of the list.
*/
char *displayCategory(nodeCategory head)
{
    if (checkEmptyListCategory(head))
    {
        printf("Empty list\n");
        return "Empty list\n";
    }
    else
    {
        struct NodeCategory *p = head;
        int bufferSize = 2048; // 
        char *message = (char *)malloc(bufferSize * sizeof(char));

        strcpy(message, "");

        while (p != NULL)
        {
            char temp[512]; 
            sprintf(temp, "%ld %s\n", p->data.id, p->data.name);
            strcat(message, temp);
                     
            p = p->next;
        }

        return message;
    }
}