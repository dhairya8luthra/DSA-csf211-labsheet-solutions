#include <stdio.h>

int isVowel(char letter)
{
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}
int main()
{
    int n;
    scanf("%d", &n);
    char sentence[n];
    scanf(" %[^\n]s", sentence);
    int found_left = 0;
    int found_right = 0;
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        if (!found_left && isVowel(sentence[start]))
        {
            found_left = 1;
        }
        else if (!found_left)
        {
            start++;
        }
        if (!found_right && isVowel(sentence[end]))
        {
            found_right = 1;
        }
        else if (!found_right)
        {
            end--;
        }
        if (found_left && found_right)
        {
            found_left = 0;
            found_right = 0;
            char temp = sentence[start];
            sentence[start] = sentence[end];
            sentence[end] = temp;
            start++;
            end--;
        }
    }
    printf("%s", sentence);
    return 0;
}