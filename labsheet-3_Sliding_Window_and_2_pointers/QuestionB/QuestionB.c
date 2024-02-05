#include <stdio.h>

int main()
{
    int len;
    // creating a map to count occurrences
    int map[26] = {0};
    // taking input & initialization
    scanf("%d", &len);
    char word[len];
    int current = 0;
    int endofcurrent = 0;
    int curr_l = 0;
    int longest = 0;
    scanf("%s", word);

    for (int i = 0; i < len; i++)
    {
        if (map[(int)word[i] - 'a'] == 0 || map[(int)word[i] - 'a'] < current)
        {
            map[(int)word[i] - 'a'] = i + 1; // Update map to store position
            endofcurrent = i;
        }
        else
        {
            current = map[(int)word[i] - 'a'];
            map[(int)word[i] - 'a'] = i + 1; // Update map to store position
            endofcurrent = i;
        }

        curr_l = endofcurrent - current + 1;
        if (curr_l > longest)
        {
            longest = curr_l;
        }
    }

    printf("%d", longest);
    return 0;
}
