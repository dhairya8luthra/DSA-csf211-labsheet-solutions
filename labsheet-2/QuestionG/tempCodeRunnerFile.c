#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int revenues[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &revenues[i]);
    }

    int contiguous = 0;
    int max_profit = 0;
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (!contiguous && (revenues[i] >= 0))
        {
            contiguous = 1;
            profit = revenues[i];
        }
        if (contiguous && (revenues[i] >= 0))
        {
            profit += revenues[i];
        }
        if (revenues[i] < 0)
        {
            contiguous = 0;
            profit = 0;
        }
        if (profit > max_profit)
        {
            max_profit = profit;
        }
    }

    printf("%d\n", max_profit);
    return 0;
}
