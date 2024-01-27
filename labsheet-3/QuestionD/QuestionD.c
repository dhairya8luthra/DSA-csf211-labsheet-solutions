#include <stdio.h>
// with bonus
int isVowel(char suspect)
{
    return (suspect == 'a' || suspect == 'e' || suspect == 'i' || suspect == 'o' || suspect == 'u');
}

int main()
{
    // taking input
    int n;
    scanf("%d", &n);
    char sentence[n];
    scanf(" %[^\n]s", sentence);

    // initialization and approach
    // the approach is going to be running two pointers, one from start and one from end
    // when both pointers find vowels, exchange them

    int start = 0;
    int end = n - 1;
    int found_left = 0;
    int found_right = 0;

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
            // swap
            char temp = sentence[start];
            sentence[start] = sentence[end];
            sentence[end] = temp;

            found_left = 0;
            found_right = 0;
            start++;
            end--;
        }
    }

    printf("%s", sentence);
    return 0;
}
