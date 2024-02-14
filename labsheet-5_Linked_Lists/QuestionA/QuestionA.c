#include <stdio.h>
#include <stdlib.h>

struct node *head = NULL;

struct node
{
    int data;
    struct node *next;
};

void createLinkedList(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void AddtoLinkedList(int val, struct node *pointer)
{
    if (head == NULL)
    {
        return;
    }
    pointer->data += val;
    if (pointer->data > 9)
    {
        pointer->data %= 10;
        if (pointer->next == NULL)
        {
            createLinkedList(1);
        }
        else
        {
            pointer->next->data++;
        }
    }

    return;
}

void display()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    // taking input;
    int first, second;
    scanf("%d", &first);
    scanf("%d", &second);
    int *firstArr = (int *)malloc(sizeof(int) * first);
    for (int i = 0; i < first; i++)
    {
        scanf("%d", &firstArr[i]);
    }
    int *secondArr = (int *)malloc(sizeof(int) * second);
    for (int i = 0; i < second; i++)
    {
        scanf("%d", &secondArr[i]);
    }
    // finding smaller and bigger
    int small = (first <= second) ? first : second;
    int *smallArr = (first <= second) ? firstArr : secondArr;
    int big = (second >= first) ? second : first;
    int *bigArr = (second >= first) ? secondArr : firstArr;
    // create a linked list
    for (int i = 0; i < big; i++)
    {
        createLinkedList(bigArr[i]);
    }
    struct node *pointer = head;
    for (int i = 0; i < small && pointer != NULL; i++)
    {
        AddtoLinkedList(smallArr[i], pointer);
        pointer = pointer->next;
    }
    display();

    // Free allocated memory
    free(firstArr);
    free(secondArr);

    return 0;
}
