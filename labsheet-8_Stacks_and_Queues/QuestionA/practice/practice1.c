#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000000

void push(char c, char Stack[], int *top)
{
    (*top)++;
    Stack[*top] = c;
}

char pop(char Stack[], int *top)
{
    char c = Stack[*top];
    (*top)--;
    return c;
}

int main()
{
    char Stack[MAX_SIZE];
    int top = -1;
    char st[MAX_SIZE];
    scanf("%s", st);

    int isNo = 0;
    int n = strlen(st);

    if (n == 0)
    {
        printf("YES");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (st[i] == '(' || st[i] == '[' || st[i] == '{')
        {
            push(st[i], Stack, &top);
        }
        else
        {
            if (top == -1)
            {
                printf("NO");
                isNo = 1;
                break;
            }
            char c = pop(Stack, &top);
            if ((st[i] == ')' && c != '(') || (st[i] == ']' && c != '[') || (st[i] == '}' && c != '{'))
            {
                printf("NO");
                isNo = 1;
                break;
            }
        }
    }

    if (top != -1 && !isNo)
    {
        printf("NO");
        isNo = 1;
    }

    if (!isNo)
    {
        printf("YES");
    }

    return 0;
}
