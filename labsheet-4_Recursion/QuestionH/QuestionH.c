#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, a, b, k;
    scanf("%d%d%d", &n, &a, &b);
    char t[100] = {0};
    if (a % (b + 1) == 0)
    {
        k = a / (b + 1);
    }
    else
    {
        k = a / (b + 1) + 1;
    }
    for (i = 0; i < n; i += (k + 1))
    {
        for (j = i; j < i + k && j < n; j++)
        {
            t[j] = 'K';
        }
        if (i + k < n)
        {
            t[i + k] = 'O';
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%c", t[i]);
    }

    return 0;
}