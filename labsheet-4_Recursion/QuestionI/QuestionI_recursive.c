#include <stdio.h>

int main()
{
    long long n, k;
    // printf("Enter the number of digits (n): ");
    scanf("%lld", &n);
    //  printf("Enter the required sum of digits (k): ");
    scanf("%lld", &k);

    if (k > 9 * n)
    {
        printf("-1\n");
    }
    else
    {
        if (k == 0 && n > 1)
        {
            printf("-1\n");
        }
        else if (k == 1 && n > 1)
        {
            printf("1");
            for (long long i = 0; i < n - 1; i++)
            {
                printf("0");
            }
            printf("\n");
        }
        else
        {
            int digits[n];
            for (long long i = 0; i < n; i++)
            {
                digits[i] = 0;
            }

            long long remainingSum = k;
            long long i = 0;
            while (remainingSum > 0)
            {
                long long add = (remainingSum > 9) ? 9 : remainingSum;
                digits[i++] += add;
                remainingSum -= add;
            }

            int allZeroes = 1;
            for (long long i = 0; i < n; i++)
            {
                if (digits[i] != 0)
                {
                    allZeroes = 0;
                    break;
                }
            }

            if (allZeroes)
            {
                printf("-1\n");
            }
            else
            {
                // printf("The minimum number is: ");
                for (long long i = n - 1; i >= 0; i--)
                {
                    printf("%d", digits[i]);
                }
                printf("\n");
            }
        }
    }

    if (k == 0 && n == 1)
    {
        printf("0");
    }
    else if (k > 9 * n || k == 0)
    {
        printf("-1\n");
    }
    else
    {
        long long int i;
        for (i = 0; i < k / 9; i++)
        {
            printf("9");
        }
        if (k % 9 != 0)
        {
            printf("%lld", k % 9);
        }
        for (i = 0; i < n - (k / 9 + (k % 9 != 0)); i++)
        {
            printf("0");
        }
    }

    return 0;
}