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
int checkEmptyListFilm(nodeFilm list)
{
    return list == NULL;
}

/**
 * @function addNewNodeFilm: add a new node to the list when list is empty
 *
 * @param head: head of list
 * @param x: node to add
 */
void addNewNodeFilm(nodeFilm *head, film x)
{
    struct NodeFilm *p = (struct NodeFilm *)malloc(sizeof(struct NodeFilm));
    p->data = x;
    p->next = NULL;
    if (checkEmptyListFilm(*head))
    {
        *head = p;
    }
}

/**
 * @function addNode: add a node to the list
 *
 * @param head: head of list
 * @param x: node to add
 */
void addNodeFilm(nodeFilm *head, film x)
{
    if (checkEmptyListFilm(*head))
    {
        addNewNodeFilm(head, x);
    }
    else
    {
        struct NodeFilm *a = *head;
        while (a->next != NULL)
        {
            a = a->next;
        }
        struct NodeFilm *p = (struct NodeFilm *)malloc(sizeof(struct NodeFilm));
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
int searchTitle(nodeFilm head, char title[], nodeFilm *addf)
{
    int a = 0;
    if (checkEmptyListFilm(head))
    {
        printf("No data!\n");
        return -1;
    }
    else
    {
        struct NodeFilm *p = head;
        while (p != NULL)
        {
            if (strcmp(title, p->data.title) == 0)
            {
                a++;
                addNodeFilm(addf, p->data);
            }
            p = p->next;
        }
    }
    return a;
}

char *searchFilmFollowCategoryID(nodeFilm head, int category_id)
{
    if (checkEmptyListFilm(head))
    {
        printf("No data!\n");
        return "No data!\n";
    }
    else
    {
        // Đặt kích thước cho chuỗi message
        struct NodeFilm *p = head;
        int bufferSize = 1048576; // Tùy thuộc vào yêu cầu của bạn
        char *message = (char *)malloc(bufferSize * sizeof(char));
        // Duyệt danh sách và thêm thông tin từ mỗi node vào chuỗi message

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
            // Chuyển đến node tiếp theo
            p = p->next;
        }

        return message;
    }
}
