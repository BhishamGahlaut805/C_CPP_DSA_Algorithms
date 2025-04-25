#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Stack->LIFO fashion working

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
int precedence(char c)
{
    if (c == '^' || c == '!')
    {
        return 6; // Giving highest precedence
    }
    else if (c == '*' || c == '/')
    {
        return 5;
    }
    else if (c == '+' || c == '-')
    {
        return 4;
    }
    else if (c == '<' || c == '>')
    {
        return 3;
    }
    else if (c == '&')
    {
        return 2;
    }
    else if (c == '|')
    {
        return 1;
    }
    else
    {
        return -1; // Not an operator
    }
}

// Function to reverse a string
void reverse(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Infix to Prefix Conversion
void infix_to_prefix(char q[])
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack)); // Allocate memory for the stack
    int len = strlen(q);
    st->size = len;
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char)); // Allocate memory for the array
    reverse(q);
    char prefix[len + 1];
    int j = 0;

    // Step 1: Push ')' onto the stack and add '(' to the expression
    push(st, ')');
    q[len] = '(';
    q[len + 1] = '\0';

    // Step 2: Scan q from L to R and repeat steps 3 to 6
    for (int i = 0; i <= len; i++)
    {
        // Case 1: If it is a number/alphabet, add it to the result
        if ((q[i] >= '0' && q[i] <= '9') || (q[i] >= 'a' && q[i] <= 'z') || (q[i] >= 'A' && q[i] <= 'Z'))
        {
            prefix[j] = q[i];
            j++;
        }
        // Case 2: If it is a closing bracket, push it to the stack
        else if (q[i] == ')')
        {
            push(st, q[i]);
        }
        // Case 3: If it is an opening bracket, repeatedly add elements to the answer and pop from the stack until its closing bracket is found
        else if (q[i] == '(')
        {
            while (!empty(st) && top(st) != ')')
            {
                prefix[j] = top(st);
                j++;
                pop(st);
            }
            // Then, remove ')' from the stack
            if (!empty(st))
            {
                pop(st);
            }
        }
        // Case 4: If it is an operator, add all elements of stack to answer until an operator with less precedence is found on top of stack
        else
        {
            while (!empty(st) && precedence(top(st)) > precedence(q[i]))
            {
                prefix[j] = top(st);
                j++;
                pop(st);
            }
            // Then push the operator to the stack
            push(st, q[i]);
        }
    }

    // If anything still remains in stack, add it to answer
    while (!empty(st))
    {
        prefix[j] = top(st);
        j++;
        pop(st);
    }

    // '\0' indicates the end of the string
    prefix[j] = '\0';
    reverse(prefix);
    printf("%s\n", prefix);

    // Free allocated memory
    free(st->arr);
    free(st);
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 500;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char str[100];
    printf("Enter Infix Form:");
    scanf("%s", str);
    printf("Prefix Form : ");
    infix_to_prefix(str);

    // Free allocated memory
    free(s->arr);
    free(s);

    return 0;
}