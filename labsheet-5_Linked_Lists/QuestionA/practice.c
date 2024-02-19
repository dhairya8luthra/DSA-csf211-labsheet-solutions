#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createLL(int val, struct node **head)
{
    //
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
    pointer->data += val;
    if (pointer->data > 9)
    {
        pointer->data %= 10;
        if (pointer->next == NULL)
        {
            createLL(1, &pointer->next);
        }
        else
        {
            pointer->next->data++;
        }
    }
}
void display(struct node **head)
{
    struct node *pointer = *head;
    while (pointer != NULL)
    {
        printf("%d ", pointer->data);
        pointer = pointer->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    int n, m;
    scanf("%d %d", &n, &m);
    int arr1[n];
    int arr2[m];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    // finding big and small arrays
    int big = n > m ? n : m;
    int small = n <= m ? n : m;
    int *bigArr = n > m ? arr1 : arr2;
    int *smallArr = n <= m ? arr1 : arr2;
    // creating the linked list
    for (int i = 0; i < big; i++)
    {
        createLL(bigArr[i], &head);
    }
    // Adding the small array to big array
    struct node *pointer = head;
    for (int i = 0; i < big + 2 && pointer != NULL; i++)
    {
        if (i < small)
        {
            AddtoLL(smallArr[i], pointer);
        }
        pointer = pointer->next;
    }
    // displaying the list
    display(&head);
    return 0;
}