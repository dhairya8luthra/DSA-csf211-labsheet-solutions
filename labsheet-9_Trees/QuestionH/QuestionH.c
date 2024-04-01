#include <stdio.h>
#include <stdlib.h>

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

        nodes[i] = createNode(arr[i]);
    }

    TreeNode *root = nodes[0];
    for (int i = 0; i < n; i++)
    {
        if (nodes[i] != NULL && nodes[i]->value != -1)
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

long long sumofdistances(TreeNode *root, int distance)
{
    long long sum = 0;
    if (root != NULL)
    {
        if (root->value == -1)
        {

            return sum;
        }
        sum += distance;

        sum += sumofdistances(root->left, (root->value != -1) ? distance + 1 : distance);
        sum += sumofdistances(root->right, (root->value != -1) ? distance + 1 : distance);
        printf("%d ", sum);
    }
    return sum;
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

    // Construct the binary tree
    TreeNode *root = constructTree(arr, n);

    printf("%lld\n", sumofdistances(root, 0));

    return 0;
}
