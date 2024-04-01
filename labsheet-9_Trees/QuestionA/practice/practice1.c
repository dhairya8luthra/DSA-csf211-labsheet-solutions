#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode
{
    int value;
    struct Treenode *left;
    struct Treenode *right;
} Treenode;
int maxf(int a, int b)
{
    return (a > b ? a : b);
}
Treenode *createnode(int val)
{
    Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
    new_node->left = NULL;
    new_node->value = val;
    new_node->right = NULL;
    return new_node; // Return the newly created node
}

Treenode *buildtree(int n, int arr[])
{
    Treenode **nodes = (Treenode **)malloc(n * sizeof(Treenode));
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            nodes[i] = NULL;
        }
        else
        {
            nodes[i] = createnode(arr[i]);
        }
    }
    // linking the tree
    Treenode *root = nodes[0];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nodes[i] == NULL)
        {
            count++;
        }
        if (nodes[i])
        {
            int leftIndex = 2 * i + 1 - (2 * count);
            int rightIndex = 2 * i + 2 - (2 * count);
            if (leftIndex < n)
            {
                nodes[i]->left = nodes[leftIndex];
            }
            if (rightIndex < n)
            {
                nodes[i]->right = nodes[rightIndex];
            }
        }
    }
    return root;
}

int maxsum(Treenode *root, int *maxSum)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maxsum(root->left, maxSum);
    int right = maxsum(root->right, maxSum);
    int leftOrRight = maxf(maxf(left, right) + root->value, root->value);
    int withRoot = maxf(leftOrRight, left + right + root->value);
    *maxSum = maxf(*maxSum, withRoot);
    return leftOrRight;
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    Treenode *root = buildtree(n, A);
    int maxSum = 0;
    maxsum(root, &maxSum);
    printf("%d", maxSum);
    return 0;
}