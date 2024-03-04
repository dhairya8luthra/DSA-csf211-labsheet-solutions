#include <stdio.h>
#include <stdlib.h>

int *countSort(int *inputArray, int N)
{
    int M = 0;

    // Finding the maximum element of array inputArray[].
    for (int i = 0; i < N; i++)
        M = (M < inputArray[i]) ? inputArray[i] : M;

    // Initializing countArray[] with 0
    int *countArray = (int *)malloc((M + 1) * sizeof(int));
    for (int i = 0; i <= M; i++)
        countArray[i] = 0;

    // Mapping each element of inputArray[] as an index
    // of countArray[] array
    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;

    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    // Creating outputArray[] from countArray[] array
    int *outputArray = (int *)malloc(N * sizeof(int));
    for (int i = N - 1; i >= 0; i--)
    {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }

    return outputArray;
}

// Driver code
int main()
{
    // Input array
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Output array
    int *outputArray = countSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", outputArray[i]);

    return 0;
}
