#include <stdio.h>

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    char answer[n];
    answer[0] = 'K';
    int groupsize = a / b;
    int i = 1;
    while (i < n)
    {
        if ((i + 1) % (groupsize + 1) == 0)
        {
            answer[i] = 'O';
        }
        else
        {
            answer[i] = 'K';
        }
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%c", answer[i]);
    }
    return 0;
}