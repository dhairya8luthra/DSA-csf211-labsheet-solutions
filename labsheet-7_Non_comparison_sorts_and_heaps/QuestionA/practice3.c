#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void countsort(int arr[], int n, int exp)
{
    int base = 16;
    int count[base];
    int output[n];
    for (int i = 0; i < base; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % base]++;
    }
    for (int i = 1; i < base; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        output[--(count[(arr[i] / exp) % base])] = arr[i];
    }
}
void radixsort(int arr[], int n, int k)
{
    for (int i = 1; i < pow(16, k); i *= 16)
    {
        countsort(arr, n, i);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int hexnumbers[n];
    for (int i = 0; i < n; i++)
    {
        char hexstring[101];
        scanf("%s", hexstring);
        hexnumbers[i] = strtol(hexstring, NULL, 16);
    }
    radixsort(hexnumbers, n, k);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", hexnumbers[i]);
    }
    return 0;
}