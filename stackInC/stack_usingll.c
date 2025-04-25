#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue Implementation using linked list
struct node
{
    int data;
    struct node *next;
};

// Traversal in linked list
void traversal(struct node *ptr)
{
    printf("Stack Elements are : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// isempty condition
bool isempty(struct node *ptr)
{
    return ptr == NULL;
}

// Push operation
struct node *push(struct node *st, int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    if (st == NULL)
    {
        st = n;
        st->next = NULL;
        return st;
    }
    else
    {
        n->next = st;
        st = n;
        return st;
    }
}

// pop operation
struct node *pop(struct node *st)
{
    if (isempty(st))
    {
        printf("No element in queue\n");
        return st;
    }
    else
    {
        struct node *temp = st;
        st = st->next;
        printf("Dequeued: %d\n", temp->data);
        free(temp);
        return st;
    }
}

int main()
{
    struct node *st = NULL; // initializing with NULL

    st = push(st, 1);
    st = push(st, 2);
    st = push(st, 3);
    st = push(st, 4);
    st = push(st, 5);

    traversal(st);

    st = pop(st);
    st = pop(st);

    traversal(st);

    return 0;
}
