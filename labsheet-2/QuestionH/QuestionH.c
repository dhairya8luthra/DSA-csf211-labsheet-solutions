#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int prices[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prices[i]);
    }

    int max_profit = 0;
    int profit = 0;

    for (int j = 1; j < n; j++)
    {
        if (prices[j] > prices[j - 1])
        {
            profit += (prices[j] - prices[j - 1]);
        }
        else
        {
            if (max_profit < profit)
            {
                max_profit = profit;
            }
            profit = 0;
        }
    }

    if (max_profit < profit)
    {
        max_profit = profit;
    }

    printf("The Max Profit is %d", max_profit);

    return 0;
}
