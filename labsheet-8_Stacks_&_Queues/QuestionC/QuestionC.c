#include <stdio.h>
#define MOD 1000000007

long long stack[1000006], top = -1;

long long min(long long a, long long b)
{
    return (a < b) ? a : b;
}

int main()
{
    long long n, i, a[1000006], ans = 0;

    scanf("%lld", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        while (top >= 0 && a[stack[top]] > a[i])
        {
            long long j = stack[top--];
            long long left = j - (top >= 0 ? stack[top] : -1);
            long long right = i - j;
            ans = (ans + (left * right % MOD) * a[j]) % MOD;
        }
        stack[++top] = i;
    }

    while (top >= 0)
    {
        long long j = stack[top--];
        long long left = j - (top >= 0 ? stack[top] : -1) + 1;
        long long right = n - j;
        ans = (ans + (left * right % MOD) * a[j]) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
