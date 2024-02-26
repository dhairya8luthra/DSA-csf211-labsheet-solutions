#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;

        while (j >= 0 && curr < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int LeftSize = middle - left + 1;
    int RightSize = right - middle;

    int L[LeftSize], R[RightSize];

    for (int i = 0; i < LeftSize; i++)
    {
        L[i] = arr[left + i];
    }

    for (int i = 0; i < RightSize; i++)
    {
        R[i] = arr[middle + 1 + i];
    }

    int LeftPointer = 0;
    int RightPointer = 0;
    int arrayPointer = left;

    while (LeftPointer < LeftSize && RightPointer < RightSize)
    {
        if (L[LeftPointer] <= R[RightPointer])
        {
            arr[arrayPointer] = L[LeftPointer];
            LeftPointer++;
        }
        else
        {
            arr[arrayPointer] = R[RightPointer];
            RightPointer++;
        }
        arrayPointer++;
    }

    while (LeftPointer < LeftSize)
    {
        arr[arrayPointer] = L[LeftPointer];
        LeftPointer++;
        arrayPointer++;
    }

    while (RightPointer < RightSize)
    {
        arr[arrayPointer] = R[RightPointer];
        RightPointer++;
        arrayPointer++;
    }
}

void mergeSort(int arr[], int left, int right, int k)
{
    if (left < right)
    {
        if (right - left + 1 <= k)
        {
            insertion_sort(arr + left, right - left + 1);
        }
        else
        {
            int middle = left + (right - left) / 2;
            mergeSort(arr, left, middle, k);
            mergeSort(arr, middle + 1, right, k);
            merge(arr, left, middle, right);
        }
    }
}

void custom_merge_sort(int arr[], int n, int k)
{
    mergeSort(arr, 0, n - 1, k);
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
