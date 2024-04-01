#include <stdio.h>
#include <stdlib.h>
typedef struct Treenode
{
    int val;
    struct Treenode *left;
    struct Treenode *right;
} Treenode;

int maxf(int a, int b)
{
    return (a > b ? a : b);
}
Treenode *createnode(int value)
{
    Treenode *node = (Treenode *)malloc(sizeof(Treenode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
}
//
Treenode *buildtree(int arr[], int n)
{
    Treenode **nodes = (Treenode **)malloc(n * (sizeof(Treenode)));
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
            int leftindex = 2 * i + 1 - (2 * count);
            int rightindex = 2 * i + 2 - (2 * count);
            if (leftindex < n)
            {
                nodes[i]->left = nodes[leftindex];
            }
            if (rightindex < n)
            {
                nodes[i]->right = nodes[rightindex];
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
    int leftorright = maxf(maxf(left, right) + root->val, root->val);
    int withroot = maxf(leftorright, left + right + root->val);
    *maxSum = maxf(*maxSum, withroot);
    return leftorright;
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
    Treenode *root = buildtree(A, n);
    int maxSum = 0;
    maxsum(root, &maxSum);
    printf("%d", maxSum);
    return 0;
}