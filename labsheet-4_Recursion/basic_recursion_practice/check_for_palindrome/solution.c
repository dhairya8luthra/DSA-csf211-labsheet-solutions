#include <stdio.h>

int check_for_palindrome(int n, int i, char *str)
{
    if (i >= n / 2)
    {
        return 1;
    }
    if (str[i] != str[n - 1 - i])
    {
        return 0;
    }
    else
    {
        return check_for_palindrome(n, ++i, str);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char str[n];

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &str[i]); // Corrected format specifier to %c
    }

    if (check_for_palindrome(n, 0, str))
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }

    return 0;
}
