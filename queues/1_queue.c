#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Queue->FIFO fashion

// Implementing queue using structure arrays
struct queue
{
    int size;
    int front;
    int back;
    int *arr;
};
// Queue operations
// isFull
bool isFull(struct queue *q)
{
    if (q->back == q->size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// isEmpty
bool isEmpty(struct queue *q)
{
    if (q->back == q->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Enqueue
// 1.Increment back index
// 2.Insert at back index
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("The Queue is Full");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->back = q->back + 1;
        q->arr[q->back] = val;
    }
}
// Dequeue
// 1.Remove element at index 0
// 2.Shift all elements to index 0
void dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("No more elements in queue\n");
    }
    else
    {
        int a = q->arr[q->front];
        q->front++;
        printf("Dequeued Element is: %d\n", a);
    }
}

void peek(struct queue*q){
    if (isEmpty(q))
    {
        printf("No more elements in queue\n");
        return;
    }
    else{
        printf("Top element on queue is : %d\n",q->arr[q->front]);
    }
}
int main()
{
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->size = 100;
    q->front = q->back = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    int n;
    printf("Enter any value to Enqueue : ");
    scanf("%d", &n);
    enqueue(q,n);
    enqueue(q, 15);
    peek(q);
    enqueue(q, 20);
    peek(q);
    enqueue(q, 25);
    peek(q);

    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);

    // if (isEmpty(&q))
    // {
    //     printf("Queue is empty\n");
    // }
    // else
    // {
    //     printf("Queue is not empty\n");
    // }
    // if (isFull(&q))
    // {
    //     printf("Queue is full\n");
    // }
    // else
    // {
    //     printf("Queue is not full\n");
    // }
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);

    // if (isEmpty(&q))
    // {
    //     printf("Queue is empty\n");
    // }
    // else
    // {
    //     printf("Queue is not empty\n");
    // }
    // if (isFull(&q))
    // {
    //     printf("Queue is full\n");
    // }
    // else
    // {
    //     printf("Queue is not full\n");
    // }
}