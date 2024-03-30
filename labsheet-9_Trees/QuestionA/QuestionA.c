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
    return new_node;
}
/////////////////

//////////max_sum function
// approach recursively check the max sum for left sub tree sum and right sub tree and then which ever is higher add that and if that node is reducing the sum dont include it
int max_path_sum(TreeNode *node, int *max_sum)
{
    if (!node)
        return 0;

    // Calculate the maximum path sum from the left and right subtrees
    int left_sum = max_path_sum(node->left, max_sum);
    int right_sum = max_path_sum(node->right, max_sum);

    *max_sum = (*max_sum > node->value + left_sum + right_sum) ? *max_sum : node->value + left_sum + right_sum;

    // Return the maximum path sum ending at this node
    return (node->value + ((left_sum > right_sum) ? left_sum : right_sum));
}

////////////////////////////////////
// main function

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
    TreeNode **nodes = (TreeNode **)malloc(sizeof(TreeNode) * n);
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
    int max_sum = 0;
    max_path_sum(nodes[0], &max_sum);
    printf("%d ", max_sum);
}