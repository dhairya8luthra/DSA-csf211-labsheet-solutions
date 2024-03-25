#include <stdio.h>
#include <stdlib.h>

// Structure to represent elements in the stack
typedef struct
{
    int index;
    int value;
} StackElement;

// Structure to represent the stack
typedef struct
{
    int top;
    StackElement *array;
} Stack;

// Function to initialize a stack
Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (StackElement *)malloc(size * sizeof(StackElement));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int index, int value)
{
    stack->top++;
    stack->array[stack->top].index = index;
    stack->array[stack->top].value = value;
}

// Function to pop an element from the stack
StackElement pop(Stack *stack)
{
    return stack->array[stack->top--];
}

// Function to find the next greater elements
void nextGreaterElements(int *weights, int n, int *result)
{
    Stack *stack = createStack(n);
    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(stack) && weights[i] > stack->array[stack->top].value)
        {
            StackElement element = pop(stack);
            result[element.index] = i - element.index;
        }
        push(stack, i, weights[i]);
    }
    while (!isEmpty(stack))
    {
        StackElement element = pop(stack);
        result[element.index] = 0;
    }
    free(stack->array);
    free(stack);
}

// Function to find the next smaller elements
void nextSmallerElements(int *weights, int n, int *result)
{
    Stack *stack = createStack(n);
    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(stack) && weights[i] < stack->array[stack->top].value)
        {
            StackElement element = pop(stack);
            result[element.index] = i - element.index;
        }
        push(stack, i, weights[i]);
    }
    while (!isEmpty(stack))
    {
        StackElement element = pop(stack);
        result[element.index] = 0;
    }
    free(stack->array);
    free(stack);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *weights = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    int *nextGreater = (int *)calloc(n, sizeof(int));
    int *nextSmaller = (int *)calloc(n, sizeof(int));

    nextGreaterElements(weights, n, nextGreater);
    nextSmallerElements(weights, n, nextSmaller);

    // Output the results
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nextGreater[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nextSmaller[i]);
    }
    printf("\n");

    return 0;
}
