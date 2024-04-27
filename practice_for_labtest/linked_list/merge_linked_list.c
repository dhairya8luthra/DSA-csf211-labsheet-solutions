#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *mergeLinkedLists(struct node *jakePtr, struct node *amyPtr)
{
    struct node dummy;
    struct node *current = &dummy;
    dummy.next = NULL;

    while (jakePtr != NULL && amyPtr != NULL)
    {
        if (jakePtr->data <= amyPtr->data)
        {
            current->next = jakePtr;
            jakePtr = jakePtr->next;
        }
        else
        {
            current->next = amyPtr;
            amyPtr = amyPtr->next;
        }
        current = current->next;
    }

    // Append the remaining nodes from Jake's or Amy's list
    if (jakePtr != NULL)
    {
        current->next = jakePtr;
    }
    else
    {
        current->next = amyPtr;
    }

    return dummy.next;
}

void printLinkedList(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    struct node *jakeHead = NULL;
    struct node *amyHead = NULL;

    // Reading Jake's list
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = val;
        new_node->next = NULL;
        if (jakeHead == NULL)
        {
            jakeHead = new_node;
        }
        else
        {
            struct node *current = jakeHead;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    // Reading Amy's list
    for (int i = 0; i < m; i++)
    {
        int val;
        scanf("%d", &val);
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = val;
        new_node->next = NULL;
        if (amyHead == NULL)
        {
            amyHead = new_node;
        }
        else
        {
            struct node *current = amyHead;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    // Merge the two lists
    struct node *mergedHead = mergeLinkedLists(jakeHead, amyHead);

    // Print the merged list
    printLinkedList(mergedHead);

    // Free the memory allocated for the linked lists
    struct node *temp;
    while (mergedHead != NULL)
    {
        temp = mergedHead;
        mergedHead = mergedHead->next;
        free(temp);
    }

    return 0;
}
