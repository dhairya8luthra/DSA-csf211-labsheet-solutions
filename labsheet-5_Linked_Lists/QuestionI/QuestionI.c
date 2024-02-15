#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Doubly linked list node structure
struct Node
{
    char data;
    struct Node *next;
    struct Node *prev;
};

// Function to insert a character at the end of the doubly linked list
void insertEnd(struct Node **head, char val)
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

// Function to check if the word is a palindrome
int isPalindrome(struct Node *head, int n)
{
    int i;
    struct Node *front = head, *rear = head;

    // Move rear to the end of the linked list
    for (i = 0; i < n - 1; i++)
    {
        rear = rear->next;
    }

    // Compare characters from the beginning and end
    while (front != NULL && rear != NULL)
    {
        if (front->data != rear->data)
        {
            return 0; // Not a palindrome
        }
        front = front->next;
        rear = rear->prev;
    }

    return 1; // Palindrome
}

int main()
{
    int n;
    scanf("%d", &n);

    char word[n + 1]; // +1 for the null terminator
    scanf("%s", word);

    // Initialize the doubly linked list with the characters of the word
    struct Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        insertEnd(&head, word[i]);
    }

    // Check if the word is a palindrome
    if (isPalindrome(head, n))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
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
