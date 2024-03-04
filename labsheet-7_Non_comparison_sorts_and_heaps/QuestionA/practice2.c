#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void countingsort(int arr[], int n, int exp)
{
    int base = 16;
    int count[16];
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
        count[i] += count[i - 1]
    }
    for (int i = 0; i < n; i++)
    {
        output[--(count[(arr[i] / exp) % base])] = arr[i];
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n, int k)
{
    for (int i = 1; i < pow(16, k); i *= 16)
    {
        countingsort(arr, n, i);
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
        hexnumbers[i] = stringtol(hexstring, NULL, 16)
    }
    radixsor(hexnumbers, n, k);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", hexnumbers[i]);
    }
}