#include <stdio.h>

int main()
{
    int l;
    scanf("%d", &l);
    int prices[l];

    for (int i = 0; i < l; i++)
    {
        scanf("%d", &prices[i]);
    }
    int profit = 0;
    int max_profit = 0;
    for (int i = 1; i < l; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
        else
        {

            if (profit > max_profit)
            {
                max_profit = profit;
            }
            profit = 0;
        }
    }
    if (profit > max_profit)
    {
        max_profit = profit;
    }
    printf("%d", max_profit);
    return 0;
}