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
    // reverse the linked list
    struct node *ptr = head;
    struct node *prev = NULL;
    for (int i = 0; i < n; i++)
    {

        struct node *temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    head = prev;
    printf("Reversed Linked List: ");
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
    return 0;
}