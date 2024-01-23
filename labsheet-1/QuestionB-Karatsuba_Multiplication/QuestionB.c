
#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1000

// Function to add two strings representing numbers
void addStrings(const char *num1, const char *num2, char result[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;

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
}

// Function to multiply two strings representing numbers using Karatsuba algorithm
void karatsubaMultiply(const char *x, const char *y, char result[])
{
    int n = strlen(x);

    // Base case: if n is 1, compute the product and return
    if (n == 1)
    {
        snprintf(result, 2, "%d", (x[0] - '0') * (y[0] - '0'));
        return;
    }

    // Split the input numbers into halves
    int half = n / 2;
    const char *a = x;
    const char *b = x + half;
    const char *c = y;
    const char *d = y + half;

    // Recursive steps
    char p[MAX_DIGITS], q[MAX_DIGITS], ac[MAX_DIGITS], bd[MAX_DIGITS], pq[MAX_DIGITS], adbe[MAX_DIGITS];

    addStrings(a, b, p);
    addStrings(c, d, q);

    karatsubaMultiply(b, d, ac); // Use 'y' for the second half
    karatsubaMultiply(a, c, bd);
    karatsubaMultiply(p, q, pq);

    // Calculate adbe
    addStrings(pq, ac, adbe);
    addStrings(adbe, bd, adbe);

    // Combine the results using the Karatsuba formula
    addStrings(ac, "0", result);
    addStrings(result, adbe, result);
    addStrings(result, "0", result);
    addStrings(result, bd, result);
}

int main()
{
    // Input
    char num1[MAX_DIGITS], num2[MAX_DIGITS];
    scanf("%s %s", num1, num2);

    // Output
    char result[2 * MAX_DIGITS];
    karatsubaMultiply(num1, num2, result);
    printf("%s\n", result);

    return 0;
}
