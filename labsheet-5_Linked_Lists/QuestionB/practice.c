#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void AddNode(int val, struct node **head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = val;
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
void insertAfterPointer(int val, struct node *pointer)
{
    if (pointer == NULL)
    {
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = pointer->next;
    pointer->next = temp;
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
    int n, m;
    scanf("%d %d", &n, &m);
    // declaring two heads
    struct node *head_big = NULL;
    struct node *head_small = NULL;
    // creating two linked lists
    // smaller one
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        AddNode(val, &head_small);
    }
    for (int i = 0; i < m; i++)
    {
        int val;
        scanf("%d", &val);
        AddNode(val, &head_big);
    }
    // traversing through larger one and inserting elements from smaller one wherever we can
    struct node *zeroNode = (struct node *)malloc(sizeof(struct node));
    zeroNode->data = -10;
    zeroNode->next = head_big;
    head_big = zeroNode;
    struct node *bigPointer = zeroNode;
    struct node *smallPointer = head_small;
    for (int i = 0; i < n + m; i++)
    {
        if (smallPointer == NULL)
        {
            break;
        }
        if (bigPointer->next->data >= smallPointer->data && bigPointer->data < smallPointer->data)
        {
            insertAfterPointer(smallPointer->data, bigPointer);
            bigPointer = bigPointer->next;
            smallPointer = smallPointer->next;
        }
        else
        {
            bigPointer = bigPointer->next;
        }
    }
    head_big = head_big->next;
    display(head_big);
    return 0;
}