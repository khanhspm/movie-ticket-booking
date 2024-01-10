#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "premieredTimeFilm.h"
/**
 * @function checkEmptyList: checking list of nodes is NULL
 * 
 * @param list: list of nodes to check
 * 
 * @return: empty list
*/
int checkEmptyListPremieredTimeFilm(nodePremieredTimeFilm list){
	return list == NULL;
}

/**
 * @function addNewNodePremieredTimeFilm: add a new node to the list when list is empty
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNewNodePremieredTimeFilm(nodePremieredTimeFilm* head, premieredTimeFilm x){
    struct NodePremieredTimeFilm* p = (struct NodePremieredTimeFilm*)malloc(sizeof(struct NodePremieredTimeFilm));
    p->data = x;
    p->next = NULL;
    if(checkEmptyListPremieredTimeFilm(*head)){
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 * 
 * @param head: head of list
 * @param x: node to add
*/
void addNodePremieredTimeFilm(nodePremieredTimeFilm* head, premieredTimeFilm x){
    if(checkEmptyListPremieredTimeFilm(*head)){
        addNewNodePremieredTimeFilm(head, x);
    }else{
        struct NodePremieredTimeFilm* a = *head;
        while(a->next != NULL){
            a = a->next;
        }
        struct NodePremieredTimeFilm* p = (struct NodePremieredTimeFilm*)malloc(sizeof(struct NodePremieredTimeFilm));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}

int *searchPremieredTimeFilm(nodePremieredTimeFilm head, unsigned long cinema_id_search)
{
    int* arr = (int*)malloc(sizeof(int));
    int i = 0;

    if (checkEmptyListPremieredTimeFilm(head))
    {
        return 0;
    }
    struct NodePremieredTimeFilm *a = head;
    while (a != NULL)
    {
        if (a->data.cinema_id == cinema_id_search)
        {
            arr[i] = a->data.film_id;
            i++;
        }
        a = a->next;
    }
    return arr;
}

int searchPremieredTimeFilmToPost(nodePremieredTimeFilm head, unsigned long film_id_search, unsigned long cinema_id_search, unsigned long premiered_time_id_search, char *date)
{
    int i = 0;

    if (checkEmptyListPremieredTimeFilm(head))
    {
        return 0;
    }
    struct NodePremieredTimeFilm *a = head;
    while (a != NULL)
    {
        if (a->data.film_id == film_id_search && a->data.cinema_id == cinema_id_search && a->data.premiered_time_id == premiered_time_id_search && strcmp(a->data.date, date) == 0)
        {
            i++;
        }
        a = a->next;
    }
    return i;
}

char *displayPremieredTimeFilm(nodePremieredTimeFilm head) {
    if (checkEmptyListPremieredTimeFilm == NULL) {
        printf("Empty list\n");
        return "Empty list\n";
    } else {
        struct NodePremieredTimeFilm *p = head;
        int bufferSize = 2048;
        char *message = (char *)malloc(bufferSize * sizeof(char));

        // Khởi tạo chuỗi message
        strcpy(message, "STT\tFilm ID\tPremiered Time ID\tCinema ID\n");

        // Duyệt danh sách và thêm thông tin từ mỗi node vào chuỗi message
        while (p != NULL) {
            // Nối thông tin từ mỗi node vào chuỗi message
            char temp[4096];
            sprintf(temp, "%ld\t%ld\t%ld\t%ld\n", p->data.id, p->data.film_id, p->data.premiered_time_id, p->data.cinema_id);
            strcat(message, temp);

            // Chuyển đến node tiếp theo
            p = p->next;
        }

        return message;
    }
}