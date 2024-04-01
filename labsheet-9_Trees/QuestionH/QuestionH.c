#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left, *right;
};

struct node *createnode(int key)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}

long long sumofdistances(struct node *root, int distance)
{
    long long sum = 0;
    if (root != NULL)
    {
        sum += distance; // Adding distance from root to current node

        // Recursively calculating sum of distances for left and right subtrees
        sum += sumofdistances(root->left, distance + 1);
        sum += sumofdistances(root->right, distance + 1);
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    // Reading the tree nodes into an array
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Building the binary tree
    struct node *root = createnode(arr[0]);
    struct node *current;
    for (int i = 1; i < n; i++)
    {
        current = root;
        while (1)
        {
            if (arr[i] < current->info)
            {
                if (current->left == NULL)
                {
                    current->left = createnode(arr[i]);
                    break;
                }
                else
                    current = current->left;
            }
            else
            {
                if (current->right == NULL)
                {
                    current->right = createnode(arr[i]);
                    break;
                }
                else
                    current = current->right;
            }
        }
    }

    // Calculate and print the sum of distances
    printf("%lld\n", sumofdistances(root, 0));

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
