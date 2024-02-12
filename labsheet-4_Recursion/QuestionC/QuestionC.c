#include <stdio.h>

// Recursive function to explore all combinations and find the maximum possible rating
int takeAllCombinations(int max_possible_rating, int previous_sum, int n, int *ratings, int *time, int total_time, int index)
{
    // Base case: If the total_time is 0, return the max_possible_rating achieved so far
    if (total_time == 0)
    {
        return max_possible_rating;
    }

    // Additional base case: If total_time becomes negative, this combination is not feasible, return 0
    if (total_time < 0)
    {
        return 0;
    }

    // Update total_time and previous_sum based on the current task
    total_time -= time[index];
    previous_sum += ratings[index];

    // Additional check: If total_time becomes negative after the update, this combination is not feasible, return 0
    if (total_time < 0)
    {
        return 0;
    }

    // Update max_possible_rating if the current combination achieves a higher rating
    if (previous_sum > max_possible_rating)
    {
        max_possible_rating = previous_sum;
    }

    // Explore all combinations by recursively calling the function with the next index
    for (int i = index + 1; i < n; i++)
    {
        int result = takeAllCombinations(max_possible_rating, previous_sum, n, ratings, time, total_time, i);

        // Update max_possible_rating with the result if it's higher
        if (result > max_possible_rating)
        {
            max_possible_rating = result;
        }
    }

    return max_possible_rating;
}

int main()
{
    int n;
    int total_time;
    scanf("%d", &n);
    scanf("%d", &total_time);

    int ratings[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ratings[i]);
    }

    int time[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &time[i]);
    }

    int max_possible_rating = 0;
    int previous_sum = 0;
    int index = 0;
    // approach: the approach is backtracking all combinations until we get a sum and comparing that
    // sum with max_sum

    // Call the recursive function to find the maximum possible rating
    max_possible_rating = takeAllCombinations(max_possible_rating, previous_sum, n, ratings, time, total_time, index);

    // Print the result
    printf("%d", max_possible_rating);

    return 0;
}
