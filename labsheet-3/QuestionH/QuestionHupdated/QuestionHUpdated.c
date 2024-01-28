#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int maxSatisfiedClients = 0;

    for (int i = 0; i < 60; i++)
    {
        int currentSatisfiedClients = 0;

        for (int j = 0; j < n; j++)
        {
            if ((a[j] >> i) & 1)
            {
                currentSatisfiedClients++;
            }
        }

        maxSatisfiedClients += (currentSatisfiedClients >= k) ? k : currentSatisfiedClients;
    }

    printf("%d\n", maxSatisfiedClients);

    return 0;
}
