#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int *top, char stack[], char val)
{
    stack[++(*top)] = val;
}
char pop(int *top, char stack[])
{
    return stack[(*top)--];
}

int main()
{
    int top = -1;
    char stack[1000];
    char input_string[1000];
    scanf("%s", &input_string);
    int n = strlen(input_string);
    for (int i = 0; i < n; i++)
    {
        if (input_string[i] == '{' || input_string[i] == '(' || input_string[i] == '[') // Correct condition
        {
            push(&top, stack, input_string[i]);
        }
        if (input_string[i] == '}' || input_string[i] == ')' || input_string[i] == ']') // Correct condition
        {
            if (top == -1) // Check if stack is empty
            {
                printf("NO");
                return 0;
            }
            char out = pop(&top, stack);
            if ((out == '{' && input_string[i] != '}') || (out == '[' && input_string[i] != ']') || (out == '(' && input_string[i] != ')'))
            {
                printf("NO");
                return 0;
            }
        }
    }
    if (top != -1) // Check if stack is empty after processing
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}
