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
    LinkedList self = calloc(sizeof(LinkedList),1);
    
    if(self == NULL)
    {
        return 0;
    }
    
    return self;
}

ListReturnCode LinkedList_destroy(LinkedList self)
{
   if(self==NULL) return LINKEDLIST_NOT_FOUND;
    if(self->head!=NULL)
    {
        while(self->head->next!=NULL)
        {
            free(self->head->next->item);
            free(self->head->next->next);
            free(self->head->next);
        }
        free(self->head);
    }
    free(self->size);
    free(self);
    
}

ListReturnCode LinkedList_push(LinkedList self, void* item)
{
    LinkedNode newNode = calloc(sizeof(LinkedNode),1);
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
    if(self==NULL) return LINKEDLIST_EMPTY;

    LinkedNode _currentNode =calloc(sizeof(LinkedNode),1);
    _currentNode=self->head;
    if(_currentNode->next==NULL) return LINKEDLIST_NOT_FOUND;

    while(_currentNode->next->item!=item)
    {
        if(_currentNode->item==NULL)
            return LINKEDLIST_NOT_FOUND;
        else
        {
            _currentNode = _currentNode->next;
        }
    }

    LinkedNode to_delete = _currentNode->next;
    _currentNode->next=_currentNode->next->next;
    self->size--;
    free(to_delete);
    return LINKEDLIST_FOUND;
}
void* LinkedList_peekItemByIndex(LinkedList self, uint16_t index)
{
    LinkedNode _current = self->head;
    int count = 0;
    while (_current != NULL) {
        if (count == index)
            return (_current->item);
        count++;
        _current = _current->next;
    }
    
    return LINKEDLIST_NOT_FOUND;
}
uint16_t LinkedList_length(LinkedList self)
{
    if(self == NULL)
    {
        return LINKEDLIST_EMPTY;
    }
    return self->size;
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