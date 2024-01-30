#include <stdio.h>

// Function to find the maximum subarray sum using Kadane's algorithm
long long maxSubArraySum(int arr[], int size)
{
    long long maxEndingHere = arr[0];
    long long maxSoFar = arr[0];
    // kadane's algorithm
    for (int i = 1; i < size; i++)
    {
        maxEndingHere = (arr[i] > maxEndingHere + arr[i]) ? arr[i] : maxEndingHere + arr[i];
        maxSoFar = (maxEndingHere > maxSoFar) ? maxEndingHere : maxSoFar;
    }

    return maxSoFar;
}

int main()
{
    int N;
    // Input the number of revenue plans
    scanf("%d", &N);

    // Input the revenue plans
    int plans[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &plans[i]);
    }

    // Find and print the highest possible revenue
    printf("%lld\n", maxSubArraySum(plans, N));

    return 0;
}
