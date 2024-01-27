#include <stdio.h>

int main()
{
    // taking input
    int n;
    scanf("%d", &n);
    char words[n];
    scanf(" %[^\n]s", words); // %[^\n]s to read the entire line including spaces

    // init
    char reversed_word[n];
    int pointer = n - 1;
    char result[n];
    int j = 0;
    int word_length = 0;

    // traversal
    for (int i = 0; i < n; i++)
    {
        if (words[i] != ' ')
        {
            word_length++;
            reversed_word[pointer] = words[i];
            pointer--;
        }
        else
        {
            reversed_word[pointer] = '\0'; // null character to mark the end of a word

            // putting the word in result
            while (pointer < n - 1)
            {
                result[j++] = reversed_word[++pointer];
            }

            // adding space
            if (i < n - 1) // Check if not the last character
            {
                result[j++] = ' ';
            }

            // resetting the pointer and word_length
            pointer = n - 1;
            word_length = 0;
        }
    }

    // Process the last word
    while (pointer < n - 1)
    {
        result[j++] = reversed_word[++pointer];
    }

    // Null-terminate the result
    result[j] = '\0';

    printf("%s", result);
    return 0;
}
