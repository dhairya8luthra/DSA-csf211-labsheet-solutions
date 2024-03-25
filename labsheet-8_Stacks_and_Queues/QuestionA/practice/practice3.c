#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000000

char pop(char stack[], int *top)
{
    char c = stack[(*top)];
    (*top)--;
    return c;
}
void push(char stack[], int *top, char c)
{
    (*top)++;
    stack[(*top)] = c;
}
int main()
{
    char stack[MAX_SIZE];
    int top = -1;
    int isNo = 0;
    char st[MAX_SIZE];
    scanf("%s", st);
    int n = strlen(st);
    for (int i = 0; i < n; i++)
    {
        if (st[i] == '(' || st[i] == '{' || st[i] == '[')
        {
            push(stack, &top, st[i]);
        }
        else
        {
            if (top == -1)
            {
                isNo = 1;
                break;
            }
            char c = pop(stack, &top);
            if ((st[i] == ')' && c != '(') || (st[i] == ']' && c != '[') || (st[i] == '}' && c != '{'))
            {
                isNo = 1;
                break;
            }
        }
    }
    if (top != -1)
    {
        isNo = 1;
    }
    if (isNo)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
}