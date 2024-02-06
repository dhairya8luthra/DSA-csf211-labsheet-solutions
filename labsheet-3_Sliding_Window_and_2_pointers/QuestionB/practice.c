#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char word[n];
    scanf("%s", word);
    int longest = 0;
    int current = 0;
    int endofcurrent = 0;
    int current_l = 0;
    int map[26] = {0};
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
        current_l = endofcurrent - current + 1;
        if (current_l > longest)
        {
            longest = current_l;
        }
    }
    printf("%d", longest);
}