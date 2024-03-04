#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void max_heapify(int arr[], int n, int i)
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
        max_heapify(arr, n, largest);
    }
}

int heaps(int arr[], int n, int k)
{
    for (int i = n / 2; i >= 0; i--)
    {
        max_heapify(arr, n, i);
    }
    int sum = 0;
    int i = n - 1;
    while (k--)
    {
        int new_sum;
        new_sum = sum + arr[0];
        if (new_sum < sum)
        {
            return sum;
        }
        else
        {
            sum = new_sum;
        }
        swap(&arr[0], &arr[i]);
        max_heapify(arr, i, 0);
        i--;
    }
    return sum;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int dps[n];
    int synergy[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dps[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &synergy[i]);
    }
    int good_arr[n];
    for (int i = 0; i < n; i++)
    {
        good_arr[i] = dps[i] + synergy[i];
    }
    // make heaps for the good_arr and sort for first k elements and then display the first k elements
    int goodness = heaps(good_arr, n, k);
    printf("%d", goodness);
    return 0;
}