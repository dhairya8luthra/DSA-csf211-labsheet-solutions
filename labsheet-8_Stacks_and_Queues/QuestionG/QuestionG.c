#include <stdio.h>
#include <stdlib.h>

int count_subarrays(int n, int k, int *arr)
{
    int result = 0;
    int *window = (int *)malloc(n * sizeof(int));
    int left = 0, right = 0;
    int min_val = arr[0], max_val = arr[0];

    while (right < n)
    {
        // Update min_val and max_val
        min_val = (arr[right] < min_val) ? arr[right] : min_val;
        max_val = (arr[right] > max_val) ? arr[right] : max_val;

        // Remove elements from the left side of the window that violate the condition
        while (max_val - min_val > k)
        {
            if (arr[left] == min_val)
            {
                min_val = max_val;
                for (int i = left + 1; i <= right; i++)
                {
                    min_val = (arr[i] < min_val) ? arr[i] : min_val;
                }
            }
            if (arr[left] == max_val)
            {
                max_val = min_val;
                for (int i = left + 1; i <= right; i++)
                {
                    max_val = (arr[i] > max_val) ? arr[i] : max_val;
                }
            }
            left++;
        }

        // Count the number of subarrays that satisfy the condition
        result += right - left + 1;
        right++;
    }

    free(window);
    return result;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = count_subarrays(n, k, arr);
    printf("%d\n", result);

    free(arr);
    return 0;
}