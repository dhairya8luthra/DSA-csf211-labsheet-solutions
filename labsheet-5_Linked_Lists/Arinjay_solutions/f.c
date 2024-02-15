#include "linkedlist.h"


struct node* deletenode(struct node* curr, struct node* prev, struct linkedList* list) {
    struct node* next = curr -> next;
    if(prev == NULL){
        list -> head = next;
    } else {
    prev -> next = next;
    }
    
    free(curr);
    return next;
    
}

void solve(struct linkedList* list) {

 struct node* curr = list -> head -> next, *prev = list -> head;

 while (curr != NULL)
 {
    if (curr -> data == prev -> data){
       curr = deletenode(curr,prev,list);
    } else {
        prev = curr;
        curr = curr -> next;
    }
 }
 
 


    
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
   
    solve(list);
    printList(list);
    return 0;
}