#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapf(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void Max_heapify(int arr[], float distances[], int n, int i)
{
    int largest = i;
    int right = 2 * i + 2;
    int left = 2 * i + 1;

    if (left < n && distances[left] > distances[largest])
    {
        largest = left;
    }
    if (right < n && distances[right] > distances[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        swapf(&distances[i], &distances[largest]);
        Max_heapify(arr, distances, n, largest);
    }
}

void heapSort(int arr[], float distances[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        Max_heapify(arr, distances, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        swapf(&distances[0], &distances[i]);
        Max_heapify(arr, distances, i, 0);
    }
}

int main()
{
    // taking input
    int n, k, pos;
    scanf("%d %d %d", &n, &k, &pos);

    int targets[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &targets[i]);
    }

    // approach: I am going to create a distances array in which we will
    // store the distance from pos and if it is left of pos then distance is 1/n less
    // if it is right it 1/n more that is how we handle equal cases
    // then sort by using a min heap

    float distances[n];

    // calculate distance from pos
    for (int i = 0; i < n; i++)
    {
        float distance = fabs(targets[i] - pos);
        distance += (targets[i] > pos) ? (1 / (float)n) : (-1 / (float)n);
        distances[i] = distance;
    }

    // sort based on distance
    heapSort(targets, distances, n);

    // printing
    for (int i = 0; i < k; i++)
    {
        printf("%d ", targets[i]);
    }

    return 0;
}
