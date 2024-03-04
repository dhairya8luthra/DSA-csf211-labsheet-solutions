#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i)
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
        // Swap arr[i] and arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        // Swap arr[0] and arr[i]
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    char characters[n];
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &characters[i]);
    }

    int frequency[26] = {0}; // Assuming only lowercase characters are given

    for (int i = 0; i < n; i++)
    {
        frequency[characters[i] - 'a']++;
    }

    heapsort(frequency, 26);

    int minSum = 0;
    for (int i = 0; i < 26 && k > 0; i++)
    {
        if (frequency[i] <= k)
        {
            minSum += frequency[i] * frequency[i];
            k -= frequency[i];
        }
        else
        {
            minSum += k * k;
            k = 0;
        }
    }

    printf("%d\n", minSum);

    return 0;
}
