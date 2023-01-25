#pragma once

#define NULL ((void *)0)

typedef struct listnode_t {
    struct listnode_t *next;
    void *data;
} ListNode;

/**
 * Linked List
 * @attention Do **NOT** deallocate data in a list
 * @param length Size of the list (Starts at one)
 */
typedef struct list_t {
    int length;
    ListNode *first_node;
    ListNode *last_node;
} List;

/**
 * Create a new list
 */
List *list_create();

/**
 * Destroy a list
 * @attention This will deallocate all data contained in the list
 */
void list_destroy(List *l);

/**
 * Destroy a list, keeping data contained allocated
 */
void list_free(List *l);

/**
 * Get the element at the specified index
 * @param index Index of element (Starts at zero)
 * @returns If not null, a pointer to the data
 */
void *list_get(List *l, int index);

/**
 * Appends data to end of list
 * @attention Do **NOT** deallocate data in a list, for more info see <List>
 * @param data Data to store in list
 * @returns Index of new element in list
 */
int list_append(List *l, void *data);

/**
 * Removes element at specified index, does not deallocate contained data
 * @attention This does **NOT** deallocate data contained in element
 * @param index Index of node to remove
 * @returns If not null, a pointer to the data contained in element
 */
void *list_pop(List *l, int index);

/**
 * Removes element at specified index
 * @param index Index of element to delete
 * @returns Zero if successful
 */
int list_drop(List *l, int index);
