#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

// WAP to perform Operations on stack in C
// Stack is based on LIFO last in first out

struct stack
{
    int size;
    int *arr;
    int top;
};

void push(struct stack *s)
{
    int x;
    printf("\n ENTER A NUMBER TO PUSH ");
    scanf("%d", &x);
    if (s->top == s->size - 1)  //denotes end of stack size
    {
        printf("\n STACK OVERFLOW ");
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
        printf("\n NO ELEMENTS IN STACK ");
        return;
    }
    s->top--;
    printf("\n POP SUCCESSFULLY FROM STACK ");
}
void POP(struct stack *s)
{
    if (s->top == -1)
    {

        return;
    }
    s->top--;
}

void top(struct stack *s)
{
    if (s->top == -1)
    {
        printf("\nNo more elements present");
        return;
    }
    else
    {
        printf("TOP ELEMENT IS : %d", s->arr[s->top]);
    }
}
bool isempty(struct stack *s)
{
    return s->top == -1;
}
void display(struct stack *s)
{
    int i = 1;
    if (s->top == -1)
    {
        printf("\n No more elements present");
        return;
    }

    while (!isempty(s))
    {
        printf("\n ELEMENT %d : %d ", i, s->arr[s->top]);
        POP(s);
        i++;
    }
    printf("\n Now Your Stack is Empty ");
}
int main()
{
    struct stack *st;
    st->size = 8000;
    st->top = -1;
    st->arr = (int *)malloc(sizeof(struct stack));

    int val, option;
    do
    {
        printf("\n\n *******ALL OPERATIONS ON STACK*******\n");
        printf("\n 1. PUSH an element in Stack ");
        printf("\n 2. POP an element from Stack ");
        printf("\n 3. Print the TOP element ");
        printf("\n 4. DISPLAY & EMPTY the whole stack ");
        printf("\n 5. Check whether Stack is EMPTY Or Not ");
        printf("\n 6. EXIT \n");
        printf("\n ENTER YOUR OPTION : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            push(st);
            printf("\n PUSH SUCCESSFULLY IN STACK ");

            break;

        case 2:
            pop(st);

            break;

        case 3:
            top(st);
            break;

        case 4:
            display(st);

            break;

        case 5:
            if (isempty(st))
            {
                printf("\n STACK IS EMPTY ");
            }
            else
            {
                printf("\n STACK IS NOT EMPTY ");
            }
            break;
        default:
            printf("\n INVALID OPTION ");
        }

    } while (option != 6);
}
