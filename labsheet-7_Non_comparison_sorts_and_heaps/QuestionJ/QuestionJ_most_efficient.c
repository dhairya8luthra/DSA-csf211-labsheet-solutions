#include <stdio.h>
int main()
{
    int n, threshold;
    scanf("%d %d", &n, &threshold);
    int hp[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &hp[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (hp[i] < threshold)
        {
            k++;
        }
    }
    printf("%d\n", k);
    for (int i = 0; i < n; i++)
    {
        if (hp[i] < threshold)
        {
            printf("%d ", i + 1);
        }
    }
    return 0;
}