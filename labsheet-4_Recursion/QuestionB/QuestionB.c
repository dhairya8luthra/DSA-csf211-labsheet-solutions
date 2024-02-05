#include <stdio.h>

#define MAX_N 8

int min_beauty(int n, int k, int weights[MAX_N], int curr_index, int curr_distribution[MAX_N])
{
    // Base case: all packets are distributed
    if (curr_index == n)
    {
        int max_beauty = 0;
        for (int i = 0; i < k; i++)
        {
            if (curr_distribution[i] > max_beauty)
            {
                max_beauty = curr_distribution[i];
            }
        }
        return max_beauty;
    }

    int min_beauty_result = __INT_MAX__;

    // Try distributing the current packet to each person
    for (int i = 0; i < k; i++)
    {
        curr_distribution[i] += weights[curr_index];
        // Recursively explore the next packet
        int result = min_beauty(n, k, weights, curr_index + 1, curr_distribution);
        // Update the minimum beauty
        if (result < min_beauty_result)
        {
            min_beauty_result = result;
        }
        // Backtrack to try other distributions
        curr_distribution[i] -= weights[curr_index];
    }

    return min_beauty_result;
}

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
