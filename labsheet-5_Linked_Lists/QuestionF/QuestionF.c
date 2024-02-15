#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void removeDuplicates(struct node **head)

{
    // approach if the curr->next->data is same as curr->data remove curr by changing prev->next to curr->next
    struct node *curr = *head;
    struct node *prev = NULL;

    while (curr != NULL)
    {
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            // Duplicate found, remove node
            if (prev == NULL)
            {
                // Removing head node
                *head = curr->next;
                printf("Removed %d\n", curr->data);
                curr = *head;
            }
            else
            {
                prev->next = curr->next;
                printf("Removed %d\n", curr->data);
                curr = prev->next;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}
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

void printList(struct node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    // taking input
    int n;
    scanf("%d", &n);
    // make the linked list
    struct node *head = NULL; // Initialize head to NULL
    for (int i = 1; i <= n; i++)
    {
        int val;
        scanf("%d", &val);
        AddNode(val, &head);
    }

    removeDuplicates(&head);

    printList(head);

    return 0;
}