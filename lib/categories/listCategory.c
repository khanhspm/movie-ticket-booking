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
int checkEmptyListCategory(nodeCategory list)
{
    return list == NULL;
}

/**
 * @function addNewNodeCategory: add a new node to the list when list is empty
 *
 * @param head: head of list
 * @param x: node to add
 */
void addNewNodeCategory(nodeCategory *head, category x)
{
    struct NodeCategory *p = (struct NodeCategory *)malloc(sizeof(struct NodeCategory));
    p->data = x;
    p->next = NULL;
    if (checkEmptyListCategory(*head))
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
void addNodeCategory(nodeCategory *head, category x)
{
    if (checkEmptyListCategory(*head))
    {
        addNewNodeCategory(head, x);
    }
    else
    {
        struct NodeCategory *a = *head;
        while (a->next != NULL)
        {
            a = a->next;
        }
        struct NodeCategory *p = (struct NodeCategory *)malloc(sizeof(struct NodeCategory));
        p->data = x;
        p->next = NULL;
        a->next = p;
    }
}

int searchCategory(nodeCategory head, char name[])
{
    if (checkEmptyListCategory(head))
    {
        return 0;
    }
    else
    {
        struct NodeCategory *p = head;
        while (p != NULL)
        {
            if (strcmp(name, p->data.name) == 0)
            {
                return p->data.id;
            }
            p = p->next;
        }
    }
    return -1;
}

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
        int bufferSize = 2048; // Tùy thuộc vào yêu cầu của bạn
        char *message = (char *)malloc(bufferSize * sizeof(char));



        // Khởi tạo chuỗi message
        strcpy(message, "");

        // Duyệt danh sách và thêm thông tin từ mỗi node vào chuỗi message

        while (p != NULL)
        {
            // Nối thông tin từ mỗi node vào chuỗi message
            char temp[512]; // Kích thước tùy thuộc vào yêu cầu của bạn
            sprintf(temp, "%ld %s\n", p->data.id, p->data.name);
            strcat(message, temp);

            // Chuyển đến node tiếp theo
            p = p->next;
        }

        return message;
    }
}

