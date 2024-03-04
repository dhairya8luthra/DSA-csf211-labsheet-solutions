#include <stdio.h>
#include <stdlib.h>
void sort(int arr[], float distances[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (distances[j] > distances[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                float tempDist = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = tempDist;
            }
        }
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
    // then sort based on the distances array value

    float distances[n];
    // calculate distance from pos
    for (int i = 0; i < n; i++)
    {

        float distance = abs(targets[i] - pos);
        distance += (targets[i] > pos) ? (1 / (float)n) : (-1 / (float)n);
        distances[i] = distance;
    }
    // sort based on distance
    sort(targets, distances, n);
    // printing
    for (int i = 0; i < k; i++)
    {
        printf("%d ", targets[i]);
    }
}