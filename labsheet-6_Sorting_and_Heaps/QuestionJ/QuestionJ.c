#include <stdio.h>
#include <stdlib.h>

// Structure to represent a time slot
typedef struct
{
    int start;
    int end;
} TimeSlot;

// Function to compare TimeSlots for sorting
int compareTimeSlots(const void *a, const void *b)
{
    return ((TimeSlot *)a)->start - ((TimeSlot *)b)->start;
}

// Function to merge overlapping slots
void mergeSlots(TimeSlot *slots, int n)
{
    if (n <= 1)
    {
        return;
    }

    // Initialize an empty result array
    TimeSlot *result = (TimeSlot *)malloc(n * sizeof(TimeSlot));
    int resultIndex = 0;

    // Sort the slots based on starting times
    qsort(slots, n, sizeof(TimeSlot), compareTimeSlots);

    // Initialize the first slot as the current slot
    TimeSlot currentSlot = slots[0];

    // Iterate through the rest of the slots
    for (int i = 1; i < n; ++i)
    {
        // If the current slot and the next slot overlap, merge them
        if (currentSlot.end >= slots[i].start)
        {
            currentSlot.end = (currentSlot.end > slots[i].end) ? currentSlot.end : slots[i].end;
        }
        else
        {
            // If there is no overlap, add the current slot to the result and update the current slot
            result[resultIndex++] = currentSlot;
            currentSlot = slots[i];
        }
    }

    // Add the last merged or unmerged slot to the result
    result[resultIndex++] = currentSlot;

    // Print the merged slots
    printf("%d\n", resultIndex);
    for (int i = 0; i < resultIndex; ++i)
    {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    // Free allocated memory
    free(result);
}

int main()
{
    // Input
    int n;
    scanf("%d", &n);

    TimeSlot *slots = (TimeSlot *)malloc(n * sizeof(TimeSlot));

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &slots[i].start, &slots[i].end);
    }

    // Output
    mergeSlots(slots, n);

    // Free allocated memory
    free(slots);

    return 0;
}
