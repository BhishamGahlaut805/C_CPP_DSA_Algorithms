#include <stdio.h>
#include <stdlib.h>

// Complete Linked list all operations in one code

// Simple Linked List

struct node
{
    int data;
    struct node *next;
};

struct node *display(struct node *start)
{
    struct node *ptr = start;
    printf("Linked list : ");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return start;
}

// Delete from beginning
struct node *del_begin(struct node *start)
{
    struct node *del = start;
    if (start != NULL)
    {
        start = start->next;
        free(del);
    }
    return start;
}

//Delete from end
struct node *delete_end(struct node *start)
{
    struct node *p = start;
    struct node *q = start->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return start;
}
//Delete the full list

struct node *delete_full(struct node *start)
{
    struct node *ptr;
    if (start != NULL)
    {
        ptr = start;
        while (ptr != NULL)
        {
            start = del_begin(ptr);
            ptr = start;
        }
    }
    return start;
}
int main()
{
    struct node *a = (struct node *)malloc(sizeof(struct node));
    struct node *b = (struct node *)malloc(sizeof(struct node));
    struct node *c = (struct node *)malloc(sizeof(struct node));
    struct node *d = (struct node *)malloc(sizeof(struct node));

    a->data = 10;
    a->next = b;
    b->data = 20;
    b->next = c;
    c->data = 30;
    c->next = d;
    d->data = 40;
    d->next = NULL;

    a = display(a);
    a = del_begin(a);
    a = display(a);
    a = delete_end(a);
    a = display(a);
    a = delete_full(a);
    a = display(a);
    // Free remaining nodes
    while (a != NULL)
    {
        a = del_begin(a);
    }

    return 0;
}
