#include <stdio.h>
#include <math.h>

// Function to check if the probable salary is within bounds
int inBounds(int probable_salary[], int n, int lower_bound, int upper_bound)
{
    long long salary = 0;
    for (int i = 0; i < n; i++)
    {
        int power = n - 1 - i;
        salary += probable_salary[i] * pow(10, power);
    }
    if (salary <= upper_bound && salary >= lower_bound)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to calculate the sum of digits in a probable salary
int digitSum(int probable_salary[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += probable_salary[i];
    }
    return sum;
}

// Function to check if the probable salary is valid based on sum_of_digits and bounds
int isValid(int probable_salary[], int n, int sum_of_digits, int lower_bound, int upper_bound)
{
    if (digitSum(probable_salary, n) == sum_of_digits)
    {
        if (inBounds(probable_salary, n, lower_bound, upper_bound))
        {
            return 1;
        }
    }
    return 0;
}

// Recursive function to find the number of valid salaries
int find_valid_salary(int possible_salary[], int n, int index, int sum_of_digits, int lower_bound, int upper_bound, int count)
{
    // Base case when we have checked all elements of the array
    if (index == n)
    {
        return count + isValid(possible_salary, n, sum_of_digits, lower_bound, upper_bound);
    }

    // Check if the current digit is unknown (denoted by -1)
    if (possible_salary[index] == -1)
    {
        int start = (index == 0) ? 1 : 0;
        // check from 1-9 if first digit else check from 0 -9
        for (int i = start; i < 10; i++)
        {
            possible_salary[index] = i;
            count += find_valid_salary(possible_salary, n, index + 1, sum_of_digits, lower_bound, upper_bound, count);
        }
        // Reset the digit for backtracking
        possible_salary[index] = -1;
    }
    else
    {
        // If the digit is known, proceed to the next index
        count += find_valid_salary(possible_salary, n, index + 1, sum_of_digits, lower_bound, upper_bound, count);
    }

    return count;
}

int main()
{
    // Taking input
    int n, sum_of_digits, lower_bound, upper_bound;
    scanf("%d %d %d %d", &n, &sum_of_digits, &lower_bound, &upper_bound);

    char possible_salary_str[n + 1];
    scanf("%s", possible_salary_str);

    int possible_salary[n];
    for (int i = 0; i < n; i++)
    {
        if (possible_salary_str[i] == '?')
        {
            possible_salary[i] = -1;
        }
        else
        {
            possible_salary[i] = possible_salary_str[i] - '0';
        }
    }

    // Approach: We need to permutate all digits where -1 is stored and check for
    // sum of digits and if there, add to count. We use backtracking on possible digits.

    int count = 0;
    count = find_valid_salary(possible_salary, n, 0, sum_of_digits, lower_bound, upper_bound, count);
    printf("%d", count);

    return 0;
}
