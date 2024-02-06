#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int result[n + m];
    //
    int pointer1 = 0;
    int pointer2 = 0;
    int pointer3 = 0;
    while ((pointer1 < n || pointer2 < m) && (pointer3 < n + m))
    {
        int number;
        if (pointer1 >= n)
        {
            number = arr2[pointer2++];
        }
        else if (pointer2 >= m)
        {
            number = arr1[pointer1++];
        }
        else
        {
            number = (arr1[pointer1] > arr2[pointer2]) ? (arr2[pointer2++]) : (arr1[pointer1++]);
        }
        result[pointer3++] = number;
    }
    for (int i = 0; i < n + m; i++)
    {
        printf(" %d", result[i]);
    }
    return 0;
}