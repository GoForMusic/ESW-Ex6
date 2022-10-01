/**
 *  \file 
 *  \brief LinkedList source file
 *  \author Adrian-Cristian Militaru learning for ESW
 *  \version 1.0.0 
 *
 *  \defgroup LinkedList Linked List
 * 
 */

#include "LinkedList.h"
#include "ListNode.h"

#include <stdlib.h>

// Abstract Data Type (ADT)
typedef struct LinkedList_st
{
    uint16_t size;
    LinkedNode head;
}LinkedList_st;

/********************************************//*
* \ingrup linked_list_init_ADT
* \brief Create ADT for the instance "Object like"
* \return pointer of the object
 */
LinkedList LinkedList_create(void)
{
    LinkedList self = calloc(sizeof(LinkedList),1);
    
    if(self == NULL)
    {
        return 0;
    }
    
    return self;
}

/********************************************//*
* \ingrup linked_list_init_ADT
* \brief Destroy the object and free the memory
* \return Status code for NOT found or OK
*
* ????? TODO: ASKING IB
 */
ListReturnCode LinkedList_destroy(LinkedList self)
{
    if(self==NULL) return LINKEDLIST_NOT_FOUND;

    if(self->head!=NULL)
    {
        while(LinkedList_length(self)!=0)
        {
            LinkedList_pull(self);
        }
        free(self->head);
        free(self->size);
        free(self);
    }
    
    return LINKEDLIST_OK;
}

/********************************************//*
* \ingrup linked_list_init_ADT
* \brief add a new NODE on LEFT and push the others to the RIGHT
*
*   The list get the item is creating a tempNODE and get the HEAD from where will be push to the next position
*   
* \param[in] list pointer to list instance to work on.
* \param[in] item pointer to item that will be pushed.
* \return OK if the item have been pushed
 */
ListReturnCode LinkedList_push(LinkedList self, void* item)
{
    LinkedNode newNode = calloc(sizeof(LinkedNode),1);
    newNode->item=item;
    newNode->next = self->head;
    self->head=newNode;
    self->size++;
    return LINKEDLIST_OK;
}

/********************************************//*
* \ingrup linked_list_init_ADT
* \brief remove the first NODE on LEFT and push the others to the LEFT positions
*
*   The list will remove an item from LEFT and returning the item before deletion.
*   
* \param[in] list pointer to list instance to work on.
* \return return the item on the specific NODE
 */
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

/********************************************//*
* TODO: IMPLEMENT THIS FUNCTION
 */
ListReturnCode LinkedList_containsItem(LinkedList self, void* item)
{
    return LINKEDLIST_NOT_FOUND;
}

/********************************************//*
* \ingrup linked_list_init_ADT
* \brief remove the item from the list
*
*   The specific item wil lbe removed from the list
*   
* \param[in] list pointer to list instance to work on.
* \param[in] pointer to the specific item that will be removed
* \return return status code
 */
ListReturnCode LinkedList_removeItem(LinkedList self, void* item)
{
    //store temp of the head
    LinkedNode temp = self->head;
    LinkedNode prev = self->head;
 
    // If head node itself holds the item to be deleted
    if (temp != NULL && temp->item == item) {
        self->head = temp->next; // Changed head
        free(temp); // free old head
        return LINKEDLIST_OK;
    }
 
    // Search for the item to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->item != item) {
        prev = temp;
        temp = temp->next;
    }
 
    // If item was not present in linked list
    if (temp == NULL)
        return LINKEDLIST_NOT_FOUND;
 
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    free(prev);
    return LINKEDLIST_OK;
}

/********************************************//*
* \ingrup linked_list_init_ADT
* \brief return an item on the index X
* \param[in] list pointer to list instance to work on.
* \param[in] the index
* \return return the item on the specific NODE
 */
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

/********************************************//*
* \ingrup linked_list_init_ADT
* \brief return the size of the linkedlist
*
*   Will return the size of the linked list
*   
* \param[in] list pointer to list instance to work on.
* \return return the item on the specific NODE
 */
uint16_t LinkedList_length(LinkedList self)
{
    if(self == NULL)
    {
        return LINKEDLIST_EMPTY;
    }
    return self->size;
}

/********************************************//*
* TODO: WORK ON THIS FUNCTION
 */
void LinkedList_clear(LinkedList self)
{
    self->size=0;
    free(self->head);
}

/********************************************//*
* TODO: IMPLEMENT THIS FUNCTION
 */
LinkedNode LinkedList_getIterator(LinkedList self)
{
    return LINKEDLIST_NOT_FOUND;
}

/********************************************//*
* TODO: IMPLEMENT THIS FUNCTION
 */
void* LinkedList_itteratorNext(LinkedList self, LinkedNode iterator)
{
    return LINKEDLIST_NOT_FOUND;
}