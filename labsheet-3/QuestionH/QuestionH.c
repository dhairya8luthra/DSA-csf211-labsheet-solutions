#include <stdio.h>

int maxSatisfiedClients(int deals[], int n, int k)
{
    long long currentSatisfied = 0;
    long long maxSatisfied = 0;

    // Calculate the maximum number of satisfied clients for the first k deals
    for (int i = 0; i < k; ++i)
    {
        currentSatisfied |= deals[i];
    }
    maxSatisfied = __builtin_popcountll(currentSatisfied);

    // Iterate through the remaining deals
    for (int i = k; i < n; ++i)
    {
        // Remove the leftmost deal from the current set
        currentSatisfied ^= deals[i - k];
        // Add the current deal to the set
        currentSatisfied |= deals[i];

        // Update the maximum satisfied clients
        maxSatisfied = maxSatisfied > __builtin_popcountll(currentSatisfied) ? maxSatisfied : __builtin_popcountll(currentSatisfied);
    }

    return maxSatisfied;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int deals[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &deals[i]);
    }

    int result = maxSatisfiedClients(deals, n, k);
    printf("%d\n", result);

    return 0;
}
