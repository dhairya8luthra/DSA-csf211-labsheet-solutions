#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int capacity;
    int size;
} MinHeap;

typedef struct
{
    int *arr;
    int capacity;
    int size;
    double sum;
} AvgHeap;

MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->arr = (int *)malloc(capacity * sizeof(int));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    return minHeap;
}

AvgHeap *createAvgHeap(int capacity)
{
    AvgHeap *avgHeap = (AvgHeap *)malloc(sizeof(AvgHeap));
    avgHeap->arr = (int *)malloc(capacity * sizeof(int));
    avgHeap->capacity = capacity;
    avgHeap->size = 0;
    avgHeap->sum = 0;
    return avgHeap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMin(MinHeap *minHeap, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < minHeap->size && minHeap->arr[left] < minHeap->arr[smallest])
        smallest = left;

    if (right < minHeap->size && minHeap->arr[right] < minHeap->arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&minHeap->arr[i], &minHeap->arr[smallest]);
        heapifyMin(minHeap, smallest);
    }
}

void heapifyAvg(AvgHeap *avgHeap, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < avgHeap->size && avgHeap->arr[left] < avgHeap->arr[smallest])
        smallest = left;

    if (right < avgHeap->size && avgHeap->arr[right] < avgHeap->arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&avgHeap->arr[i], &avgHeap->arr[smallest]);
        heapifyAvg(avgHeap, smallest);
    }
}

void pushMin(MinHeap *minHeap, int val)
{
    if (minHeap->size == minHeap->capacity)
    {
        printf("Overflow: Cannot push %d to min heap\n", val);
        return;
    }

    minHeap->arr[minHeap->size] = val;
    int i = minHeap->size;
    minHeap->size++;

    while (i && minHeap->arr[i] < minHeap->arr[(i - 1) / 2])
    {
        swap(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void pushAvg(AvgHeap *avgHeap, int val)
{
    if (avgHeap->size == avgHeap->capacity)
    {
        printf("Overflow: Cannot push %d to avg heap\n", val);
        return;
    }

    avgHeap->arr[avgHeap->size] = val;
    int i = avgHeap->size;
    avgHeap->size++;
    avgHeap->sum += val;

    while (i && avgHeap->arr[i] < avgHeap->arr[(i - 1) / 2])
    {
        swap(&avgHeap->arr[i], &avgHeap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int popMin(MinHeap *minHeap)
{
    if (minHeap->size == 0)
    {
        printf("Underflow: Cannot pop from min heap\n");
        return -1;
    }

    int root = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    minHeap->size--;
    heapifyMin(minHeap, 0);

    return root;
}

int popAvg(AvgHeap *avgHeap)
{
    if (avgHeap->size == 0)
    {
        printf("Underflow: Cannot pop from avg heap\n");
        return -1;
    }

    int root = avgHeap->arr[0];
    avgHeap->arr[0] = avgHeap->arr[avgHeap->size - 1];
    avgHeap->sum -= root;
    avgHeap->size--;
    heapifyAvg(avgHeap, 0);

    return root;
}

int getMin(MinHeap *minHeap)
{
    if (minHeap->size == 0)
    {
        printf("Min heap is empty\n");
        return -1;
    }
    return minHeap->arr[0];
}

int getAvg(AvgHeap *avgHeap)
{
    if (avgHeap->size == 0)
    {
        printf("Avg heap is empty\n");
        return -1;
    }
    return (int)(avgHeap->sum / avgHeap->size);
}

int main()
{
    int q;
    scanf("%d", &q);

    MinHeap *minHeap = createMinHeap(q);
    AvgHeap *avgHeap = createAvgHeap(q);

    for (int i = 0; i < q; i++)
    {
        int op;
        scanf("%d", &op);

        if (op == 1)
        {
            int val;
            scanf("%d", &val);
            pushMin(minHeap, val);
            pushAvg(avgHeap, val);
        }
        else if (op == 2)
        {
            popMin(minHeap);
            popAvg(avgHeap);
        }
        else if (op == 3)
        {
            int minVal = getMin(minHeap);
            int avgVal = getAvg(avgHeap);
            printf("%d %d\n", minVal, avgVal);
        }
    }

    free(minHeap->arr);
    free(minHeap);
    free(avgHeap->arr);
    free(avgHeap);

    return 0;
}