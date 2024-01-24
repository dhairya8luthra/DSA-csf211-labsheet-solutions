#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    int precision = 6;
    float ans = 0;
    int high = num;
    int low = 0;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (mid * mid == num)
        {
            ans = mid;
            printf("%f", ans);
            return 0;
        }
        if (mid * mid < num)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // now that we have the integer part we need to find the floart part of the number;
    float increment = 0.1;
    for (int i = 0; i < precision; i++)
    {
        while (ans * ans < num)
        {
            ans += increment;
        }
        ans -= increment;
        increment /= 10;
    }
    printf("%0.6f", ans);
    return 0;
}