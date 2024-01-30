#include <stdio.h>

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);

    long long int revenues[N];

    // Input the array of annual revenues
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &revenues[i]);
    }

    // Process Q queries
    for (int i = 0; i < Q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);

        // Calculate cumulative revenue for the given range
        long long int cumulativeRevenue = 0;
        for (int j = l - 1; j <= r - 1; j++)
        {
            cumulativeRevenue += revenues[j];
        }

        // Output the result for this query
        printf("%lld\n", cumulativeRevenue);
    }

    return 0;
}
