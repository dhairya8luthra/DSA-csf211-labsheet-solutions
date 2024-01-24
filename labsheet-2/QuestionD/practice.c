#include <stdio.h>

int main()
{
    int precision = 6;
    int num;
    scanf("%d", &num);
    float ans = 0;
    int mid;
    int high = num;
    int low = 0;
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
    // got the integer part lets find the float part
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
    printf("%0.6f", ans);
    return 0;
}