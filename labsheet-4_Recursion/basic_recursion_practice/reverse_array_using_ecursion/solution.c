#include <stdio.h>
void reverse(int *arr, int n, int i)
{
    if (i >= n / 2)
    {
        return;
    }
    else
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
        reverse(arr, n, ++i);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    // taking input
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //
    reverse(arr, n, 0);
    // printf
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }

    return 0;
}