#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char sentence[n];
    scanf("% [^\n]s", sentence);
    //
    int result_pointer = 0;
    int pointer = n - 1;
    char reversed_words[n];
    char result[n];
    //
    for (int i = 0; i < n; i++)
    {
        if (sentence[i] != ' ')
        {
            reversed_words[pointer--] = sentence[i];
        }
        else
        {
            reversed_words[pointer] = '\0';
            while (pointer < n - 1)
            {
                result[result_pointer++] = reversed_words[++pointer];
            }
            if (i < n - 1)
            {
                result[result_pointer++] = ' ';
            }
            pointer = n - 1;
        }
    }
    while (pointer < n - 1)
    {
        result[result_pointer++] = reversed_words[++pointer];
    }
    result[result_pointer] = '\0';
    printf("%s", result);
    return 0;
}