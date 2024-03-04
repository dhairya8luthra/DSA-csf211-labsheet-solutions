#include <stdio.h>
#include <stdlib.h>

// Define a struct to store information about unique elements
struct UniqueElement
{
    int value;
    int firstOccurrenceIndex;
    double frequency; // Change data type to double
};

// Function to swap two unique elements
void swap(struct UniqueElement *arr, int i, int j)
{
    struct UniqueElement temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Counting sort based on frequency for unique elements array
void countingSortUniqueElements(struct UniqueElement *arr, int n)
{
    // Find the maximum frequency
    double maxFreq = 0;
    for (int i = 0; i < n; i++)
    {
        maxFreq = (arr[i].frequency > maxFreq) ? arr[i].frequency : maxFreq;
    }

    // Counting sort based on frequency
    int count[(int)maxFreq + 1];
    struct UniqueElement output[n];

    for (int i = 0; i <= (int)maxFreq; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[(int)arr[i].frequency]++;
    }

    for (int i = 1; i <= (int)maxFreq; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(int)arr[i].frequency] - 1] = arr[i];
        count[(int)arr[i].frequency]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    // Create an array to store the input elements
    int arr[n];

    // Read the input array
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Initialize an array to store information about unique elements
    struct UniqueElement uniqueArr[n];
    int uniqueCount = 0;

    // Initialize frequency and first occurrence index for each unique element
    for (int i = 0; i < n; i++)
    {
        int isUnique = 1;

        for (int j = 0; j < uniqueCount; j++)
        {
            if (uniqueArr[j].value == arr[i])
            {
                isUnique = 0;
                uniqueArr[j].frequency++;
                break;
            }
        }

        if (isUnique)
        {
            uniqueArr[uniqueCount].value = arr[i];
            uniqueArr[uniqueCount].firstOccurrenceIndex = i;
            uniqueArr[uniqueCount].frequency = 1.0; // Initialize frequency as double
            uniqueCount++;
        }
    }
    for (int i = 0; i < uniqueCount; i++)
    {
        // Adjust frequency as specified
        uniqueArr[i].frequency += i * 0.1 / (uniqueArr[i].firstOccurrenceIndex + 1);
    }

    // Sort the array of unique elements based on frequency using counting sort
    countingSortUniqueElements(uniqueArr, uniqueCount);

    // Adjust frequency before printing each unique element

    for (int i = 0; i < uniqueCount; i++)
    {
        // Print each unique element that many times its (int)frequency
        for (int j = 0; j < (int)uniqueArr[i].frequency; j++)
        {
            printf("%d ", uniqueArr[i].value);
        }
    }

    return 0;
}
