#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int left, int right, int middle)
{
    int LeftSize = middle - left + 1;
    int RightSize = right - middle;
    int LeftPointer = 0;
    int RightPointer = 0;
    int ArrayPointer = left;
    // declaring temp arrays
    int L[LeftSize];
    int R[RightSize];
    // adding data to temp arrays
    for (int i = 0; i < LeftSize; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < RightSize; i++)
    {
        R[i] = arr[middle + 1 + i];
    }
    // sort and Merge these arrays back into original Array
    while (LeftPointer < LeftSize && RightPointer < RightSize)
    {
        if (L[LeftPointer] <= R[RightPointer])
        {
            arr[ArrayPointer] = L[LeftPointer];
            LeftPointer++;
        }
        else
        {
            arr[ArrayPointer] = R[RightPointer];
            RightPointer++;
        }
        ArrayPointer++;
    }
    // adding other elements to the Array
    while (LeftPointer < LeftSize)
    {
        arr[ArrayPointer] = L[LeftPointer];
        LeftPointer++;
        ArrayPointer++;
    }
    while (RightPointer < RightSize)
    {
        arr[ArrayPointer] = R[RightPointer];
        RightPointer++;
        ArrayPointer++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        // sorting left side
        merge_sort(arr, left, middle);
        // sorting right side
        merge_sort(arr, middle + 1, right);
        // merging 2 sorted halves
        merge(arr, left, right, middle);
    }
}

int main()
{
    // taking input
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}