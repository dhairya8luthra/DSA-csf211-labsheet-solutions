#include "linkedlist.h"

struct node* getnext(struct node* curr, struct linkedList* list) {
    if (curr -> next == NULL) {
        return list -> head;
    } else {
        return curr -> next;
    }
}

struct node* find(struct linkedList* list,int val) {
    struct node*  head = list -> head;
    while (head != NULL)
    {
        if (head -> data == val) {
            return head;
        }
        head = head -> next;
    }
    return NULL;
    
}

int solve(struct linkedList* list,int a,int b) {
    struct node* pa = find(list,a), *pb = find(list,b);      
    while (1)
    {
        if (pa == pb){
            return pa -> data;
        }
        pa = getnext(getnext(pa,list),list);
        pb = getnext(pb,list);
        
    }
    

}
int main(int argc, char const *argv[])
{
    int n,a,b;
    scanf("%d %d %d",&n,&a ,&b);
    int val[n];
     for (size_t i = 0; i < n; i++)
    {
        val[i] = i + 1;
    }

    struct linkedList* list = init(val,n);
    printf("%d",solve(list,a,b));
   
    return 0;
}