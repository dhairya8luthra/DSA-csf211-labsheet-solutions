#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode
{
    int val;
    struct Treenode *right;
    struct Treenode *left;
} Treenode;

Treenode *createnode(int value)
{
    Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
Treenode *buildtree(int arr[], int n)
{
    Treenode **nodes = (Treenode **)(malloc(sizeof(Treenode) * n));
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
    // linking
    Treenode *root = nodes[0];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nodes[i] == NULL)
        {
            count++;
        }
        else
        {
            int leftindex = (2 * i + 1) - (2 * count);
            int rightindex = (2 * i + 2) - (2 * count);
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
int isIdentical(Treenode *a, Treenode *b)
{
    if (a == NULL && b == NULL)
    {
        return 1;
    }
    if (a == NULL || b == NULL)
    {
        return 0;
    }
    if (a->val != b->val)
    {
        return 0;
    }
    return isIdentical(a->right, b->right) && isIdentical(a->left, b->left);
}
int isSubtree(Treenode *a, Treenode *b)
{
    if (b == NULL)
    {
        return 1;
    }
    if (a == NULL)
    {
        return 0;
    }
    if (isIdentical(a, b))
    {
        return 1;
    }
    return (isSubtree(a->left, b)) || (isSubtree(a->right, b));
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr1[n];
    int arr2[k];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arr2[i]);
    }
    Treenode *communityroot = buildtree(arr1, n);
    Treenode *handroot = buildtree(arr2, k);

    if (isSubtree(communityroot, handroot))
    {
        printf("WIN");
    }
    else
    {
        printf("LOSS");
    }
}