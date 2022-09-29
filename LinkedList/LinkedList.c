#include "LinkedList.h"

#include <stdlib.h>

typedef struct ListNode_st
{
    void* item;
    struct ListNode* next;
}ListNode_st;

typedef struct LinkedList_st
{
    uint16_t size;
    LinkedNode head;
    LinkedNode current;
}LinkedList_st;

// -- construct & de-construct
LinkedList LinkedList_create(void)
{
    LinkedList newList = calloc(sizeof(LinkedList),1);
    return newList;
}

ListReturnCode LinkedList_destroy(LinkedList self)
{
    if(self==NULL)
    {
        return LINKEDLIST_NOT_FOUND;
    }

    free(self);
    return LINKEDLIST_OK;
}

ListReturnCode LinkedList_push(LinkedList self, void* item)
{
    return LINKEDLIST_NOT_FOUND;
}
void* LinkedList_pull(LinkedList self)
{
    
}
ListReturnCode LinkedList_containsItem(LinkedList self, void* item)
{
    return LINKEDLIST_NOT_FOUND;
}
ListReturnCode LinkedList_removeItem(LinkedList self, void* item)
{
    return LINKEDLIST_NOT_FOUND;
}
void* LinkedList_peekItemByIndex(LinkedList self, uint16_t index)
{
    
}
uint16_t LinkedList_length(LinkedList self)
{
    if(self==NULL) return LINKEDLIST_NOT_FOUND;
    else return self->size;
}
void LinkedList_clear(LinkedList self)
{
    
}
LinkedNode LinkedList_getIterator(LinkedList self)
{
    return LINKEDLIST_NOT_FOUND;
}
void* LinkedList_itteratorNext(LinkedList self, LinkedNode iterator)
{
    
}