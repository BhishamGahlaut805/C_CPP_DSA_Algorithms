#include <stdio.h>
#include <stdlib.h>

// Circular Linked List

struct node
{
    int data;
    struct node *next;
};

struct node *display(struct node *start)
{
    if (start == NULL)
    {
        printf("Linked list is empty.\n");
        return start;
    }
    struct node *ptr = start;
    printf("Linked list: ");
    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("%d\n", start->data); // Corrected this line
    return start;
}

// Delete from beginning
struct node *del_begin(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    struct node *p = start;
    if (start->next == start)
    { // Only one node
        free(start);
        return NULL;
    }
    while (p->next != start)
    {
        p = p->next;
    }
    struct node *temp = start;
    p->next = start->next;
    start = start->next;
    free(temp);
    return start;
}

// Delete from end
struct node *delete_end(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    struct node *p = start;
    if (start->next == start)
    { // Only one node
        free(start);
        return NULL;
    }
    struct node *q = start->next;
    while (q->next != start)
    { // Circular manner
        p = p->next;
        q = q->next;
    }
    p->next = start; // Circular manner
    free(q);
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
    d->next = a;

    a = display(a);
    a = del_begin(a);
    a = display(a);
    a = delete_end(a);
    a = display(a);
    
    while (a != NULL)
    {
        a = del_begin(a);
    }

    return 0;
}
