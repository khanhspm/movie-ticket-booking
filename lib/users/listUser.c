#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "user.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyList(node list){
	return list == NULL;
}

/**
 * @function addNewNode: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNode(node* head, user x){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    if(checkEmptyList(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNode(node* head, user x){
    if(checkEmptyList(*head)){
        addNewNode(head, x);
    }else{
        struct Node* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}

/**
 * @function changeNodePassword: change the node's password
 * 
 * @param head : the head node
 * @param username : the username 
 * @param newPassword : the new password to be added
 */
void changeNodePassword(node* head, char username[], char newPassword[]){
    if(checkEmptyList(*head)){
        printf("Empty list\n");
    } else {
        struct Node* p = *head;
        while(p != NULL){
            if(strcmp(p->data.username, username) == 0){
                printf("Trước khi thay đổi: %s\n", p->data.password);
                strcpy(p->data.password, newPassword);
                printf("Sau khi thay đổi: %s\n", p->data.password);
            }
            p = p->next;
        }
    }
}
