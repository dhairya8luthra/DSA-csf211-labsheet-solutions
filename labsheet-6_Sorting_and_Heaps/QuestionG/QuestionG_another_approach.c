#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int a[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    while (l < n && a[l] < a[smallest])
        smallest = l;
    while (r < n && a[r] < a[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&a[smallest], &a[i]);
        heapify(a, n, smallest);
    }
}
int heap_solve(int a[], int n, int k)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    int sum = 0;
    int i = n - 1;
    while (k--)
    {
        sum = sum + a[0];
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
        i--;
    }
    return sum;
}
int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int a[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", heap_solve(a, n, k));
}