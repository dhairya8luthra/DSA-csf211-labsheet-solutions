#include <stdio.h>

int main()
{
    int n;
    printf("Please Enter the Number of Days: ");
    scanf("%d", &n);

        printf("\nPlease Enter the Prices: ");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nPlease Enter the Element: ");
        scanf("%d", &arr[i]);
    }

    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            maxProfit += (arr[i] - arr[i - 1]);
        }
    }
    printf("%d is the max profit\n", maxProfit);

    return 0;
}
