#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void AddNode(int val, struct node **head)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct node *ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
void display(struct node *head)
{
    struct node *start = head;
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}
int main()
{
    // taking input
    int n, a, b;
    scanf("%d %d %d", &n, &b, &a);
    // create 2 linked list
    struct node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        AddNode(1 + i, &head);
    }
    // making both the linked lists circular
    struct node *pointer1 = head;

    // also i need to find start pointer of where to traverse from when i will be comparing  two nodes.
    struct node *pointer_a = head;
    struct node *pointer_b = head;
    while (pointer1->next != NULL)
    {
        if (pointer1->data == a)
        {
            pointer_a = pointer1;
        }
        if (pointer1->data == b)
        {
            pointer_b = pointer1;
        }
        pointer1 = pointer1->next;
    }
    pointer1->next = head;
    // now I have a circular linked lists with one having 1 - n and  now I will traverse untill I come to  the point where 2 pointer data is equal.
    while (pointer_a->data != pointer_b->data)
    {
        // go clockwise once
        printf("a reached %d\n", pointer_a->data);
        pointer_a = pointer_a->next;

        // go anticlocwise twice
        printf("b reached %d\n", pointer_b->data);
        pointer_b = pointer_b->next->next;
    }
    printf("%d", pointer_a->data);
    return 0;
}