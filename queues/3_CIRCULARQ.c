#include<stdio.h>
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
//1.Enqueue operation
void enqueue(struct queue*q,int val){
    if((q->front==0 && q->back==q->size-1)||q->front==q->back+1){
        printf("\n Queue is Overflow ");
        return;
    }

     if (q->front == -1 && q->back == -1)
    {
        q->front = 0;
        q->back = 0;
    }
    else{
        q->back = (q->back + 1) % q->size;
    }
    q->arr[q->back] = val;
}

//2.Dequeue

void dequeue(struct queue*q){
    int deleted = -1;
    if(q->front==-1){
        printf("Queue Underflow\n");

    }else{
        deleted = q->arr[q->front];
        if (q->front == q->back)
        {
            q->front = q->back = -1;
    }
    else{
        q->front = (q->front + 1) % (q->size);
    }
    printf("Deleted element is : %d\n", deleted);

    }
}
void peek(struct queue *);
// {
//     if (q->front == -1 && q->back == -1)
//     {
//         printf("\n Queue is Empty ");
//     }
//     else
//     {
//        printf("Top of the queue is: %d \n ", q->arr[q->front]);
//     }
// }
int main(){
    struct queue *q;
    q->size = 5;
    q->front = q->back = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    int n;
    printf("Enter any value to Enqueue : ");
    scanf("%d", &n);
    enqueue(q, n);
    enqueue(q, 10);
    enqueue(q, 15);
    peek(q);
    enqueue(q, 20);
    peek(q);
    dequeue(q);
    enqueue(q, 25);
    peek(q);
    dequeue(q);
    peek(q);
    dequeue(q);
    dequeue(q);
    peek(q);

}
void peek(struct queue *q)
{
    if (q->front == -1 && q->back == -1)
    {
        printf("\n Queue is Empty ");
    }
    else
    {
       printf("Top of the queue is: %d \n ", q->arr[q->front]);
    }
}