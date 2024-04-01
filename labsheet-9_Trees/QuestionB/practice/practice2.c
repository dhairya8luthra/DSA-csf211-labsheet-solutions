#include <stdio.h>
#include <stdio.h>
typedef struct Treenode
{
    int val;
    struct Treenode *left;
    struct Treenode *right;
} Treenode;

Treenode *createnode(int value)
{
    Treenode *newnode = (Treenode *)malloc(sizeof(Treenode));
    newnode->val = value;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}
Treenode buildtree(int n, int arr[])
{
    Treenode **nodes = (Treenode **)malloc(sizeof(Treenode) * n);
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
    return isSubtree(a->left, b) || isSubtree(a->right, b);
}
int main()
{
    int n, k;
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
        printf("NO");
    }
}