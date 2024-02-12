#include <stdio.h>
#include <math.h>

void findAns(int m, int k, int index, int arr[], long long *lowest, long long *highest)
{
    // Base case: when we reach index m
    if (index == m)
    {
        // Check if the current number's digits sum up to k
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += arr[i];
        }

        // Check if the sum matches the required k
        if (sum == k)
        {
            // Calculate the number represented by the array of digits
            long long number = 0;
            for (int i = 0; i < m; i++)
            {
                number = number * 10LL + arr[i];
            }

            // Update lowest and highest possible numbers
            if (*lowest == -1 || number < *lowest)
            {
                *lowest = number;
            }
            if (number > *highest)
            {
                *highest = number;
            }
        }
        return;
    }

    // Recursive calls
    int start = (index == 0) ? 1 : 0; // Leading zero is not allowed except for the first digit
    for (int i = start; i < 10; i++)
    {
        arr[index] = i;
        findAns(m, k, index + 1, arr, lowest, highest);
    }
}

int main()
{
    int m, k;
    scanf("%d %d", &m, &k);

    long long lowest_possible = -1;
    long long highest_possible = -1;
    int arr[m]; // Array to store digits

    findAns(m, k, 0, arr, &lowest_possible, &highest_possible);

    if (lowest_possible == -1 && highest_possible == -1)
    {
        printf("-1 -1\n");
    }
    else
    {
        printf("%lld %lld\n", lowest_possible, highest_possible);
    }

    return 0;
}
