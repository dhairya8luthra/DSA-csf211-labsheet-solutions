#include <stdio.h>
#define SIZE 100000
unsigned int MOD = 1000000007;

int front = -1;
int rear = -1;
int arr[SIZE];
void enqueue(int x); // push
void pop();          // removes one element
int dequeue();       // returns element
int isEmpty();

int min()
{
    int min = arr[front];
    for (int i = front + 1; i <= rear; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

void clear_queue()
{
    front = -1;
    rear = -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    for (int w = 1; w <= n; w++)
    {
        for (int i = 0; i < w; i++)
        {
            enqueue(arr1[i]);
        }
        sum = (sum + min()) % MOD;
        for (int i = w; i < n; i++)
        {
            enqueue(arr1[i]);
            pop();
            sum = (sum + min()) % MOD;
        }
        clear_queue();
    }
    printf("%d\n", sum);

    return 0;
}

void enqueue(int x)
{
    if (front < SIZE - 1)
    {
        if (front == -1)
        {
            front++;
        }
        rear++;
        arr[rear] = x;
    }
}
void pop()
{
    if ((front <= rear) && (front != -1))
    {
        front++;
    }
}
int dequeue()
{
    if (front != -1)
    {
        return arr[front];
    }
    else
    {
        return -1;
    }
}
int isEmpty()
{
    if ((front > rear) || (front == -1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
