#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    int index;
    struct node *next;
};
void add_index(int a, int n, int ind, struct node **num)
{

    struct node *curr;
    curr = (struct node *)malloc(sizeof(struct node));
    if (num[a] == NULL)
    {
        curr->data = a;
        curr->index = ind;
        curr->next = NULL;
        num[a] = curr;
    }
    else
    {
        curr = num[a];
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a;
        temp->index = ind;
        temp->next = NULL;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void count_sort(int a[], int n)
{
    int count[10] = {0};
    int b[n];
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        b[--count[a[i]]] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];

    struct node **num;
    num = (struct node **)malloc(sizeof(struct node *) * 10);
    for (int i = 0; i < 10; i++)
    {

        num[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        add_index(a[i], n, i, num);
    }
    count_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        if (num[i] != NULL)
        {
            struct node *cur = num[i];
            while (cur != NULL)
            {
                printf("%d ", cur->index + 1);
                cur = cur->next;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        struct node *temp = num[i];
        while (temp != NULL)
        {
            struct node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(num);
}
