#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        printf("Stack overflow No elements can be added\n");
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
        printf("No more elements to pop");
        return;
    }
    s->top--;
}

int Top(struct stack *s)
{
    if (s->top == -1)
    {
        printf("No more elements present");
        return -1;
    }
    return s->arr[s->top];
}
bool empty(struct stack *s)
{
    return s->top == -1;
}

int main()
{
    // stack implementation in C lang using struct  pointers
    struct stack *s;
    s->size = 800;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(struct stack));

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    printf("%d\n", Top(s));
    pop(s);
    printf("%d\n", Top(s));
    pop(s);
    printf("%d\n", Top(s));
    pop(s);
    printf("%d\n", Top(s));
    pop(s);
    printf("%d\n", Top(s));
    pop(s);
    printf("%d\n", Top(s));
    pop(s);
    printf("%d\n", Top(s));
    pop(s);
    printf("%d", empty(s));
}