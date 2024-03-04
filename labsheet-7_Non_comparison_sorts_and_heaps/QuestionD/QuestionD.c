#include <stdio.h>

int main()
{
    int n, val;
    scanf("%d %d", &n, &val);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int frequency[max + 1];
    for (int i = 1; i < max + 1; i++)
    {
        frequency[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]]++;
    }
    int missingNumbers[n];
    int k = 0;
    for (int i = 1; i < max + 1; i++)
    {
        if (!frequency[i])
        {
            missingNumbers[k] = i;
            k++;
        }
    }
    // so we have k missing numbers and target sum val
    // i have to check these k numbers if they give a combination
    if (k == 1)
    {
        printf("no");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (missingNumbers[i] + missingNumbers[j] == val)
            {
                printf("yes");
                return 0;
            }
        }
    }
    printf("no");
    return 0;
}