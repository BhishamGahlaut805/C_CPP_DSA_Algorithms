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

struct node *insert_at_begin(struct node *start)
{
    int num;
    printf("Enter the number to insert at beginning: ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;

    if (start == NULL)
    {
        start = ptr;
        ptr->next = start;
    }
    else
    {
        struct node *p = start;
        while (p->next != start)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = start;
        start = ptr;
    }

    return start;
}

struct node *insert_at_end(struct node *start)
{
    int num;
    printf("Enter the number to insert at End: ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;

    if (start == NULL)
    {
        start = ptr;
        ptr->next = start;
    }
    else
    {
        struct node *p = start;
        while (p->next != start)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = start;
    }

    return start;
}

int main()
{
    struct node *list = NULL; // No need to allocate memory here
    list = insert_at_begin(list);
    list = insert_at_begin(list);
    list = insert_at_end(list);
    list = insert_at_end(list);
    list = display(list);

    return 0;
}
