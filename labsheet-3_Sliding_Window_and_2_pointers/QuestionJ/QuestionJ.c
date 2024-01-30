#include <stdio.h>

#define MOD 1000000007

long long modPow(long long base, long long exponent)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    long long a[n], b[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &b[i]);
    }

    long long product = 1;

    for (int i = 0; i < n; ++i)
    {
        long long poweredValue = modPow(a[i], b[i]);
        product = (product * poweredValue) % MOD;
    }

    printf("%lld\n", product);

    return 0;
}
// final solved