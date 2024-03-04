#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void countingSort(int arr[], int n, int exp)
{
    int base = 16;
    int output[n];
    int count[base];
    for (int i = 0; i < base; i++)
    {
        count[i] = 0;
    }
    // count occurences of each digit
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % base]++;
    }
    for (int i = 1; i < base; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[--(count[(arr[i] / exp) % base])] = arr[i];
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n, int k)
{
    for (int exp = 1; exp <= pow(16, k); exp *= 16)
    {
        countingSort(arr, n, exp);
    }
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int hexNumbers[n];
    for (int i = 0; i < n; i++)
    {
        char hexString[101];
        scanf("%s", hexString);
        hexNumbers[i] = (int)strtol(hexString, NULL, 16);
    }
    radixSort(hexNumbers, n, k);
    for (int i = 0; i < n; i++)
    {
        printf("%X ", hexNumbers[i]);
    }
}