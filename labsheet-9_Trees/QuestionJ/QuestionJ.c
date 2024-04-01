#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
TreeNode *insert(TreeNode *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to find the height of a binary tree
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to find the diameter of a binary tree
int diameter(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return (leftHeight + rightHeight + 1 > leftDiameter && leftHeight + rightHeight + 1 > rightDiameter) ? leftHeight + rightHeight + 1 : (leftDiameter > rightDiameter ? leftDiameter : rightDiameter);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("%d\n", diameter(root));

    free(arr);
    return 0;
}
