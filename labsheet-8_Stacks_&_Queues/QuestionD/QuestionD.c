#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int n;
    scanf("%d", &n);

    int heights[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &heights[i]);

    int stack[n]; // stack to store indices of histogram bars
    int top = -1; // initialize stack top

    int max_area = 0;
    int i = 0;
    while (i < n)
    {
        if (top == -1 || heights[stack[top]] <= heights[i])
            stack[++top] = i++; // push current index to stack
        else
        {
            int tp = stack[top--];                                                  // store the top index and pop from stack
            int area_with_top = heights[tp] * (top == -1 ? i : i - stack[top] - 1); // calculate area with the popped bar as the smallest bar
            max_area = MAX(max_area, area_with_top);                                // update maximum area if needed
        }
    }

    while (top != -1)
    {
        int tp = stack[top--];                                                  // store the top index and pop from stack
        int area_with_top = heights[tp] * (top == -1 ? i : i - stack[top] - 1); // calculate area with the popped bar as the smallest bar
        max_area = MAX(max_area, area_with_top);                                // update maximum area if needed
    }

    printf("%d\n", max_area);

    return 0;
}
