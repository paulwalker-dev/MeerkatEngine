#include "List.h"
#include <stdio.h>
#include <stdlib.h>

List *list_create()
{
    List *l;

    l = malloc(sizeof(List));
    l->length = 0;
    l->first_node = NULL;
    l->last_node = NULL;

    return l;
}

void list_destroy(List *l)
{
    while (l->length)
        list_drop(l, 0);
    free(l);
}

void list_free(List *l)
{
    while (l->length)
        list_pop(l, 0);
    free(l);
}

void list_cleanup(List *l, void (* destroy)(void *))
{
    void *o;

    while (l->length) {
        o = list_pop(l, 0);
        if (o != NULL)
            destroy(o);
    }
    list_destroy(l);
}

ListNode *list_get_node(List *l, int index)
{
    ListNode *node;
    int i;

    i = 0;
    node = l->first_node;
    while (node != NULL) {
        if (index == i++)
            return node;
        node = node->next;
    }

    return NULL;
}

void *list_get(List *l, int index)
{
    ListNode *node;

    if ((node = list_get_node(l, index)) == NULL)
        return NULL;

    return node->data;
}

int list_append(List *l, void *data)
{
    ListNode *prev_last;
    ListNode *new_node;

    new_node = malloc(sizeof(ListNode));
    new_node->next = NULL;
    new_node->data = data;

    if (l->first_node != NULL) {
        prev_last = l->last_node;
        prev_last->next = new_node;
    } else
        l->first_node = new_node;
    l->last_node = new_node;

    return l->length++;
}

void *list_pop(List *l, int index)
{
    ListNode *node;
    ListNode *prev_node;
    ListNode *next_node;
    void *data;

    if (index == 0) {
        prev_node = NULL;
        node = l->first_node;
    } else {
        prev_node = list_get_node(l, index-1);
        if (prev_node == NULL)
            return NULL;
        node = prev_node->next;
    }

    if (node == NULL)
        return NULL;

    next_node = node->next;
    data = node->data;
    free(node);
    if (prev_node == NULL)
        l->first_node = next_node;
    else
        prev_node->next = next_node;

    l->length--;

    return data;
}

int list_drop(List *l, int index)
{
    void *data;

    data = list_pop(l, index);
    if (data == NULL)
        return 1;

    free(data);
    return 0;
}
