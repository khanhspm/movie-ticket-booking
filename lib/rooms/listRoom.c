#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "room.h"

/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListRoom(nodeRoom list){
	return list == NULL;
}

/**
 * @function addNewNodeRoom: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodeRoom(nodeRoom* head, room x){
    struct NodeRoom* p = (struct NodeRoom*)malloc(sizeof(struct NodeRoom));
    p->data = x;
    p->next = NULL;
    if(checkEmptyListRoom(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodeRoom(nodeRoom* head, room x){
    if(checkEmptyListRoom(*head)){
        addNewNodeRoom(head, x);
    }else{
        struct NodeRoom* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct NodeRoom* p = (struct NodeRoom*)malloc(sizeof(struct NodeRoom));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}

char* searchRoomFromID(nodeRoom* head, unsignedlong id){
    struct NodeRoom* a = *head;
    while(a->next != NULL){
        if(a->data.id == id){
            return a->data.name
        }
        a = a->next;
    }

    return NULL;
}

unsigned long checkRoomStatus(nodeRoom* head, unsigned long id){
    struct NodeRoom* a = *head;
    while(a->next != NULL){
        if(a->data.id = id){
            return a->data.status;
        }
        a = a->next;
    }

    return NULL;
}

unsigned long *searchRoomFromCinemaID(nodeRoom* head, unsigned long id){
    unsigned long arr[1000];
    int i = 0;
    struct NodeRoom* a = *head;
    while(a->next != NULL){
        if(a->data.cinema_id == id){
            arr[i] = a->data.id;
            i++;
        }
        a = a->next;
    }
    return arr;
}
