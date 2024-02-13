#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int weights[MAX_N];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    // Initialize current distribution
    int curr_distribution[MAX_N] = {0};

    int result = min_beauty(n, k, weights, 0, curr_distribution);
    printf("%d\n", result);

    return 0;
}