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
    printf("Queue Elements are : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;

    }
    printf("\n");
}

// isempty condition
bool isempty(struct node *front)
{
    return front == NULL;
}

// Enqueue operation
struct node *enqueue(struct node *front, int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = front;
    n->data = val;
    if(front==NULL){
        front = n;
        front->next = NULL;
        return front;
    }
    else{
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
        n->next = NULL;
        return front;
    }
}

// Dequeue operation
struct node *dequeue(struct node *front)
{
    if (isempty(front))
    {
        printf("No element in queue\n");
        return front;
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        printf("Dequeued: %d\n", temp->data);
        free(temp);
        return front;
    }
}

int main()
{
    struct node *front = NULL; // initializing with NULL

    front = enqueue(front, 1);
    front = enqueue(front, 2);
    front = enqueue(front, 3);
    front = enqueue(front, 4);
    front = enqueue(front, 5);

    traversal(front);

    front = dequeue(front);
    front = dequeue(front);

    traversal(front);

    return 0;
}
