#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode
{
    int val;
    struct Treenode *left;
    struct Treenode *right;
} Treenode;

Treenode *createnode(int value)
{
    Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
    new_node->val = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node; // Return the newly created node
}

Treenode *buildtree(int n, int arr[])
{
    Treenode **nodes = (Treenode **)malloc(n * sizeof(Treenode *));
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
    // Linking
    Treenode *root = nodes[0];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nodes[i] == NULL)
        {
            count++;
            continue;
        }
        int leftindex = 2 * i + 1 - 2 * count;
        int rightindex = 2 * i + 2 - 2 * count;
        if (leftindex < n)
        {
            nodes[i]->left = nodes[leftindex];
        }
        if (rightindex < n)
        {
            nodes[i]->right = nodes[rightindex];
        }
    }
    return root;
}

int isIdentical(Treenode *rootA, Treenode *rootB)
{
    if (rootA == NULL && rootB == NULL)
    {
        return 1;
    }
    if (rootA == NULL || rootB == NULL)
    {
        return 0;
    }
    if (rootA->val != rootB->val)
    {
        return 0;
    }
    return isIdentical(rootA->left, rootB->left) && isIdentical(rootA->right, rootB->right);
}

int isSubtree(Treenode *rootA, Treenode *rootB)
{
    if (rootB == NULL)
    {
        return 1;
    }
    if (rootA == NULL)
    {
        return 0;
    }
    if (isIdentical(rootA, rootB))
    {
        return 1;
    }
    return isSubtree(rootA->left, rootB) || isSubtree(rootA->right, rootB);
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
    Treenode *communityroot = buildtree(n, arr1);
    Treenode *handroot = buildtree(k, arr2);
    if (isSubtree(communityroot, handroot))
    {
        printf("WIN");
    }
    else
    {
        printf("LOSS");
    }

    return 0;
}
