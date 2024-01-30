#include <stdio.h>

int main()
{
    int l;
    scanf("%d", &l);
    int revenue[l];
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &revenue[i]);
    }

    long long maxsofar = revenue[0];
    long long maxendinghere = revenue[0];

    for (int j = 1; j < l; j++)
    {
        maxendinghere = revenue[j] > maxendinghere + revenue[j] ? revenue[j] : maxendinghere + revenue[j];
        maxsofar = maxsofar > maxendinghere ? maxsofar : maxendinghere;
    }

    printf("%lld", maxsofar);

    return 0;
}
