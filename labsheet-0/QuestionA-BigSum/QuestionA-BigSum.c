#include <stdio.h>

int main()
{
    char num1[1000];
    char num2[1000];
    int digit;
    int carry = 0;
    char sum[10000] = {'0'};
    int i, j;

    printf("Enter the first number: ");
    scanf("%s", num1);
    printf("Enter the second number: ");
    scanf("%s", num2);

    for (i = 0; num1[i] != '\0'; i++)
    {
    }
    for (j = 0; num2[j] != '\0'; j++)
    {
    }

    i--;
    j--;

    int k = i + 1;
    int l = k;
    while (j >= 0)
    {
        digit = carry + (num1[i] - '0') + (num2[j] - '0');
        carry = digit / 10;
        digit %= 10;

        sum[k] = digit + '0';
        k--;
        i--;
        j--;
    }

    sum[k] += carry + '0';

    int head = 0;
    while (sum[head] == '0')
    {
        head++;
    }

    if (head == l + 1)
    {
        printf("0");
    }
    else
    {
        head = head + 1;
        for (; head <= l; head++)
        {
            printf("%c", sum[head]);
        }
    }

    return 0;
}
