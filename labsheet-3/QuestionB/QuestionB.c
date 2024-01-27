#include <stdio.h>

int main()
{
    int len;
    // creating a map to count occurences
    int map[26] = {0};
    // taking input & initialisation
    scanf("%d", &len);
    char word[len];
    int current = 0;
    int endofcurrent = 0;
    int curr_l = 0;
    int longest = 0;
    scanf("%s", word);
    //
    for (int i = 0; i < len; i++)
    {
        if (!(map[(int)word[i] - 97]))
        {
            map[(int)word[i] - 97] = 1;
            endofcurrent = i;
            curr_l = endofcurrent - current + 1;
        }
        else
        {
            current = i + 1;
            if (curr_l > longest)
            {
                longest = curr_l;
            }
            // Reset the map for the next substring
            for (int j = 0; j < 26; j++)
            {
                map[j] = 0;
            }
        }
    }
    if (curr_l > longest)
    {
        longest = curr_l;
    }
    printf("%d", longest);
}