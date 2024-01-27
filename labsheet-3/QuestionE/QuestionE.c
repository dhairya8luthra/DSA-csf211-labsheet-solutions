#include <stdio.h>

int main()
{
    // taking input
    int arr1len;
    int arr2len;
    scanf("%d", &arr1len);
    scanf("%d", &arr2len);
    int arr1[arr1len];
    int arr2[arr2len];
    for (int i = 0; i < arr1len; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < arr2len; i++)
    {
        scanf("%d", &arr2[i]);
    }
    // initialisation and approach
    // make 2 pointers 1 on array and 1 on array2 keep copying down elements
    // from bigger array until a smaller element from smaller array is encountered
    int result[arr1len + arr2len];
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    while ((p1 < arr1len || p2 < arr2len) && p3 < arr1len + arr2len)
    {
        int number;

        if (p1 >= arr1len)
        {
            number = arr2[p2++];
        }
        else if (p2 >= arr2len)
        {
            number = arr1[p1++];
        }
        else
        {
            number = (arr1[p1] < arr2[p2]) ? (arr1[p1++]) : (arr2[p2++]);
        }
        result[p3++] = number;
    }
    for (int i = 0; i < arr1len + arr2len; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}