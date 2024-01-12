#include <stdio.h>

int main()
{
    char num1[1000];
    char num2[1000];
    char sum[10000] = {'0'};
    int i, j;
    int digit;
    int carry = 0;
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
    int k = i;
    i--;
    j--;
    int l = k;
    while (i >= 0 || j >= 0)
    {
        if (j >= 0)
        {
            digit = (num1[i] - '0') + (num2[j] - '0') + carry;
            carry = digit / 10;
            digit = digit % 10;
            sum[k] = digit + '0';
            i--;
            j--;
            k--;
        }
        else
        {
            digit = (num1[i] - '0') + carry;
            carry = digit / 10;
            digit = digit % 10;
            sum[k] = digit + '0';
            i--;
            k--;
        }
    }
    sum[k] = carry + '0';
    int head = 0;
    while (sum[head] == '0')
    {
        head++;
    }
    if (head == l)
    {
        printf('0');
    }
    else
    {
        for (; head <= l; head++)
        {
            printf("%c", sum[head]);
        }
    }
    return 0;
}