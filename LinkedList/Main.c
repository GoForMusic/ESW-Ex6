#include <stdio.h>

#include "LinkedList.h"

int main()
{
    LinkedList x = LinkedList_create();
    printf("%d",LinkedList_length(x));
    LinkedList_destroy(x);
    
    return 0;
}
