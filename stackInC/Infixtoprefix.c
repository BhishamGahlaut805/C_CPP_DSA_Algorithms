#include <stdio.h>
#include<string.h>

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

void infix_to_prefix(char q[])
{

    int len = strlen(q);
    reverse(q);
    char stack[len + 1];
    int top = -1;

    char prefix[len + 1];
    int j = 0;

    // Step 1: Push ')' onto the stack and add '(' to the expression
    // push(st, ')');
    stack[++top] = ')';
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
            stack[++top] = ')';
        }
        // Case 3: If it is an opening bracket, repeatedly add elements to the answer and pop from the stack until its closing bracket is found
        else if (q[i] == '(')
        {
            while (top!=-1 &&  stack[top]!=')')
            {
                prefix[j++] = stack[top--];
                // j++;

            }
            // Then, remove ')' from the stack
            if (top!=-1)
            {
                top--;
            }
        }
        // Case 4: If it is an operator, add all elements of stack to answer until an operator with less precedence is found on top of stack
        else
        {
            while (top!=-1 && precedence(stack[top]) > precedence(q[i]))
            {
                prefix[j++] = stack[top--];
                // j++;

            }
            // Then push the operator to the stack
            stack[++top] = q[i];
        }
    }

    // If anything still remains in stack, add it to answer
    while (top!=-1)
    {
        prefix[j] = stack[top--];
        j++;
    }

    // '\0' indicates the end of the string
    prefix[j] = '\0';
    reverse(prefix);
    printf("%s\n", prefix);

}

int main()
{
    char str[100];
    printf("Enter Infix Form:");
    scanf("%s", str);
    printf("Prefix Form : ");
    infix_to_prefix(str);
}
