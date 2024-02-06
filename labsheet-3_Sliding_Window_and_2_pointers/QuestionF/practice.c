#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int window_length;
    scanf("%d", &window_length);
    int average;
    scanf("%d", &average);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //
    float curr_avg;
    float curr_sum = 0;
    int count = 0;
    int start = 0;
    int end = start + window_length - 1;
    for (int i = start; i <= end; i++)
    {
        curr_sum += arr[i];
    }
    curr_avg = curr_sum / (float)window_length;
    if (curr_avg >= average)
    {
        count++;
    }
    start++;
    end++;
    while (end < n)
    {
        curr_avg += ((float)(arr[end] - arr[start - 1])) / (float)window_length;
        if (curr_avg >= average)
        {
            count++;
        }
        start++;
        end++;
    }
    printf("%d\n", count);
    return (0);
}