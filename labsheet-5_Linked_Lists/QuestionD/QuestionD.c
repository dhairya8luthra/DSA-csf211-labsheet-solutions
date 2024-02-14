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
}

void RotateLinkedList(struct node **head, struct node **end)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        // Empty list or list with only one node, no rotation needed
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;

    // Find the new end of the list
    struct node *newEnd = *head;
    while (newEnd->next != NULL)
    {
        newEnd = newEnd->next;
    }

    // Update the end pointer
    *end = newEnd;

    temp->next = NULL;
    (*end)->next = temp;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    // creating a linked list
    struct node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        AddNode(val, &head);
    }
    // approach rotate the linked list by setting the head to head->next and traverse and get end pointer and update it from null to element rotated
    struct node *end = head;
    while (end->next != NULL)
    {
        end = end->next;
    }

    // if k is more than length than find mod of k with length of the linked list to reduce loop
    if (k > n)
    {
        k = k % n;
    }
    // now rotating the linked list k times;
    for (int i = 0; i < k; i++)
    {
        RotateLinkedList(&head, &end);
    }
    display(head);
    return 0;
}