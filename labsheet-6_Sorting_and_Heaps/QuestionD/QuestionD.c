#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = left; x <= right; x++)
    {
        arr[x] = temp[x];
    }
}

void merge_sort(int arr[], int temp[], int left, int right, int k)
{
    if (left < right)
    {
        if (right - left + 1 <= k)
        {
            insertion_sort(arr + left, right - left + 1);
        }
        else
        {
            int mid = (left + right) / 2;
            merge_sort(arr, temp, left, mid, k);
            merge_sort(arr, temp, mid + 1, right, k);
            merge(arr, temp, left, mid, right);
        }
    }
}

void custom_merge_sort(int arr[], int n, int k)
{
    int temp[n];
    merge_sort(arr, temp, 0, n - 1, k);
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

    custom_merge_sort(arr, n, k);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
