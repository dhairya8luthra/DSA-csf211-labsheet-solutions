#include <stdio.h>

// Function to convert a given number into words
void convert_to_words(long long n)
{
    // Define arrays for units, teens, and tens places
    char *units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    // Helper function to convert numbers below 1000
    void convert_below_thousand(int num)
    {
        if (num >= 100)
        {
            printf("%s hundred", units[num / 100]);
            num %= 100;
            if (num > 0)
            {
                printf(" ");
            }
        }

        if (num >= 11 && num <= 19)
        {
            printf("%s", teens[num - 11]);
        }
        else if (num >= 20)
        {
            printf("%s", tens[num / 10]);
            num %= 10;
            if (num > 0)
            {
                printf(" ");
            }
        }

        if (num >= 1 && num <= 9)
        {
            printf("%s", units[num]);
        }
    }

    if (n == 0)
    {
        printf("zero");
        return;
    }

    // Extract billions, millions, thousands, and remaining
    int billion = n / 1000000000;
    int million = (n % 1000000000) / 1000000;
    int thousand = (n % 1000000) / 1000;
    int remaining = n % 1000;

    // Convert billions
    if (billion > 0)
    {
        convert_below_thousand(billion);
        printf(" billion");
        if ((million > 0 || thousand > 0 || remaining > 0))
        {
            printf(" ");
        }
    }

    // Convert millions
    if (million > 0)
    {
        convert_below_thousand(million);
        printf(" million");
        if (thousand > 0 || remaining > 0)
        {
            printf(" ");
        }
    }

    // Convert thousands
    if (thousand > 0)
    {
        convert_below_thousand(thousand);
        printf(" thousand");
        if (remaining > 0)
        {
            printf(" ");
        }
    }

    // Convert remaining
    if (remaining > 0)
    {
        convert_below_thousand(remaining);
    }
}

int main()
{
    long long n;
    scanf("%lld", &n);
    convert_to_words(n);
    return 0;
}
