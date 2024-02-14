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
void insertAfterPointer(int x, struct node *BigPointer)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = BigPointer->next;
    BigPointer->next = temp;
}
void display(struct node *head)
{
    struct node *start = head;
    while (start != NULL)
    {
        printf("%d", start->data);
        start = start->next;
    }
}

int main()
{
    // Approach:What we basically have to do is merge 2 linked lists
    // we create 2 linked lists traverse through larger one and insert elements from shorter one wherever we can
    // Declaring Heads
    struct node *head_big = NULL;
    struct node *head_small = NULL;
    // taking input
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    // creating 2 Linked Lists
    // smaller one
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        AddNode(val, head_small);
    }
    display(head_small);
    // bigger one
    for (int i = 0; i < m; i++)
    {
        int val;
        scanf("%d", &val);
        AddNode(val, head_big);
    }
    display(head_big);
    // time to merge
    struct node *BigPointer = head_big;
    struct node *SmallPointer = head_small;

    // we need to add -1 pointer as head of big so that we can add all those elements which are smaller than the smallest element of Big Linked List
    struct node *zeroNode = (struct node *)malloc(sizeof(struct node));
    zeroNode->data = -10;
    zeroNode->next = head_big;
    BigPointer = zeroNode;
    // merging the 2 Linked Lists
    for (int i = 0; i < m + 1; i++)
    {
        if (SmallPointer == NULL)
        {
            break;
        }
        if (BigPointer->next->data >= SmallPointer->data && BigPointer->data < SmallPointer->data)
        {
            insertAfterPointer(SmallPointer->data, BigPointer);
            BigPointer = BigPointer->next;
            SmallPointer = SmallPointer->next;
        }
        else
        {
            BigPointer = BigPointer->next;
        }
    }
    // while displaying display from the head of big
    display(head_big);
    return 0;
}