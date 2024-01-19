#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add two strings representing numbers
char *addStrings(const char *num1, const char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;

    char *result = (char *)malloc((maxLen + 2) * sizeof(char));
    result[maxLen + 1] = '\0';

    int carry = 0;
    int i, j, k;

    for (i = len1 - 1, j = len2 - 1, k = maxLen; i >= 0 || j >= 0 || carry > 0; i--, j--, k--)
    {
        int digit1 = (i >= 0) ? (num1[i] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        result[k] = '0' + (sum % 10);
        carry = sum / 10;
    }

    return result;
}

// Function to multiply two strings representing numbers using Karatsuba algorithm
char *karatsubaMultiply(const char *x, const char *y)
{
    int n = strlen(x);

    // Base case: if n is 1, compute the product and return
    if (n == 1)
    {
        char *result = (char *)malloc(2 * sizeof(char));
        snprintf(result, 2, "%d", (x[0] - '0') * (y[0] - '0'));
        return result;
    }

    // Split the input numbers into halves
    int half = n / 2;
    const char *a = x;
    const char *b = x + half;
    const char *c = y;
    const char *d = y + half;

    // Recursive steps
    char *p = addStrings(a, b);
    char *q = addStrings(c, d);

    char *ac = karatsubaMultiply(a, c);
    char *bd = karatsubaMultiply(b, d);
    char *pq = karatsubaMultiply(p, q);

    // Calculate adbe
    char *adbe = addStrings(pq, "-");
    adbe = addStrings(adbe, ac);
    adbe = addStrings(adbe, "-");
    adbe = addStrings(adbe, bd);

    // Combine the results using the Karatsuba formula
    char *result = addStrings(ac, "0");
    result = addStrings(result, adbe);
    result = addStrings(result, "0");
    result = addStrings(result, bd);

    free(p);
    free(q);
    free(ac);
    free(bd);
    free(pq);
    free(adbe);

    return result;
}

int main()
{
    // Input
    char num1[1000], num2[1000];
    scanf("%s %s", num1, num2);

    // Output
    char *result = karatsubaMultiply(num1, num2);
    printf("%s\n", result);

    free(result);

    return 0;
}
