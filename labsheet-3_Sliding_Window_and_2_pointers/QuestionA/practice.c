#include <stdio.h>

int isPalindrome(char substring[], int length)
{
    int start = 0;
    int end = length - 1;
    int result = 1;
    while (start <= end)
    {
        if (substring[start++] != substring[end--])
        {
            result = 0;
            return result;
        }
    }
    return result;
}

int main()
{
    // taking input
    int n;
    scanf("%d", &n);
    char string[n];
    scanf("%s", string);
    //
    int longest = 0;
    int current = 0;
    char substring[n + 1];
    //
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int pointer = 0;
            for (int k = i; k <= j; k++)
            {
                substring[pointer++] = string[k];
            }
            substring[pointer] = '\0';
            if (isPalindrome(substring, pointer))
            {
                current = pointer;
                if (current > longest)
                {
                    longest = current;
                }
            }
        }
    }
    printf("%d", longest);
    return 0;
}