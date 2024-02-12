#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &arr[i][j]);
        }
        scanf("\n");
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i][j] == '*')
            {
                for (int k = i; k < n && arr[k + 1][j] == '.'; k++)
                {
                    arr[k + 1][j] = '*';
                    arr[k][j] = '.';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}