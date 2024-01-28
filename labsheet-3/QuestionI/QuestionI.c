#include <stdio.h>
#include <stdbool.h>

#define MOD 1000000007

int isPrime(int num)
{
    if (num < 2)
    {
        return 0;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    long long product = 1;
    int hasNonPrimes = 0;

    for (int i = 0; i < n; ++i)
    {
        if (!isPrime(arr[i]))
        {
            product = (product * arr[i]) % MOD;
            hasNonPrimes = 1;
        }
    }

    if (hasNonPrimes)
    {
        printf("%lld\n", product);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
