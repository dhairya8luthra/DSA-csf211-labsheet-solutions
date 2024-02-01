#include <stdio.h>
// why does left love peanut butter yaar
int main()
{
    // taking input
    int length;
    scanf("%d", &length);
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
    // intiialisation
    int maximum_weight = 0;
    int left_pointer = 0;
    int right_pointer = length - 1;
    int left_sum = arr[left_pointer];
    int right_sum = arr[right_pointer];
    // approach set 2 pointers one from left andd one from right
    // and add weights to left sum and right sum
    // when they are equal set them to max weight
    // until they cross each other

    while (left_pointer < right_pointer)
    {
        // adding to right sum and left sum
        if (left_sum > right_sum)
        {
            right_pointer--;
            right_sum += arr[right_pointer];
        }
        if (right_sum > left_sum)
        {
            left_pointer++;
            left_sum += arr[left_pointer];
        }
        if (left_sum == right_sum)
        {
            maximum_weight = right_sum;
            left_pointer++;
            right_pointer--;
            right_sum += arr[right_pointer];
            left_sum += arr[left_pointer];
        }
    }
    printf("%d", maximum_weight);
    return 0;
}