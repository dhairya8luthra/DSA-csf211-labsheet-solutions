#include <stdio.h>

int main()
{
    // Variables for number 1
    int num;
    scanf("%d", &num);
    int precision = 6;

    // Finding square root for number 1
    int start = 0, end = num;
    int mid;
    float ans;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (mid * mid == num)
        {
            ans = mid;
            break;
        }
        if (mid * mid < num)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    float increment = 0.1;
    for (int i = 0; i < precision; i++)
    {
        while (ans * ans <= num)
        {
            ans += increment;
        }
        ans = ans - increment;
        increment = increment / 10;
    }

    // Printing result for number 1
    printf("%.6f\n", ans);

    return 0;
}
