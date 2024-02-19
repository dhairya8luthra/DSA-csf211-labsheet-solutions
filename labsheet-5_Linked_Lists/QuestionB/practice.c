#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void AddNode(int val, struct node **head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        struct node *pointer = *head;
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
        }
        pointer->next = temp;
    }
}
void insertAfterPointer(int val, struct node *big_pointer)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = big_pointer->next;
    big_pointer->next = temp;
}
void display(struct node *head)
{
    struct node *start = head;
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->next;
    }
}
int main()
{
    struct node *head_big = NULL;
    struct node *head_small = NULL;
    // taking input
    int n, m;
    scanf("%d %d", &n, &m);
    // adding nodes to linked lists
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        AddNode(val, &head_small);
    }
    for (int i = 0; i < m; i++)
    {
        int val;
        scanf("%d", &val);
        AddNode(val, &head_big);
    }
    // setting up a zero node on big linked list
    struct node *big_pointer = head_big;
    struct node *small_pointer = head_small;
    struct node *zeronode = (struct node *)malloc(sizeof(struct node));
    zeronode->data = -10;
    zeronode->next = head_big;
    head_big = zeronode;
    for (int i = 0; i < n + m + 1; i++)
    {
        if (small_pointer == NULL)
        {
            break;
        }
        if (big_pointer->next->data >= small_pointer->data && big_pointer->data < small_pointer->data)
        {
            insertAfterPointer(small_pointer->data, big_pointer);
            big_pointer = big_pointer->next;
            small_pointer = small_pointer->next;
        }
        else
        {
            big_pointer = big_pointer->next;
        }
    }
    head_big = head_big->next;
    display(head_big);
    return 0;
}