#include <stdio.h>
#include <stdlib.h>

void frequencySort(int arr[], int n)
{
    // Find the maximum element in the array
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Create an array to store the frequency of each element
    int *freq = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++)
    {
        freq[i] = 0;
    }

    // Create an array to store the original order of each element
    int *originalOrder = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        originalOrder[i] = i;
    }

    // Count the frequency of each element
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Custom comparison function to sort based on frequency and original order
    int compare(const void *a, const void *b)
    {
        int indexA = *(int *)a;
        int indexB = *(int *)b;

        if (freq[arr[indexA]] != freq[arr[indexB]])
        {
            return freq[arr[indexA]] - freq[arr[indexB]];
        }

        return indexA - indexB;
    }

    // Sort the indices array using the custom comparison function
    qsort(originalOrder, n, sizeof(int), compare);

    // Reconstruct the sorted array using the original order
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[originalOrder[i]]);
    }

    // Free the memory allocated for frequency and original order arrays
    free(freq);
    free(originalOrder);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    frequencySort(arr, n);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}
