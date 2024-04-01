#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
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

// Function to insert a new node in BST
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

// Function to perform in-order traversal and find the k-th largest node
void findKthLargest(TreeNode *root, int k, int *count, int *result)
{
    if (root == NULL || *count >= k)
        return;

    // Traverse right subtree first
    findKthLargest(root->right, k, count, result);

    // If kth largest element is found
    if (++(*count) == k)
    {
        *result = root->data;
        return;
    }

    // Traverse left subtree
    findKthLargest(root->left, k, count, result);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int values[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &values[i]);
    }

    // Construct BST
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }

    // Initialize count and result variables
    int count = 0, result = -1;

    // Find k-th largest node
    findKthLargest(root, k, &count, &result);

    // Output result
    printf("%d\n", result);

    return 0;
}
