#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/////create a treenode function
TreeNode *createNode(int val)
{
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    new_node->left = NULL;
    new_node->value = val;
    new_node->right = NULL;
}
/////////////////

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    /////////Building the tree///////
    /// creating n tree nodes
    TreeNode **nodes = (TreeNode *)malloc(sizeof(TreeNode) * n);
    for (int i = 0; i < n; i++)
    {
        nodes[i] = createNode(arr[i]);
    }
    ////////linking the tree nodes to each other
    for (int i = 1; i < n; i++)
    {
        int parent_index = (i - 1) / 2;
        if (2 * parent_index + 1 == i)
            nodes[parent_index]->left = nodes[i];
        else
            nodes[parent_index]->right = nodes[i];
    }
}