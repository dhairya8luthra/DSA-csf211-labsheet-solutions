#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Using counting sort to sort the elements based on the significant place value
void countingSort(int arr[], int n, int exp)
{
    const int base = 16; // Hexadecimal base
    int output[n];
    int count[base];
    for (int i = 0; i < base; i++)
        count[i] = 0;

    // Count the occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % base]++;

    // Update count[i] to store the position of the digit in output
    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[--(count[(arr[i] / exp) % base])] = arr[i];
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(int arr[], int n, int k)
{

    // Process each digit from right to left up to the k-th digit
    for (int exp = 1; exp <= pow(16, k); exp *= 16)
        countingSort(arr, n, exp);
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
        hexNumbers[i] = (int)strtol(hexString, NULL, 16); // Convert hex string to integer
    }

    radixSort(hexNumbers, n, k);

    // Print the sorted array as hexadecimal strings
    for (int i = 0; i < n; i++)
    {
        printf("%X ", hexNumbers[i]);
    }

    return 0;
}
