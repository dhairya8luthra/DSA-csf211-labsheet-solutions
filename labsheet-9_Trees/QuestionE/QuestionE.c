#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *constructTreeUtil(int post[], int *postIndex,
                               int key, int min, int max, int size)
{
    if (*postIndex < 0)
        return NULL;

    struct node *root = NULL;

    if (key > min && key < max)
    {
        root = newNode(key);
        *postIndex = *postIndex - 1;

        if (*postIndex >= 0)
        {
            root->right = constructTreeUtil(post, postIndex, post[*postIndex],
                                            key, max, size);

            root->left = constructTreeUtil(post, postIndex, post[*postIndex],
                                           min, key, size);
        }
    }

    return root;
}

struct node *constructTree(int post[], int size)
{
    int postIndex = size - 1;
    return constructTreeUtil(post, &postIndex, post[postIndex],
                             INT_MIN, INT_MAX, size);
}

void levelOrder(struct node *root)
{
    if (root == NULL)
        return;

    struct node *queue[100]; // Assuming maximum of 100 nodes
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front != rear)
    {
        struct node *curr = queue[front++];

        if (curr == NULL)
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ", curr->data);

            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
    }
}

int main()
{
    int post[] = {1, 3, 2};
    int size = sizeof(post) / sizeof(post[0]);

    struct node *root = constructTree(post, size);

    printf("Level-order traversal of the constructed tree: \n");
    levelOrder(root);

    return 0;
}