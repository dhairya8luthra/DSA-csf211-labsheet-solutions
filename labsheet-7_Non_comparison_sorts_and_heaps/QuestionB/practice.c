#include <stdio.h>
#include <stdlib.h>
struct node
{
    float data;
    struct node *next;
};
void Addnode(struct node **head, float val)
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
        struct node *pointer = *head;
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
        }
        pointer->next = new_node;
    }
}
void insertion_sort_LL(struct node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    // Initialization of pointers
    struct node *sorted = NULL;
    struct node *current = *head;

    // Loop through the linked list
    while (current)
    {
        // Save the next node in the original list before modifying pointers
        struct node *next = current->next;

        // Case 1: If the sorted list is empty or the current node is smaller than the first node in the sorted list
        if (sorted == NULL || sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        // Case 2: If the current node is larger than the first node in the sorted list
        else
        {
            struct node *temp = sorted;
            while (temp != NULL)
            {
                struct node *s = temp;
                // Find the appropriate position to insert the current node
                if (s->next == NULL || s->next->data > current->data)
                {
                    current->next = s->next;
                    s->next = current;
                    break;
                }
                temp = temp->next;
            }
        }
        // Move to the next node in the original list
        current = next;
    }
    // Update the head pointer to point to the sorted list
    *head = sorted;
}

int main()
{
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    // creating buckets
    struct node *buckets[n];
    for (int i = 0; i < n; i++)
    {
        buckets[i] = NULL;
    }
    // adding elements into the buckets
    int element_count[n];
    for (int i = 0; i < n; i++)
    {
        element_count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int bucket_no = (int)(arr[i] * n);
        if (bucket_no >= n)
        {
            bucket_no = n - 1;
        }
        element_count[bucket_no]++;
        Addnode(&buckets[bucket_no], arr[i]);
    }
    // sorting the buckets
    for (int i = 0; i < n; i++)
    {
        insertion_sort_LL(&buckets[i]);
    }
    // merging the buckets
    float sorted_list[n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (buckets[i] != NULL)
        {
            struct node *curr_pointer = buckets[i];
            while (curr_pointer)
            {
                sorted_list[k++] = curr_pointer->data;
                curr_pointer = curr_pointer->next;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%.1f ", sorted_list[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", element_count[i]);
    }

    return 0;
}
