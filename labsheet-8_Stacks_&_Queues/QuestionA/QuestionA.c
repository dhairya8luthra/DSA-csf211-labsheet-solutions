#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

// Define a structure for stack
struct Stack
{
    char arr[MAX_SIZE];
    int top;
};

// Function to create an empty stack
struct Stack *createStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char c)
{
    stack->arr[++stack->top] = c;
}

// Function to pop an element from the stack
char pop(struct Stack *stack)
{
    if (stack->top == -1)
        return '\0'; // Stack is empty
    return stack->arr[stack->top--];
}

// Function to check if the given string is a valid parentheses string
char *isValidParentheses(char *s)
{
    int n = strlen(s);
    struct Stack *stack = createStack();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(stack, s[i]);
        }
        else
        {
            if (stack->top == -1)
                return "NO"; // Closing bracket with no corresponding opening bracket
            char c = pop(stack);
            if ((s[i] == ')' && c != '(') || (s[i] == ']' && c != '[') || (s[i] == '}' && c != '{'))
                return "NO"; // Mismatched closing and opening brackets
        }
    }

    if (stack->top != -1)
        return "NO"; // Unmatched opening brackets left in the stack

    return "YES"; // All brackets matched
}

int main()
{
    char s[MAX_SIZE];
    fgets(s, MAX_SIZE, stdin);
    s[strcspn(s, "\n")] = '\0'; // Removing trailing newline character from fgets

    printf("%s\n", isValidParentheses(s));

    return 0;
}
