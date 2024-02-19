#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createLinkedList(int val, struct node **head)
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

void AddtoLL(int val, struct node *pointer)
{
    if (pointer == NULL)
    {
        return;
    }
    else
    {
        pointer->data += val;
        if (pointer->data > 9)
        {
            pointer->data %= 10;
            if (pointer->next == NULL)
            {
                createLinkedList(1, &pointer->next);
            }
            else
            {
                pointer->next->data++;
            }
        }
    }
    return;
}

void diplay(struct node **head)
{
    struct node *ptr = *head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    int n, m;
    scanf("%d %d", &n, &m);
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int small = n <= m ? n : m;
    int big = n > m ? n : m;
    int *smallArr = n <= m ? arr1 : arr2;
    int *bigArr = n > m ? arr1 : arr2;
    // creating linked list
    for (int i = 0; i < big; i++)
    {
        createLinkedList(bigArr[i], &head);
    }
    struct node *pointer = head;
    for (int i = 0; i < n + m && pointer != NULL; i++)
    {
        if (i < small)
        {
            AddtoLL(smallArr[i], pointer);
        }
        pointer = pointer->next;
    }
    diplay(&head);
}