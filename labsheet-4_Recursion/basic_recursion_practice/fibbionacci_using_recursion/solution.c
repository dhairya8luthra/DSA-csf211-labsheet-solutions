#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;

    // Input the value of n
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    // Check if n is non-negative
    if (n < 0)
    {
        printf("Please enter a non-negative integer.\n");
        return 1; // Exit with an error code
    }

    // Print the result
    printf("Fibonacci number at position %d is %d\n", n, fibonacci(n));

    return 0;
}
