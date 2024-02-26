#include <stdio.h>
#include <stdlib.h>

// Min heap structure and functions
typedef struct
{
    int *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->arr = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->arr[left] < minHeap->arr[smallest])
        smallest = left;

    if (right < minHeap->size && minHeap->arr[right] < minHeap->arr[smallest])
        smallest = right;

    if (smallest != idx)
    {
        swap(&minHeap->arr[idx], &minHeap->arr[smallest]);
        minHeapify(minHeap, smallest);
    }
}

void insertMinHeap(MinHeap *minHeap, int val)
{
    if (minHeap->size == minHeap->capacity)
    {
        // If the heap is full, replace the root with the new value if it's smaller
        if (val > minHeap->arr[0])
            return;
        minHeap->arr[0] = val;
        minHeapify(minHeap, 0);
    }
    else
    {
        // If the heap is not full, insert the new value at the end and heapify
        minHeap->arr[minHeap->size++] = val;
        int i = minHeap->size - 1;
        while (i > 0 && minHeap->arr[(i - 1) / 2] > minHeap->arr[i])
        {
            swap(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
}

long long kSmallestSum(int n, int k, int *arr)
{
    // Create a min heap
    MinHeap *minHeap = createMinHeap(n);

    // Insert the first k elements into the heap
    for (int i = 0; i < k; ++i)
    {
        insertMinHeap(minHeap, arr[i]);
    }

    // Iterate through the rest of the elements
    for (int i = k; i < n; ++i)
    {
        // If the current element is smaller than the largest element in the heap, replace it
        if (arr[i] < minHeap->arr[0])
        {
            minHeap->arr[0] = arr[i];
            minHeapify(minHeap, 0);
        }
    }

    // Calculate the sum of the k smallest elements
    long long sum = 0;
    for (int i = 0; i < k; ++i)
    {
        sum += minHeap->arr[i];
    }

    // Free allocated memory
    free(minHeap->arr);
    free(minHeap);

    return sum;
}

int main()
{
    // Input
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    // Output
    long long result = kSmallestSum(n, k, arr);
    printf("%lld\n", result);

    // Free allocated memory
    free(arr);

    return 0;
}
