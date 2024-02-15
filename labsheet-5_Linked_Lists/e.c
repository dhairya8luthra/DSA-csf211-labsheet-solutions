#include "linkedlist.h"

struct node* getnext(struct node* curr, struct linkedList* list) {
    if (curr -> next == NULL) {
        return list -> head;
    } else {
        return curr -> next;
    }
}

struct node* deletenode(struct node* curr, struct node* prev, struct linkedList* list) {
    struct node* next = getnext(curr,list);
    if(prev == NULL){
        list -> head = next;
    } else {
    prev -> next = next;
    }
    
    free(curr);
    return next;
    
}

void solve(struct linkedList* list, int k, int n) {
    
 struct node* curr = list -> head,*prev = NULL;

    for (int i = 0; i < n - 1;i++) {
        for(int j = 1; j < k ; j++) {
            prev = curr;
            curr = getnext(curr,list);
       }
        curr = deletenode(curr,prev, list);
    }
    printf("%d\n",curr->data);
    
}
int main(int argc, char const *argv[])
{
    int n,k;
    scanf("%d %d",&n,&k);
    int val[n];
     for (size_t i = 0; i < n; i++)
    {
        val[i] = i + 1;
    }

    struct linkedList* list = init(val,n);
   
    solve(list,k,n);
     //printList(list);
    return 0;
}