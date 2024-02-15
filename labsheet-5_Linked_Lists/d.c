#include "linkedlist.h"

void rotate(struct linkedList* list) {
    struct node* head = list -> head;
    insert(list,list->head->data);
    list -> head = list -> head -> next;
    free(head);
}

int main(int argc, char const *argv[])
{
        int n,r;
    scanf("%d %d",&n, &r);
    int val[n];
     for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }

    struct linkedList* list = init(val,n);
    for (size_t i = 0; i < r; i++)
    {
        rotate(list);
    }
    
    printList(list);
    return 0;
}
