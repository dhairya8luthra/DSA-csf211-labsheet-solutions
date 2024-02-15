#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert a song at the end of the playlist
void insertEnd(struct Node **head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->prev = NULL;
    }
    else
    {
        struct Node *last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
}

// Function to delete the now playing song and move to the next song
void deleteNowPlaying(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *current = *head;
    *head = current->next;

    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    free(current);
}

// Function to move to the next song
void nextSong(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *current = *head;

    if (current->next != NULL)
    {
        *head = current->next;
        (*head)->prev = NULL;

        current->next = NULL;
        insertEnd(head, current->data);
        free(current);
    }
}

// Function to move to the previous song
void previousSong(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *current = *head;

    if (current->prev != NULL)
    {
        struct Node *last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = current;
        current->prev = last;
        *head = current->next;

        current->next = NULL;
        current->prev = NULL;
    }
}

// Function to print the now playing song
void printNowPlaying(struct Node *head)
{
    if (head == NULL)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", head->data);
    }
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    // Initialize the doubly linked list with the initial playlist
    struct Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    // Process the operations
    for (int i = 0; i < q; i++)
    {
        int operation;
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            printNowPlaying(head);
            break;
        case 2:
        {
            int song;
            scanf("%d", &song);
            insertEnd(&head, song);
            break;
        }
        case 3:
        {
            int song;
            scanf("%d", &song);
            insertEnd(&head, song);
            deleteNowPlaying(&head);
            break;
        }
        case 4:
            nextSong(&head);
            break;
        case 5:
            previousSong(&head);
            break;
        case 6:
            deleteNowPlaying(&head);
            break;
        }
    }

    // Free the allocated memory
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
