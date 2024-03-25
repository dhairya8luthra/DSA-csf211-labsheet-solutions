#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pop(char Q[], int base)
{
    int offset = 1;
    while (Q[base + offset] == '0')
    {
        offset++;
    }
    return base + offset;
}

long long str_to_int(char *str)
{
    char *endptr;
    long long val = strtoll(str, &endptr, 10);
    if (*endptr != '\0')
    {
        printf("Conversion failed. Invalid character '%c' found.\n", *endptr);
    }

    return val;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char Q[n];
    scanf("%s", Q);
    int base = 0;
    for (int i = 0; i < k - 1; i++)
    {
        base = pop(Q, base);
    }
    char price_string[n - base];
    int j = 0;
    for (int i = base + 1; i < n; i++)
    {
        price_string[j] = Q[i];
        j++;
    }
    price_string[j] = '\0';
    long long new_price = str_to_int(price_string);
    long long old_price = str_to_int(Q);
    long long profit = old_price - new_price;
    printf("%lld\n", profit);
    return 0;
}
