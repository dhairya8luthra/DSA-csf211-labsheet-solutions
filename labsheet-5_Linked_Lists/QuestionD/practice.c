#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} void AddNode(int val, struct node **head)
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
        struct node *pointer = *head;
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
        }
        pointer->next = new_node;
    }
}
void RotateLinkedList(struct node **head)
{
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if (k > n)
    {
        k = k % n;
    }
    struct node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        AddNode(val, &head);
    }
    for (int i = 0; i < k; i++)
    {
        RotateLinkedList(&head);
    }
}