#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int inOrder[], int start, int end, int value, int *index)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (inOrder[i] == value)
        {
            *index = i;
            return i;
        }
    }
    return -1;
}

struct Node *buildTree(int inOrder[], int preOrder[], int start, int end, int *preIndex)
{
    if (start > end)
        return NULL;

    struct Node *root = newNode(preOrder[*preIndex]);
    (*preIndex)++;

    if (start == end)
        return root;

    int inIndex;
    search(inOrder, start, end, root->data, &inIndex);

    root->left = buildTree(inOrder, preOrder, start, inIndex - 1, preIndex);
    root->right = buildTree(inOrder, preOrder, inIndex + 1, end, preIndex);

    return root;
}

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node **queue = (struct Node **)malloc(sizeof(struct Node *) * 1000);
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front != rear)
    {
        struct Node *temp = queue[front++];

        if (temp == NULL)
        {
            printf("-1 ");
            continue;
        }

        printf("%d ", temp->data);

        queue[rear++] = temp->left;
        queue[rear++] = temp->right;
    }

    free(queue);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *inOrder = (int *)malloc(sizeof(int) * n);
    int *preOrder = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &inOrder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &preOrder[i]);

    int preIndex = 0;
    struct Node *root = buildTree(inOrder, preOrder, 0, n - 1, &preIndex);

    levelOrder(root);
    printf("\n");

    free(inOrder);
    free(preOrder);

    return 0;
}