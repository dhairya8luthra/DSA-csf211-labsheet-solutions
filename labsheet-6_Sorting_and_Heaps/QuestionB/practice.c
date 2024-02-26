#include <stdio.h>
void swap(int arr[], int pointer1, int pointer2)
{
    int temp = arr[pointer1];
    arr[pointer1] = arr[pointer2];
    arr[pointer2] = temp;
}

void Qsort(int arr[], int high, int low)
{
    if (low < high)
    {
        int pointer1 = low;
        int pointer2 = low;
        int pivot = high;
        // now that pivot and pointers are set we try sort pivot to its right position
        // if arr[pointer1]<arr[pivot] we need to swap it with pointer 2
        while (pointer1 < pivot)
        {
            if (arr[pointer1] < arr[pivot])
            {
                swap(arr, pointer1, pointer2);
                pointer1++;
                pointer2++;
            }
            else
            {
                pointer1++;
            }
        }
        swap(arr, pointer2, pivot);
        Qsort(arr, pointer2 - 1, low);
        Qsort(arr, high, pointer2 + 1);
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
    int high = n - 1;
    int low = 0;
    Qsort(arr, high, low);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}