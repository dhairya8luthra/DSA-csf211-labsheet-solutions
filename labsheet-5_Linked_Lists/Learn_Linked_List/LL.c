#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// creating a node
void create_node()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        // traverse until the end and point last next address to address of new node
        struct Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List Empty\n");
    }
    else
    {
        struct Node *ptr = head;
        while (ptr != NULL)
        {
            printf(" %d \n", ptr->data);
            ptr = ptr->next;
        }
    }
}
// to insert node at start of LinkedList
void insert_begin()
{
    struct node *temp;
    // creating a new node
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        temp->next = head; // point it to old head node
        head = temp;       // point head to new first node
    }
}

// to insert node at given position
void insert_pos()
{
    struct node *temp;
    // creating a new node
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL) // if list empty we return
    {
        head = temp;
        return;
    }
    else
    {
        struct node *prev_ptr;
        struct node *ptr = head;
        int pos;
        printf("Enter position: ");
        scanf("%d", &pos);
        for (int i = 0; i < pos; i++)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        // new node pointing to node in that pos
        temp->next = ptr;
        // prevptr pointing to new node
        prev_ptr->next = temp;
    }
}

void insert_end()
{
    struct node *temp;
    // creating new node
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp; // if list is empty, we return
        return;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        // tail node pointing to new node
        ptr->next = temp;
    }
}

int main()
{
    int lengthofll;
    scanf("%d", &lengthofll);
    for (int i = 0; i < lengthofll; i++)
    {
        create_node();
    }
    display();
    return 0;
}
