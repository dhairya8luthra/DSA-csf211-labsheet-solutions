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

void AddtoLinkedList(int val)
{
    if (head == NULL)
    {
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL)
    {
        ptr->data += val;
        if (ptr->data > 9 && ptr->next != NULL)
        {
            ptr->data %= 10;
            ptr->next->data += 1;
        }
        else if (ptr->data > 9 && ptr->next == NULL)
        {
            ptr->data %= 10;
            struct node *nextNode = (struct node *)malloc(sizeof(struct node));
            nextNode->data = 1;
            nextNode->next = NULL;
            ptr->next = nextNode;
        }
        ptr = ptr->next;
    }
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
    int big = (first >= second) ? first : second;
    int *bigArr = (first >= second) ? firstArr : secondArr;
    // create a linked list
    for (int i = 0; i < big; i++)
    {
        createLinkedList(bigArr[i]);
    }
    for (int i = 0; i < small; i++)
    {
        AddtoLinkedList(smallArr[i]);
    }
    display();

    // Free allocated memory
    free(firstArr);
    free(secondArr);

    return 0;
}
