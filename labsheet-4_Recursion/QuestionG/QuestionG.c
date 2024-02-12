#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
char *multiply(char subs[], int factor)
{
    int length = strlen(subs) * factor + 1;
    char *result = (char *)malloc(length);

    // Fill the result array by repeating the substring 'factor' times
    for (int i = 0; i < length - 1; i++)
    {
        result[i] = subs[i % strlen(subs)];
    }
    result[length - 1] = '\0'; // Null-terminate the result string

    return result;
}
char *findLCM(char *a, char *b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);

    // Calculate GCD of lengths of strings
    int gcdLen = gcd(lenA, lenB);

    // Calculate LCM using the formula
    int lcmLen = (lenA * lenB) / gcdLen;

    // Allocate memory for the result string
    char *lcm = malloc(lcmLen + 1);

    // Construct the LCM string
    for (int i = 0; i < lcmLen; i++)
    {
        lcm[i] = a[i % lenA];
    }

    // Null-terminate the LCM string
    lcm[lcmLen] = '\0';

    return lcm;
}

int main()
{
    // Input strings
    char a[1000001], b[1000001];

    // Read input strings
    scanf("%s", a);
    scanf("%s", b);

    // Determine the lengths of the input strings
    int n = strlen(a), m = strlen(b);

    // Determine the smaller string and its length
    int smaller = (n >= m) ? m : n;
    char *smallerArr = (n >= m) ? b : a;

    // Variable to check if LCM exists
    int isLCM = 0;

    // Iterate over possible subsequence lengths
    for (int i = 1; i <= smaller; i++)
    {
        // Extract the subsequence from the smaller string
        char subsequence[i + 1];
        strncpy(subsequence, smallerArr, i);
        subsequence[i] = '\0'; // Null-terminate the subsequence

        // Check if both strings are built using the same subsequence
        int factor1 = n / strlen(subsequence);
        int factor2 = m / strlen(subsequence);

        if (strcmp(multiply(subsequence, factor1), a) == 0 && strcmp(multiply(subsequence, factor2), b) == 0)
        {
            printf("%s\n", multiply(subsequence, factor1));
            isLCM = 1; // LCM exists
            break;
        }
    }

    if (!isLCM)
    {
        printf("-1\n");
    }
    if (isLCM)
    {
        char *lcm = findLCM(a, b);
        printf("%s\n", lcm);
        free(lcm);
    }

    return 0;
}
