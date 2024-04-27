#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};

void Addnode(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->val = data;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        struct node *ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        Addnode(&head, data);
    }
    // now removing duplicates
    struct node *ptr = head->next;
    int current = head->val;
    struct node *curr_pointer = head;
    for (int i = 1; i < n; i++)
    {
        if (ptr->val == current)
        {
            ptr = ptr->next;
        }
        else
        {
            curr_pointer->next = ptr;
            curr_pointer = curr_pointer->next;
            current = ptr->val;
            ptr = ptr->next;
        }
    }
    // print
    struct node *ptr2 = head;
    while (ptr2 != NULL)
    {
        printf("%d ", ptr2->val);
        ptr2 = ptr2->next;
    }
    return 0;
}