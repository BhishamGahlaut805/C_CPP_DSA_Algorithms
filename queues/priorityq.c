#include <stdio.h>
#include <stdlib.h>

// Priority Queues
/*
A priority queue is a data structure in which each element is assigned a priority. The priority of the
element will be used to determine the order in which the elements will be processed.
*/

struct node
{
    int data;
    int priority;
    struct node *next;
};

// 1. Insert an element in a Priority Queue
struct node *insert(struct node *start, int val, int pri)
{
    struct node *ptr, *p;
    ptr = (struct node *)malloc(sizeof(struct node));

    // Saving data and priority in ptr
    ptr->data = val;
    ptr->priority = pri;

    // Case 1: Empty queue or less priority number (higher priority) is added before start
    if (start == NULL || pri < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    // Case 2: Queue is not empty, so add the element in the queue according to its priority order
    else
    {
        p = start;
        while (p->next != NULL && p->next->priority <= pri)
        {
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return start;
}

// 2. Deletion will be the same as a normal queue to be followed in Priority queue
struct node *delete(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\n UNDERFLOW ");
        return start;
    }
    else
    {
        ptr = start;
        printf("\n Deleted element is : %d", ptr->data);
        start = start->next;
        free(ptr);
    }
    return start;
}

// 3. Display will be the same as a normal queue
void display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("\n Queue is Empty ");
        return;
    }
    else
    {
        printf("\n Priority Queue is : ");
        while (ptr != NULL)
        {
            printf("\t%d[priority=%d]", ptr->data, ptr->priority);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int val, pri;
    struct node *queue = NULL;

    for (int i = 0; i < 5; i++)
    {
        printf("Enter the value : ");
        scanf("%d", &val);
        printf("Enter Priority of %d : ", val);
        scanf("%d", &pri);
        queue = insert(queue, val, pri);
    }

    display(queue);
    queue = delete (queue);
    queue = delete (queue);
    display(queue);

    return 0;
}
