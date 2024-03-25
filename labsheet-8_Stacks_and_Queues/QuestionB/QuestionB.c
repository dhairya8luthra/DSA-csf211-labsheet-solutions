#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
};

struct Queue
{
    struct node *head;
    struct node *tail;
    int max;
};
void print_q(struct Queue *queue)
{
    struct node *temp = queue->tail;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int pop(struct Queue *queue)
{
    if (queue->head == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int val = queue->head->data;
    struct node *temp = queue->head;
    queue->head = queue->head->prev;
    if (val == queue->max)
    {
        int new_max = -1;
        struct node *ptr = queue->tail;
        while (ptr != NULL)
        {
            if (ptr->data > new_max)
            {
                new_max = ptr->data;
            }

            ptr = ptr->prev;
        }
        print_q(queue);
        queue->max = new_max;
    }
    free(temp);
    return val;
}

void push(struct Queue *queue, int val)
{
    struct node *new_tail = (struct node *)malloc(sizeof(struct node));
    new_tail->data = val;
    new_tail->prev = NULL;
    if (queue->tail == NULL)
    {
        queue->head = new_tail;
        queue->tail = new_tail;
    }
    else
    {
        new_tail->prev = queue->tail->prev;
        queue->tail = new_tail;
    }

    if (val > queue->max)
    {
        queue->max = val;
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->max = -1;

    int max_val = arr[0];
    int head_pointer = k - 1;
    int tail_pointer = 0;
    // setting up initial window
    for (int i = head_pointer; i >= tail_pointer; i--)
    {
        push(queue, arr[i]);
    }
    while (head_pointer != n)
    {
        printf("%d head_pointer is at %d \n", queue->max, arr[head_pointer]);
        pop(queue);
        tail_pointer++;
        head_pointer++;
        push(queue, arr[head_pointer]);
    }

    free(queue); // free allocated memory
    return 0;
}
