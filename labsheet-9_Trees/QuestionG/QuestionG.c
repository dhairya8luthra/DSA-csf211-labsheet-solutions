#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper function to find the LCA
TreeNode *findLCA(TreeNode *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->val == n1 || root->val == n2)
        return root;

    TreeNode *leftLCA = findLCA(root->left, n1, n2);
    TreeNode *rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Function to find the LCA
int LCA(TreeNode *root, int n1, int n2)
{
    TreeNode *lca = findLCA(root, n1, n2);
    if (lca != NULL)
        return lca->val;
    else
    {
        printf("Please enter valid input\n");
        return -1;
    }
}

// Function to build tree from array
TreeNode *buildTreeFromArray(int arr[], int index, int n)
{
    TreeNode *root = NULL;
    if (index < n)
    {
        TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
        temp->val = arr[index];
        temp->left = buildTreeFromArray(arr, 2 * index + 1, n);
        temp->right = buildTreeFromArray(arr, 2 * index + 2, n);
        root = temp;
    }
    return root;
}

int main()
{
    // Input array representing the tree
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Building tree from array
    TreeNode *root = buildTreeFromArray(arr, 0, n);

    // Finding LCAs
    printf("LCA of 2 and 3 is %d\n", LCA(root, 2, 3));

    return 0;
}
