#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *buildTree(int *arr, int *index, int size)
{
    if (*index >= size || arr[*index] == -1)
    {
        (*index)++;
        return NULL;
    }

    Node *root = createNode(arr[*index]);
    (*index)++;
    root->left = buildTree(arr, index, size);
    root->right = buildTree(arr, index, size);
    return root;
}

int isSubtree(Node *communityTree, Node *treeInHand)
{
    if (treeInHand == NULL)
    {
        return 1;
    }
    if (communityTree == NULL)
    {
        return 0;
    }
    if (communityTree->val == treeInHand->val)
    {
        if (isSubtree(communityTree->left, treeInHand->left) && isSubtree(communityTree->right, treeInHand->right))
        {
            return 1;
        }
    }
    return isSubtree(communityTree->left, treeInHand) || isSubtree(communityTree->right, treeInHand);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int *communityTreeArr = (int *)malloc(n * sizeof(int));
    int *treeInHandArr = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &communityTreeArr[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &treeInHandArr[i]);
    }

    int index = 0;
    Node *communityTree = buildTree(communityTreeArr, &index, n);
    index = 0;
    Node *treeInHand = buildTree(treeInHandArr, &index, m);

    if (isSubtree(communityTree, treeInHand))
    {
        printf("WIN\n");
    }
    else
    {
        printf("LOSS\n");
    }
    return 0;
}