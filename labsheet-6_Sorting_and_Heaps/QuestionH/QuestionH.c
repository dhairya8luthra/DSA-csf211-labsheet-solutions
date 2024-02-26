#include <stdio.h>
#include <stdlib.h>

// Min heap structure and functions
typedef struct
{
    int value;
    int arrayIndex;
    int elementIndex;
} HeapNode;

typedef struct
{
    HeapNode *heapArr;
    int size;
    int capacity;
} MinHeap;

MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->heapArr = (HeapNode *)malloc(capacity * sizeof(HeapNode));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void swap(HeapNode *a, HeapNode *b)
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->heapArr[left].value < minHeap->heapArr[smallest].value)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->heapArr[right].value < minHeap->heapArr[smallest].value)
        smallest = right;

    if (smallest != idx)
    {
        swap(&minHeap->heapArr[idx], &minHeap->heapArr[smallest]);
        minHeapify(minHeap, smallest);
    }
}

void insertMinHeap(MinHeap *minHeap, int value, int arrayIndex, int elementIndex)
{
    if (minHeap->size == minHeap->capacity)
    {
        // If the heap is full, replace the root with the new value if it's smaller
        if (value > minHeap->heapArr[0].value)
            return;

        minHeap->heapArr[0].value = value;
        minHeap->heapArr[0].arrayIndex = arrayIndex;
        minHeap->heapArr[0].elementIndex = elementIndex;
        minHeapify(minHeap, 0);
    }
    else
    {
        // If the heap is not full, insert the new value at the end and heapify
        minHeap->heapArr[minHeap->size].value = value;
        minHeap->heapArr[minHeap->size].arrayIndex = arrayIndex;
        minHeap->heapArr[minHeap->size].elementIndex = elementIndex;
        minHeap->size++;
        int i = minHeap->size - 1;
        while (i > 0 && minHeap->heapArr[(i - 1) / 2].value > minHeap->heapArr[i].value)
        {
            swap(&minHeap->heapArr[i], &minHeap->heapArr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
}

int *mergeKSortedArrays(int k, int **arrays, int *sizes, int *resultSize)
{
    // Create a min heap
    MinHeap *minHeap = createMinHeap(k);

    // Insert the first element from each array into the heap
    for (int i = 0; i < k; ++i)
    {
        if (sizes[i] > 0)
        {
            insertMinHeap(minHeap, arrays[i][0], i, 0);
        }
    }

    // Create the result array
    int *result = (int *)malloc((k * sizes[0]) * sizeof(int));
    *resultSize = 0;

    // Merge the arrays using the heap
    while (minHeap->size > 0)
    {
        HeapNode minNode = minHeap->heapArr[0];
        result[(*resultSize)++] = minNode.value;

        // Move to the next element in the same array
        if (minNode.elementIndex + 1 < sizes[minNode.arrayIndex])
        {
            insertMinHeap(minHeap, arrays[minNode.arrayIndex][minNode.elementIndex + 1],
                          minNode.arrayIndex, minNode.elementIndex + 1);
        }

        // Remove the min element from the heap
        if (minHeap->size > 1)
        {
            minHeap->heapArr[0] = minHeap->heapArr[minHeap->size - 1];
            minHeap->size--;
            minHeapify(minHeap, 0);
        }
        else
        {
            minHeap->size = 0;
        }
    }

    return result;
}

int main()
{
    // Input
    int k;
    scanf("%d", &k);

    int **arrays = (int **)malloc(k * sizeof(int *));
    int *sizes = (int *)malloc(k * sizeof(int));

    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &sizes[i]);
        arrays[i] = (int *)malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; ++j)
        {
            scanf("%d", &arrays[i][j]);
        }
    }

    // Output
    int resultSize;
    int *result = mergeKSortedArrays(k, arrays, sizes, &resultSize);

    // Print the merged and sorted array
    for (int i = 0; i < resultSize; ++i)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < k; ++i)
    {
        free(arrays[i]);
    }
    free(arrays);
    free(sizes);
    free(result);

    return 0;
}
