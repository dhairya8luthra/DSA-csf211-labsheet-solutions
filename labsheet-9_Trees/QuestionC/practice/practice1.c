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
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->val = value;
    return new_node;
}
Treenode *buildtree(int n, int arr[])
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

void deletenode(Treenode *root, int target)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left->val == target)
    {
        root->left = NULL;
    }
    else if (root->right->val == target)
    {
        root->right = NULL;
    }
    else
    {
        deletenode(root->left, target);
        deletenode(root->right, target);
    }
}

int height(Treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        return (leftheight > rightheight) ? (leftheight + 1) : (rightheight + 1);
    }
}
int main()
{
    int n, target;
    scanf("%d %d", &n, &target);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Treenode *root = buildtree(n, arr);
    deletenode(root, target);
    int h = height(root);
    printf("%d", h);
    return 0;
}