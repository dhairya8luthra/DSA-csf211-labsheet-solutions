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
    int max;
    max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int freq[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int missingnumbers[n];
    int k = 0;
    for (int i = 1; i < max + 1; i++)
    {
        if (!freq[i])
        {
            missingnumbers[k] = i;
            k++;
        }
    }
    if (k == 1)
    {
        printf("no");
        return 0;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (missingnumbers[i] + missingnumbers[j] == val)
            {
                printf("yes");
                return 0;
            }
        }
    }
    printf("no");
    return 0;
}