#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Stack->LIFO fashion working

struct stack
{
    int size;
    int *arr; 
    int top;
};

void push(struct stack *s, int x)
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

int top(struct stack *s)
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

int prefix(char q[])
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack)); // Allocate memory for the stack
    int len = strlen(q);
    st->size = len;
    st->top = -1;
    st->arr = (int *)malloc(st->size * sizeof(int)); // Allocate memory for the array

    for (int i = len - 1; i >= 0; i--)
    {
        // Case 1: It is a number, then push it to stack
        if (q[i] >= '0' && q[i] <= '9')
        {
            push(st, q[i] - '0'); // Convert char to int to push into stack
        }
        // Case 2: It is an operator
        else
        {
            int operand1 = top(st);
            pop(st);
            int operand2 = top(st);
            pop(st);
            int res = 0;
            switch (q[i])
            {
            case '+':
                res = (operand1 + operand2);
                break;
            case '-':
                res = (operand1 - operand2);
                break;
            case '*':
                res = (operand1 * operand2);
                break;
            case '/':
                res = (operand1 / operand2);
                break;
            case '^':
                res = pow(operand1, operand2);
                break;
            default:
                break;
            }
            push(st, res);
        }
    }
    int result = top(st);
    free(st->arr); // Free the allocated memory for the array
    free(st);      // Free the allocated memory for the stack
    return result;
}

int main()
{
    char expression[] = "-++1*234/556";
    printf("Result of prefix expression evaluation: %d\n", prefix(expression));
    printf("%d ", 1 + 2 * 3 + 4 - 55 / 6);
    return 0;
}
