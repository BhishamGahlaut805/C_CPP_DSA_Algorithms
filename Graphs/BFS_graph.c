#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue -> FIFO fashion
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
    if (q->front == q->back)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Enqueue
// 1. Increment back index
// 2. Insert at back index
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("The Queue is Full\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0; // Initialize front for the first element
        }
        q->back++;
        q->arr[q->back] = val;
    }
}

// Dequeue
// 1. Remove element at front index
// 2. Increment front index
int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        return -1; // Return -1 if the queue is empty
    }
    else
    {
        int a = q->arr[q->front];
        if (q->front == q->back)
        {
            // Reset queue after last element is dequeued
            q->front = q->back = -1;
        }
        else
        {
            q->front++;
        }
        return a;
    }
}

void peek(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("No more elements in queue\n");
        return;
    }
    else
    {
        printf("Top element on queue is: %d\n", q->arr[q->front]);
    }
}

// Function to perform Breadth-First Traversal (BFT)
void BFT(int graph[][7], int startNode, int numberOfNodes)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 100;
    q->front = q->back = 0; // Initialize front and back to 0
    q->arr = (int *)malloc(q->size * sizeof(int));

    int node;
    int visited[7] = {0};

    printf("%d ", startNode);
    visited[startNode] = 1;
    enqueue(q, startNode);

    while (!isEmpty(q))
    {
        node = dequeue(q);

        for (int j = 0; j < numberOfNodes; j++)
        {
            if (graph[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    // Free allocated memory
    free(q->arr);
    free(q);
}

int main()
{
    // Graph adjacency matrix
    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    int numberOfNodes = 7;
    int startNode = 0;

    // Perform Breadth-First Traversal
    BFT(graph, startNode, numberOfNodes);

    return 0;
}
