#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int middle, int right)
{
    int LeftSize = middle - left + 1;
    int RightSize = right - middle;
    //
    int L[LeftSize], R[RightSize];
    // put data in Left and Right arrays
    for (int i = 0; i < LeftSize; i++)
    {
        L[i] = arr[left + i];
    }
    //
    for (int i = 0; i < RightSize; i++)
    {
        R[i] = arr[middle + 1 + i];
    }
    // Merge these temp arrays back into arr[]
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
    // copy rest elemnts of L and R
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

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        // sort first half
        mergeSort(arr, left, middle);
        // sort second half
        mergeSort(arr, middle + 1, right);
        // merge right half and left half
        merge(arr, left, middle, right);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}