#include <stdio.h>

int isPalindrome(char substring[], int len)
{
    int start = 0;
    int end = len - 1;
    int result = 1;
    while (start <= end)
    {
        if (substring[start] != substring[end])
        {
            result = 0;
        }
        start++;
        end--;
    }
    return result;
}

int main()
{
    // taking input
    int n;
    scanf("%d", &n);
    char word[n];
    scanf("%s", word);

    int longest = 0;
    char substring[n + 1];
    int current = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int pointer = 0;
            for (int k = i; k <= j; k++)
            {
                substring[pointer] = word[k];
                pointer++;
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
