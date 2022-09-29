#include "LinkedList.h"
#include "ListNode.h"

#include <stdlib.h>

typedef struct LinkedList_st
{
    uint16_t size;
    LinkedNode head;
}LinkedList_st;

// -- construct & de-construct
LinkedList LinkedList_create(void)
{
    LinkedList newList = calloc(sizeof(LinkedList),1);
    newList->head = calloc(sizeof(LinkedNode),1);
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
    LinkedNode newNode = malloc(sizeof(LinkedNode));
    newNode->item=item;
    newNode->next = self->head;
    self->head=newNode;
    self->size++;
    return LINKEDLIST_OK;
}
void* LinkedList_pull(LinkedList self)
{
    //save reference to first link
    LinkedNode tempLink = self->head;
    //mark next to first link as first 
    self->head = self->head->next;
    self->size--;
    //return the item link
    return tempLink->item;
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
    return LINKEDLIST_NOT_FOUND;
}
uint16_t LinkedList_length(LinkedList self)
{
    if(self==NULL) return LINKEDLIST_NOT_FOUND;
    else return self->size;
}
void LinkedList_clear(LinkedList self)
{
    self->size=0;
    free(self->head);
}
LinkedNode LinkedList_getIterator(LinkedList self)
{
    return LINKEDLIST_NOT_FOUND;
}
void* LinkedList_itteratorNext(LinkedList self, LinkedNode iterator)
{
    
}