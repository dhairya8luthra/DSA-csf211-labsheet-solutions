#include <stdio.h>

void multiply(char num1[], char num2[], char result[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int lenResult = len1 + len2;

    int carry, i, j, k, temp;
    int resultArray[lenResult];

    // Initialize resultArray with zeros
    for (i = 0; i < lenResult; i++)
    {
        resultArray[i] = 0;
    }

    // Multiply each digit and add to resultArray
    for (i = 0; i < len1; i++)
    {
        carry = 0;
        for (j = 0; j < len2; j++)
        {
            temp = (num1[len1 - 1 - i] - '0') * (num2[len2 - 1 - j] - '0') + carry + resultArray[i + j];
            carry = temp / 10;
            resultArray[i + j] = temp % 10;
        }
        resultArray[i + len2] += carry;
    }

    // Find the first non-zero digit from the right in resultArray
    k = lenResult - 1;
    while (k >= 0 && resultArray[k] == 0)
    {
        k--;
    }

    // If result is 0, set the result to "0"
    if (k == -1)
    {
        result[0] = '0';
        result[1] = '\0';
    }
    else
    {
        // Convert resultArray to a string
        for (i = 0; k >= 0; i++, k--)
        {
            result[i] = resultArray[k] + '0';
        }
        result[i] = '\0';
    }
}

int main()
{
    char num1[100], num2[100], result[200];

    // Input two non-negative numbers as strings
    printf("Enter the first number: ");
    scanf("%s", num1);

    printf("Enter the second number: ");
    scanf("%s", num2);

    // Call the multiply function
    multiply(num1, num2, result);

    // Output the result
    printf("Multiplication Result: %s\n", result);

    return 0;
}
