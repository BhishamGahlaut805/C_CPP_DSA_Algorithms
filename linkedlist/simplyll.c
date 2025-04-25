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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = start;
    printf("Linked list : ");
    while (ptr!= NULL)
    {
         printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

// 3.Insert at beginning
struct node *insert_at_begin(struct node *start)
{
    int num;
    printf("Enter the number to insert at beginning : ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num; // Making links as in a chain
    if (start == NULL)
    {
        start = ptr;
        start->next = NULL;
    }
    else{
    ptr->next = start; // Making links as in a chain
    start = ptr;
    }
    return start;
}

// 4.Insert at End
struct node *insert_at_end(struct node *start)
{
    int num;
    printf("Enter the number to insert at End : ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;        // Node to be added
    if(start==NULL){
        start = ptr;
        start->next = NULL;
    }
    else{
        struct node *p = start; // Saving our start node
        while (p->next != NULL)
        {
            p = p->next;
    }
    // Now reached at the last node
    p->next = ptr;    // Making links at the end
    ptr->next = NULL; // Making links at the end
    }
    return start;
}
struct node *insert_before(struct node *start)
{
    int val;
    printf("Enter the node before you want to insert : ");
    scanf("%d", &val);
    int num;
    printf("Enter the number to insert : ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;

    if (start == NULL)
    {
        start = ptr;
        start->next = NULL;
    }
    else if(val==start->data){
        ptr->next = start;
        start = ptr;

    }
    else{
    struct node *p = start;
    struct node *preptr;
    while (p->data != val)
    {
        preptr = p; // preptr will be the position of p(start) before num(to be added)
        p = p->next;
    }
    preptr->next = ptr; // Making links
    ptr->next = p;      // Making links
    }
    return start;
}

int main(){
    struct node *list = (struct node *)malloc(sizeof(struct node));
    list = NULL;
    list = insert_at_begin(list);
    list = insert_at_begin(list);
    list = insert_at_end(list);
    list = insert_at_end(list);
    list = insert_before(list);
    list = insert_before(list);
    list = display(list);
}