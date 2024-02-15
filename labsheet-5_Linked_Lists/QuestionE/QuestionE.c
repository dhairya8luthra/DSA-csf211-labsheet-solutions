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

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    // making a circular linked list
    struct node *head = NULL; // Initialize head to NULL
    for (int i = 1; i <= n; i++)
    {
        AddNode(i, &head);
    }

    // setting last element to point to head to make circular linked list
    struct node *pointer = head;
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }
    pointer->next = head;

    // now we have a circular linked list
    // now traverse the list and remove kth node until there is only one node left.
    int no_of_elements_left = n;
    pointer = head;
    struct node *prev = NULL;
    while (no_of_elements_left != 1)
    {
        for (int i = 0; i < k - 1; i++)
        {
            prev = pointer;
            pointer = pointer->next;
        }
        printf("%d removed\n", pointer->data);
        prev->next = pointer->next;
        struct node *temp = pointer; // Save the current node for later use
        pointer = pointer->next;
        free(temp); // Free the removed node
        no_of_elements_left--;
    }
    printf("%d\n", prev->data);
}
