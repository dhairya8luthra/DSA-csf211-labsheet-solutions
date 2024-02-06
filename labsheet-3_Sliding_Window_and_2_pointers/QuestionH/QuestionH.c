#include <stdio.h>

void countSetBits(long long int n, int arr[])
{
    int count = 0;
    long long int t = n;
    int j = 0;
    while (t)
    {
        if (t & 1)
        {
            arr[j]++;
        }
        t >>= 1;
        j++;
    }
}

void discountSetBits(long long int n, int arr[])
{
    int count = 0;
    long long int t = n;
    int j = 0;
    while (t)
    {
        if (t & 1)
        {
            arr[j]--;
        }
        t >>= 1;
        j++;
    }
}

int countNonZero(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf(" %lld", &arr[i]);
    }

    int brr[60];

    for (int i = 0; i < 60; i++)
    {
        brr[i] = 0;
    }

    for (int j = 0; j < k; j++)
    {
        countSetBits(arr[j], brr);
    }

    int maxi = countNonZero(brr, 60);
    int curr = 0;

    for (int i = 1; i < n - k - 1; i++)
    {
        discountSetBits(arr[i - 1], brr);
        countSetBits(arr[i + k - 1], brr);
        curr = countNonZero(brr, 60);
        if (curr > maxi)
        {
            maxi = curr;
        }
    }

    printf("%d\n", maxi);
    return 0;
}