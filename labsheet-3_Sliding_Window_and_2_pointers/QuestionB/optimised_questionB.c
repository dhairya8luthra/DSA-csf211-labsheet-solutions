#include <stdio.h>

// Funtion to convert to integers
int getint(int c)
{
    if (c >= 97)
    {
        return c - 97;
    }
    else
    {
        return c - 65;
    }
}

void main()
{
    // Getting length of string
    int n;
    scanf("%d", &n);

    // Discarding the \n character
    getchar();

    // Taking input
    char str[n + 1];
    scanf("%[^\n]s", str);

    // Setting initial values
    int FLAG = 0;
    int max = 0, curr = 0, start = 0;

    for (int i = 0; i < n; i++)
    {
        // Converting letters to integers ranging from 0 to 25
        int x = getint(str[i]);

        // Checking the x'th bit
        int T = FLAG & (1 << x);

        if (T != 0)
        {
            // Reducing the window size if finding a duplicate
            do
            {
                FLAG &= ~(1 << getint(str[start])); // Removing letter from set
                start++;
                curr--;
            } while (str[start] != str[i]);

            FLAG |= (1 << x);
        }

        else
        {
            // Not repeating so increasing the forward pointer
            FLAG |= (1 << x); // Updating the set
            curr++;
        }

        if (curr > max)
        {
            max = curr;
        }
    }
    printf("%d", max);
}
