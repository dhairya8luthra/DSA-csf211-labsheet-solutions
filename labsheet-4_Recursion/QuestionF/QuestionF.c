#include <stdio.h>

int findCombinations(int index, int combinations, int target_sum, int arr[], int n)
{
    // Base case
    if (index == n)
    {
        if (target_sum == 0)
        {
            return combinations + 1;
        }
        return combinations;
    }

    // Pick up elements
    if (arr[index] <= target_sum)
    {
        combinations = findCombinations(index, combinations, target_sum - arr[index], arr, n);
    }
    combinations = findCombinations(index + 1, combinations, target_sum, arr, n);
    return combinations;
}

int main()
{
    // Taking input
    int n, target_sum;
    scanf("%d", &n);
    scanf("%d", &target_sum);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Initialize variables
    int index = 0;
    int combinations = 0;

    // Find combinations
    combinations = findCombinations(index, combinations, target_sum, arr, n);

    printf("%d", combinations);

    return 0;
}
