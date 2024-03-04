#include <stdio.h>
#include <stdlib.h>
struct pair
{
    int first;
    int second;
};

void printpairs(struct pair *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]->first);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]->second);
    }
}
void sortPairs(struct pair *arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j]->first > arr[j + 1]->first ||
                (arr[j]->first == arr[j + 1]->first && arr[j]->second > arr[j + 1]->second))
            {
                struct pair *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    struct pair *arr[n];
    // setting first
    for (int i = 0; i < n; i++)
    {
        struct pair *temp = (struct pair *)malloc(sizeof(struct pair));
        int val;
        scanf("%d", &val);
        temp->first = val;
        arr[i] = temp;
    }
    // setting second
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        arr[i]->second = val;
    }
    // sorting the pairs
    sortPairs(arr, n);
    // print pairs
    printpairs(arr, n);
    return 0;
}