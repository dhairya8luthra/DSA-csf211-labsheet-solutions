#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int arr[], int index[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        swap(&index[largest], &index[i]);
        max_heapify(arr, index, n, largest);
    }
}

void heapSort(int arr[], int index[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        max_heapify(arr, index, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        swap(&index[0], &index[i]);
        max_heapify(arr, index, i, 0);
    }
}

int main()
{
    int n, threshold;
    scanf("%d %d", &n, &threshold);
    int hp[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &hp[i]);
    }
    int indexes[n];
    for (int i = 0; i < n; i++)
    {
        indexes[i] = i + 1;
    }
    heapSort(hp, indexes, n);
    int j = n;
    int k = 0;
    while (j)
    {
        if (hp[k] >= threshold)
        {
            break;
        }
        else
        {
            k++;
            j--;
        }
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d", indexes[i]);
    }
}