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
struct node *ReverseLinkedList(struct node **head)
{
    struct node *prev = NULL;
    struct node *curr = *head;
    struct node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    // taking input
    int n;
    scanf("%d", &n);
    // make the linked list
    struct node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        AddNode(val, &head);
    }
    // reversing the linked list
    // approach: the approach is going to be simple we will have 3 pointers next,curr,and previous we basically hhave to set the next of
    // node to previous and shift curr to the next pointer
    struct node *new_head = ReverseLinkedList(&head);
    display(new_head);
    return 0;
}