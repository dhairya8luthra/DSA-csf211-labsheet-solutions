#include "linkedlist.h"

int main(int argc, char const *argv[])
{
    int a,b;
    scanf("%d %d",&a,&b);
    struct linkedList* num1 = empty_init(), *num2 = empty_init();
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


    struct node* left = num1->head;
    struct node* right = num2 -> head;
    val  = 0;
    while (left != NULL || right != NULL) {
        if (left != NULL && right != NULL) {
            if (left->data < right->data) {
                val = left-> data;
                left = left -> next;
            } else {
                val = right -> data;
                right = right -> next;
            }
        } else if (left != NULL)
        {
           val = left -> data;
           left = left -> next;
        } else {
            val = right -> data;
            right = right -> next;
        }
        printf("%d ", val);
        
    }
    return 0;
}
