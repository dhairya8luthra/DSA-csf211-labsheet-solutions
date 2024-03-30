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

// Function to construct the binary tree from the given array
TreeNode *constructTree(int arr[], int n)
{
    TreeNode **nodes = (TreeNode **)malloc(n * sizeof(TreeNode *));
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            nodes[i] = NULL;
        }
        else
        {
            nodes[i] = createNode(arr[i]);
        }
    }

    TreeNode *root = nodes[0];
    for (int i = 0; i < n; i++)
    {
        if (nodes[i] != NULL)
        {
            int leftChildIdx = 2 * i + 1;
            int rightChildIdx = 2 * i + 2;
            if (leftChildIdx < n)
            {
                nodes[i]->left = nodes[leftChildIdx];
            }
            if (rightChildIdx < n)
            {
                nodes[i]->right = nodes[rightChildIdx];
            }
        }
    }

    free(nodes);
    return root;
}

// Function to cut the specified node from the tree
TreeNode *cutNode(TreeNode *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->value == target)
    {
        free(root);
        return NULL;
    }
    root->left = cutNode(root->left, target);
    root->right = cutNode(root->right, target);
    return root;
}

// Function to calculate the height of the tree
int heightOfTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Construct the binary tree
    TreeNode *root = constructTree(arr, n);

    // Cut the specified node
    root = cutNode(root, k);

    // Calculate the height of the remaining tree
    int remainingHeight = heightOfTree(root);

    // Output the result
    printf("%d\n", remainingHeight);

    return 0;
}
