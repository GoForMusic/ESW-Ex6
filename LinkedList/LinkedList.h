#pragma once

#include <stdint.h>
/**
 \ingroup linked_list_return
 Return codes from linked list functions
 */
typedef enum
{
    LINKEDLIST_OK,
    LINKEDLIST_EMPTY,
    LINKEDLIST_NOT_FOUND,
    LINKEDLIST_FULL,
    LINKEDLIST_FOUND
}ListReturnCode;

// Abstract Data Type (ADT)
typedef struct LinkedList_st* LinkedList;
typedef struct ListNode_st* LinkedNode;

// -- construct & de-construct
LinkedList LinkedList_create(void);
ListReturnCode LinkedList_destroy(LinkedList self);


ListReturnCode LinkedList_push(LinkedList self, void* item);
void* LinkedList_pull(LinkedList self);
ListReturnCode LinkedList_containsItem(LinkedList self, void* item);
ListReturnCode LinkedList_removeItem(LinkedList self, void* item);
void* LinkedList_peekItemByIndex(LinkedList self, uint16_t index);
uint16_t LinkedList_length(LinkedList self);
void LinkedList_clear(LinkedList self);
LinkedNode LinkedList_getIterator(LinkedList self);
void* LinkedList_itteratorNext(LinkedList self, LinkedNode iterator);