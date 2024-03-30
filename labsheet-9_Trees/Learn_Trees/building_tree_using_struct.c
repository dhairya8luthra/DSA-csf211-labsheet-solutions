#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode *createNode(int val)
{
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    new_node->left = NULL;
    new_node->value = val;
    new_node->right = NULL;
    return new_node;
}

// Function to print the tree with the root at the top
void printTree(TreeNode *root, int space)
{
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Print right child first
    printTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    // Print left child
    printTree(root->left, space);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Creating n tree nodes
    TreeNode **nodes = (TreeNode **)malloc(sizeof(TreeNode) * n);
    for (int i = 0; i < n; i++)
    {
        nodes[i] = createNode(arr[i]);
    }

    // Linking the tree nodes to each other
    for (int i = 1; i < n; i++)
    {
        int parent_index = (i - 1) / 2;
        if (2 * parent_index + 1 == i)
            nodes[parent_index]->left = nodes[i];
        else
            nodes[parent_index]->right = nodes[i];
    }

    // Printing the tree
    printf("Tree structure:\n");
    printTree(nodes[0], 0); // Assuming nodes[0] is the root of the tree

    // Freeing dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        free(nodes[i]);
    }
    free(nodes);

    return 0;
}
