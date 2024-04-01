#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    bool isRed;
    struct node *parent;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->isRed = true; // New nodes are always red
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *bstInsert(struct node *root, struct node *newNode)
{
    if (root == NULL)
        return newNode;

    if (newNode->data < root->data)
    {
        root->left = bstInsert(root->left, newNode);
        root->left->parent = root;
    }
    else if (newNode->data > root->data)
    {
        root->right = bstInsert(root->right, newNode);
        root->right->parent = root;
    }

    return root;
}

void leftRotate(struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(struct node *y)
{
    struct node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

void fixViolation(struct node *root, struct node *pt)
{
    struct node *parent_pt = NULL;
    struct node *grand_parent_pt = NULL;

    while ((pt != root) && (pt->isRed) && (pt->parent->isRed))
    {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left)
        {
            struct node *uncle_pt = grand_parent_pt->right;

            if (uncle_pt != NULL && uncle_pt->isRed)
            {
                grand_parent_pt->isRed = true;
                parent_pt->isRed = false;
                uncle_pt->isRed = false;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->right)
                {
                    leftRotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rightRotate(grand_parent_pt);
                bool temp = parent_pt->isRed;
                parent_pt->isRed = grand_parent_pt->isRed;
                grand_parent_pt->isRed = temp;
                pt = parent_pt;
            }
        }
        else
        {
            struct node *uncle_pt = grand_parent_pt->left;

            if (uncle_pt != NULL && uncle_pt->isRed)
            {
                grand_parent_pt->isRed = true;
                parent_pt->isRed = false;
                uncle_pt->isRed = false;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->left)
                {
                    rightRotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                leftRotate(grand_parent_pt);
                bool temp = parent_pt->isRed;
                parent_pt->isRed = grand_parent_pt->isRed;
                grand_parent_pt->isRed = temp;
                pt = parent_pt;
            }
        }
    }

    root->isRed = false;
}

void enqueue(struct node **queue, int *rear, struct node *data)
{
    queue[*rear] = data;
    (*rear)++;
}

struct node *dequeue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

bool isQueueEmpty(int front, int rear)
{
    return (front == rear);
}

void levelOrderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    struct node *queue[100000];
    int front = 0, rear = 0;
    enqueue(queue, &rear, root);

    while (!isQueueEmpty(front, rear))
    {
        struct node *current = dequeue(queue, &front);
        printf("%d ", current->data);
        if (current->left != NULL)
            enqueue(queue, &rear, current->left);
        if (current->right != NULL)
            enqueue(queue, &rear, current->right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    root = createNode(arr[0]);

    for (int i = 1; i < n; ++i)
    {
        struct node *newNode = createNode(arr[i]);
        root = bstInsert(root, newNode);
        fixViolation(root, newNode);
    }

    levelOrderTraversal(root);

    return 0;
}
