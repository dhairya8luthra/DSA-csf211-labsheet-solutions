#include "linkedlist.h"

void add(struct linkedList* num1, struct linkedList* num2, struct linkedList* ans) {
    struct node* a = num1->head, *b = num2 -> head;
    int carry = 0;
    while(a != NULL || b != NULL || carry != 0) {
        int sum = 0;
        sum += carry;
        carry = 0;
        if (a != NULL) {
            sum += a->data;
        }
        if (b != NULL) {
            sum += b -> data;
        }
        if (a != NULL) {
            a = a -> next;
        }
        if (b != NULL) {
            b = b -> next;
        }
        insert(ans,sum%10);
        carry = sum / 10;
    }
}

int main(int argc, char const *argv[])
{
    
    int a,b;
    scanf("%d %d",&a,&b);
    struct linkedList* num1 = empty_init(), *num2 = empty_init(), *ans= empty_init();
    int val;
    for (size_t i = 0; i < a; i++)
    {
        scanf("%d", &val);
        insert(num1,val);
    }
    for (size_t i = 0; i < b; i++)
    {
        scanf("%d", &val);
        insert(num2,val);
    }

    add(num1,num2,ans);
    printList(ans);
    return 0;
}
