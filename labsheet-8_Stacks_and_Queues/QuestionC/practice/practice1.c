#include <stdio.h>

#define SIZE 100000
unsigned int MOD = 1000000007;
int front = -1;
int rear = -1;

int arr[SIZE];

void push(int val)
{
    if (front < SIZE - 1)
    {
        if (front == -1)
        {
            front++;
        }
        rear++;
        arr[rear] = val;
    }
}

void pop()
{
    if (front <= rear && front != -1)
    {
        front++;
    }
}

int min()
{
    int min = arr[front];
    for (int i = front; i <= rear; i++)
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
            push(arr1[i]);
        }
        sum = (sum + min()) % MOD;
        for (int i = w; i < n; i++)
        {
            push(arr1[i]);
            pop();
            sum = (sum + min()) % MOD;
        }
        clear_queue();
    }
    printf("%d\n", sum);

    return 0;
}
