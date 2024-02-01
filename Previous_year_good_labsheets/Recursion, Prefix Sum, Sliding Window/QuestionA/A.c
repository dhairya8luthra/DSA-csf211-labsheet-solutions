#include <stdio.h>

// Function to generate regular bracket sequences
void generateBracketSequences(char *sequence, int openCount, int closeCount, int n, int index)
{
    // Base case: If the sequence is complete, print it
    if (index == 2 * n)
    {
        sequence[index] = '\0';
        printf("%s\n", sequence);
        return;
    }

    // Add an open bracket if there are remaining open brackets
    if (openCount < n)
    {
        sequence[index] = '(';
        generateBracketSequences(sequence, openCount + 1, closeCount, n, index + 1);
    }

    // Add a closing bracket if it doesn't violate the regularity
    if (closeCount < openCount)
    {
        sequence[index] = ')';
        generateBracketSequences(sequence, openCount, closeCount + 1, n, index + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    n = n / 2;
    // The length of the bracket sequence is always even
    char sequence[2 * n + 1];

    // Start generating regular bracket sequences
    generateBracketSequences(sequence, 0, 0, n, 0);

    return 0;
}
