#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Implement Stack using Linked List

struct snode
{
    int data;
    struct snode *next;
};
struct snode *stack = NULL;

// Push operation
struct snode *push(struct snode *st)
{
    int x;
    printf("\n Enter element to PUSH ");
    scanf("%d", &x);

    struct snode *ptr = (struct snode *)malloc(sizeof(struct snode));
    ptr->data = x;

    // Case when stack is empty
    if (st == NULL)
    {
        ptr->next = NULL;
        st = ptr;
    }
    else
    {
        ptr->next = st; // added at the top
        st = ptr;
    }
    return st;
}

void pop(struct snode *s)
{
    struct snode *ptr;
    ptr = s;
    if (s == NULL)
    {
        printf("\n Stack is empty ");
    }

    else
    {
        s = s->next;
        printf("\n The value being deleted is : %d ", ptr->data);
    }
    free(ptr);
}
void top(struct snode *st)
{
    if (st == NULL)
    {
        printf("\n Stack is empty ");
    }
    else
    {
        printf("Top Element is : %d", st->data);
    }
}
bool isempty(struct snode *st)
{
    return st == NULL;
}

void display(struct snode *s)
{
    int i = 1;
    if (s == NULL)
    {
        printf("\n No more elements present");
        return;
    }

    while (s->next != NULL)
    {
        printf("\n ELEMENT %d : %d ", i, s->data);
        s = s->next;
        i++;
    }
    printf("\n ELEMENT %d : %d ", i, s->data);
}
int main()
{
    int val, option;
    do
    {
        printf("\n\n *******ALL OPERATIONS ON LINKED STACK*******\n");
        printf("\n 1. PUSH an element in Stack ");
        printf("\n 2. POP an element from Stack ");
        printf("\n 3. Print the TOP element ");
        printf("\n 4. DISPLAY the whole stack ");
        printf("\n 5. Check whether Stack is EMPTY Or Not ");
        printf("\n 6. EXIT \n");
        printf("\n ENTER YOUR OPTION : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            stack = push(stack);
            printf("\n PUSH SUCCESSFULLY IN STACK ");

            break;

        case 2:
            pop(stack);

            break;

        case 3:
            top(stack);
            break;

        case 4:
            display(stack);

            break;

        case 5:
            if (isempty(stack))
            {
                printf("\n STACK IS EMPTY ");
            }
            else
            {
                printf("\n STACK IS NOT EMPTY ");
            }
            break;
        }
    } while (option != 6);
}