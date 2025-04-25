#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack
{
    int size;
    char *arr; // Change to char to store characters
    int top;
};

void push(struct stack *s, char x)
{
    if (s->top == s->size - 1)
    {
        printf("Stack overflow. No elements can be added\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = x;
    }
}

void pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("No more elements to pop\n");
        return;
    }
    s->top--;
}

char top(struct stack *s)
{
    if (s->top == -1)
    {
        printf("No more elements present\n");
        return -1;
    }
    return s->arr[s->top];
}

bool empty(struct stack *s)
{
    return s->top == -1;
}

bool balanced(char q[])
{
    int l = strlen(q);
    char stack[l];
    int top = -1;
    bool ans = true;

    for (int i = 0; i < l; i++)
    {
        if (q[i] == '(' || q[i] == '{' || q[i] == '[')
        {
            stack[++top] = q[i]; // Push the actual character
        }
        else if (q[i] == ')')
        {
            if (top != -1 && stack[top] == '(')
            {
                top--;
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (q[i] == '}')
        {
            if (top != -1 && stack[top] == '{')
            {
                top--;
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (q[i] == ']')
        {
            if (top != -1 && stack[top] == '[')
            {
                top--;
            }
            else
            {
                ans = false;
                break;
            }
        }
        else
        {
            ans = false;
            break;
        }
    }

    if (top != -1)
    {
        ans = false;
    }

    return ans;
}
    int main()
    {
        char exp[] = "{[](){}[[{}]]}";
        balanced(exp) ? printf(" < %s > expression is a Valid Parenthesis\n", exp) : printf("< %s > expression is a Invalid Parenthesis\n", exp);
        char exp1[] = "{))()}";
        balanced(exp1) ? printf("< %s > expression is a Valid Parenthesis\n", exp1) : printf("< %s > expression is a Invalid Parenthesis\n", exp1);
    }
