#include <stdio.h>
#include <stdlib.h>
struct element
{
    int data;
    int firstOccurrence;
    float freq;
};

void countingsort(struct element arr[], int n)
{
    float max = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i].freq)
        {
            max = arr[i].freq;
        }
    }
    struct element output[n];
    int count[(int)max + 1];
    for (int i = 0; i < (int)max + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[(int)arr[i].freq]++;
    }
    for (int i = 1; i < (int)max + 1; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[--(count[(int)arr[i].freq])] = arr[i];
        }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
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
    struct element uniqueArr[n];
    int uniquecount = 0;
    for (int i = 0; i < n; i++)
    {
        int isUnique = 1;
        for (int j = 0; j < uniquecount; j++)
        {
            if (uniqueArr[j].data == arr[i])
            {
                isUnique = 0;
                uniqueArr[j].freq++;
                break;
            }
        }
        if (isUnique)
        {
            uniqueArr[uniquecount].data = arr[i];
            uniqueArr[uniquecount].firstOccurrence = i;
            uniqueArr[uniquecount].freq = 1.0;
            uniquecount++;
        }
    }
    for (int i = 0; i < uniquecount; i++)
    {
        uniqueArr[i].freq += i * 0.1 / (uniqueArr[i].firstOccurrence + 1);
    }
    countingsort(uniqueArr, uniquecount);
    for (int i = 0; i < uniquecount; i++)
    {
        for (int j = 0; j < (int)uniqueArr[i].freq; j++)
        {
            printf("%d ", uniqueArr[i].data);
        }
    }
    return 0;
}