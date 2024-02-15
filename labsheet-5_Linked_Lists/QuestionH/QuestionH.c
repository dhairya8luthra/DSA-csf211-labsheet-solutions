#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert an element at the front of the list
void insertFront(struct Node **head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// Function to insert an element at the back of the list
void insertBack(struct Node **head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Function to delete an element from the front of the list
void deleteFront(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    free(temp);
}

// Function to delete an element from the back of the list
void deleteBack(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    if (last->prev != NULL)
    {
        last->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }

    free(last);
}

// Function to print the list forward
void printForward(struct Node *head)
{
    if (head == NULL)
    {
        printf("-1\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to print the list backward
void printBackward(struct Node *head)
{
    if (head == NULL)
    {
        printf("-1\n");
        return;
    }

    while (head->next != NULL)
    {
        head = head->next;
    }

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    // Initialize the doubly linked list with the given elements
    struct Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        insertBack(&head, val);
    }

    // Process the operations
    for (int i = 0; i < q; i++)
    {
        int operation, val;
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            scanf("%d", &val);
            insertFront(&head, val);
            break;
        case 2:
            scanf("%d", &val);
            insertBack(&head, val);
            break;
        case 3:
            deleteFront(&head);
            break;
        case 4:
            deleteBack(&head);
            break;
        case 5:
            printForward(head);
            break;
        case 6:
            printBackward(head);
            break;
        }
    }

    return 0;
}
