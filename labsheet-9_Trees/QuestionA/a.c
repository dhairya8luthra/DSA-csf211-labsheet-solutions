#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode *createNode(int value)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to calculate the maximum path sum
int max_path_sum_helper(TreeNode *node, int *max_sum)
{
    if (!node)
        return 0;

    // Calculate the maximum path sum from the left and right subtrees
    int left_sum = max_path_sum_helper(node->left, max_sum);
    int right_sum = max_path_sum_helper(node->right, max_sum);

    // Update the maximum path sum found so far
    *max_sum = (*max_sum > node->value + left_sum + right_sum) ? *max_sum : node->value + left_sum + right_sum;

    // Return the maximum path sum ending at this node
    return (node->value + ((left_sum > right_sum) ? left_sum : right_sum));
}

// Function to calculate the maximum path sum of a binary tree
int max_path_sum(TreeNode *root)
{
    if (!root)
        return 0;

    int max_sum = 0;
    max_path_sum_helper(root, &max_sum);
    return max_sum;
}

int main()
{
    int n;
    scanf("%d", &n); // Read the size of the array representing the binary tree

    int *values = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &values[i]); // Read the values of Peanut Butter jars

    // Construct the binary tree
    TreeNode **nodes = (TreeNode **)malloc(n * sizeof(TreeNode *));
    for (int i = 0; i < n; ++i)
        nodes[i] = createNode(values[i]);
    for (int i = 1; i < n; ++i)
    {
        int parent_index = (i - 1) / 2;
        if (2 * parent_index + 1 == i)
            nodes[parent_index]->left = nodes[i];
        else
            nodes[parent_index]->right = nodes[i];
    }

    // Calculate and print the maximum path sum
    printf("%d\n", max_path_sum(nodes[0]));

    // Free dynamically allocated memory
    free(values);
    for (int i = 0; i < n; ++i)
        free(nodes[i]);
    free(nodes);

    return 0;
}