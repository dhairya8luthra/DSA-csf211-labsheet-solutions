#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    int high = num;
    int low = 0;
    int mid;
    float ans = 0;
    int precision = 6;
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
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    // now we have the integer part of the number lets find the float part
    float increment = 0.1;
    for (int i = 0; i < precision; i++)
    {
        while (ans * ans <= num)
        {
            ans += increment;
        }
        ans -= increment;
        increment /= 10;
    }
    printf("%.6f", ans);
    return 0;
}