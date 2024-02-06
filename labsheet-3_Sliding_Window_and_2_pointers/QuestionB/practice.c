#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char word[n];
    int map[26] = {0};
    int current = 0;
    int endofcurrent = 0;
    int curr_l = 0;
    int longest = 0;
    scanf("%s", word);

    for (int i = 0; i < n; i++)
    {

        if (map[(int)word[i] - 'a'] == 0 || map[(int)word[i] - 'a'] < current)
        {
            map[(int)word[i] - 'a'] = i + 1;
            endofcurrent = i;
        }
        else
        {
            current = map[(int)word[i] - 'a'];
            map[(int)word[i] - 'a'] = i + 1;
            endofcurrent = i;
        }
        curr_l = endofcurrent - current + 1;
        if (curr_l > longest)
        {
            longest = curr_l;
        }
    }
    printf("%d\n", longest);
    return 0;
}