#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Stack->LIFO fashion working

struct stack
{
    int size;
    int *arr; // Change to char to store characters
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
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    int len = strlen(q);
    st->size = len;
    st->top = -1;
    st->arr = (int *)malloc(st->size * sizeof(int));

    for (int i = len - 1; i >= 0; i--)
    {
        if (q[i] >= '0' && q[i] <= '9')
        {
            push(st, q[i] - '0');
        }
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
                res = operand1 + operand2;
                break;
            case '-':
                res = operand1 - operand2;
                break;
            case '*':
                res = operand1 * operand2;
                break;
            case '/':
                res = operand1 / operand2;
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
    return top(st);
}

int postfix(char q[])
{
    // struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    // int len = strlen(q);
    // st->size = len;
    // st->top = -1;
    // st->arr = (int *)malloc(st->size * sizeof(int));
    int len = strlen(q);
    int stack[len];
    int top = -1;
    for (int i = 0; i < len; i++)
    {
        if (q[i] >= '0' && q[i] <= '9')
        {
            // push(st, q[i] - '0');
            stack[++top] = q[i] - '0';
        }
        else
        {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            int res = 0;
            switch (q[i])
            {
            case '+':
                res = operand1 + operand2;
                break;
            case '-':
                res = operand1 - operand2;
                break;
            case '*':
                res = operand1 * operand2;
                break;
            case '/':
                res = operand1 / operand2;
                break;
            case '^':
                res = pow(operand1, operand2);
                break;
            default:
                break;
            }
            stack[++top] = res;
        }
    }
    return stack[top];
}

int main(){

//      printf("Solution is : %d\n", 1 + 2 * (3 + 4) / 6 + 4 * 5);
//     // printf("Postfix solution is : %d \n", postfix("1234+6/*45*++"));
//    printf("Prefix Solution is : %d\n", prefix("++1/*2+346*45"));

//     printf("Solution is : %d\n", 1*(2+3)*(4/2)+6);
//     // printf("Postfix solution is : %d \n", postfix("123+42/**6+"));
//   printf("Prefix Solution is : %d\n", prefix("+**1+23/426"));

struct stack *s = (struct stack *)malloc(sizeof(struct stack));
s->size = 100;
s->top = -1;
s->arr = (int *)malloc(s->size * sizeof(int));

int val;
printf("Enter the Value to Push into stack : ");
scanf("%d", &val);
push(s, val);
printf("%d Pushed Successfully\n", val);
printf("Top of the stack is %d\n", top(s));
push(s, 50);
printf("Top of the stack is %d\n", top(s));
push(s, 20);
printf("Top of the stack is %d\n", top(s));
pop(s);
printf("Top of the stack is %d\n", top(s));
pop(s);
printf("Top of the stack is %d\n", top(s));

}
