#include <stdio.h>

int main()
{
    // taking input
    int length;
    scanf("%d", &length);
    int window_length;
    scanf("%d", &window_length);
    int avg;
    scanf("%d", &avg);
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
    // initialisation and approach
    // we have to use sliding window approach
    // window size is window_length;
    //
    int window_start = 0;
    int window_end = window_start + window_length - 1;
    int count = 0;
    int sum_curr = 0;
    // calculating average so i dont have to traverse the window again and again
    for (int i = window_start; i < window_end + 1; i++)
    {
        sum_curr += arr[i];
    }
    float avg_curr = sum_curr / window_length;
    if (avg_curr >= avg)
    {
        count++;
    }
    window_start++;
    window_end++;
    while (window_end < length)
    {
        // search for the condition in the window
        avg_curr += (arr[window_end] - arr[window_start - 1]) / window_length;
        if (avg_curr >= avg)
        {
            count++;
        }
        window_start++;
        window_end++;
    }
    printf("%d", count);
    return 0;
}