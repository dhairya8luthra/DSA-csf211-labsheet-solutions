#include <stdio.h>

// Structure to represent a voting slot
struct Slot
{
    int start;
    int end;
};

// Function to merge overlapping slots
void mergeSlots(struct Slot slots[], int n)
{
    // Sort slots based on starting times
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (slots[j].start > slots[j + 1].start)
            {
                // Swap slots if not in ascending order
                struct Slot temp = slots[j];
                slots[j] = slots[j + 1];
                slots[j + 1] = temp;
            }
        }
    }

    // Merge overlapping slots
    int mergedIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (slots[mergedIndex].end >= slots[i].start)
        {
            // Merge overlapping slots
            slots[mergedIndex].end = (slots[mergedIndex].end > slots[i].end) ? slots[mergedIndex].end : slots[i].end;
        }
        else
        {
            // Move to the next slot in the result
            mergedIndex++;
            slots[mergedIndex] = slots[i];
        }
    }

    // Print the merged slots
    printf("%d\n", mergedIndex + 1);
    for (int i = 0; i <= mergedIndex; i++)
    {
        printf("%d %d\n", slots[i].start, slots[i].end);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Slot slots[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &slots[i].start, &slots[i].end);
    }

    // Merge and print the result
    mergeSlots(slots, n);

    return 0;
}
