#include "linkedlist.h"

void reverseList(struct linkedList* list) {
    struct node* curr= list -> head,*prev , *next;

    if (curr == NULL)
        return;
     if (curr -> next == NULL)
        return;

    next = curr;
   
    prev = NULL;

    while (next != NULL)
    {
        curr = next;
        next = curr -> next;       
        curr -> next = prev;
        prev = curr;
        
    }

    list->head = prev;
    
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int val[n];
     for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }

    struct linkedList* list = init(val,n);
    reverseList(list);
    printList(list);
    return 0;
}