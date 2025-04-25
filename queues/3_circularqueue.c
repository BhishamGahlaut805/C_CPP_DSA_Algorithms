#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define size 11
// Circular Queue-> Insertion and deletions can be made from both front and rear ends
int queue[size];
int front = -1;
int back = -1;

void enqueue(int val)
{
    // 1.Queue is full
    if ((front == 0 && back == size - 1)||front==back+1)
    {
        printf("\n Queue is Overflow ");
        return;
    }

    // 2.Queue is empty ->insertion from back as in Linear queue
    else if (front == -1 && back == -1)
    {
        front = 0;
        back = 0;
        queue[back] = val;
    }

    // 3. Insert from front if it is full from back
    else if (back == size - 1 && front != 0)
    {
        back = 0;
        queue[back] = val;
    }
    // 4.Else insert from back
    else
    {
        back++;
        queue[back] = val;
    }
}
// 2.Peek
int peek()
{
    if (front == -1 && back == -1)
    {
        printf("\n Queue is Empty ");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

// 3.Display
void display()
{

    printf("\n");
    if (front == -1 && back == -1)
    {
        printf("\n Queue is Empty ");
        return;
    }
    else
    {
        if (front < back)
        { // Normal condition
            for (int i = front; i < back; i++)
            {
                printf("%d\t", queue[i]);
            }
        }
        else
        {
            for (int i = front; i < back; i++)
            {
                printf("%d\t", queue[i]);
            }

            // elements inserted at front using back as pointer
            for (int i = 0; i < back; i++)
            {
                printf("%d\t", queue[i]);
            }
        }
    }
}

// 4.Deletion
void delete_at_front()
{
    if (front == -1 && back == -1)
    {
        printf("\n Queue Underfow ");
        return;
    }
    else
    {

        front++;
        // casting value of int into pointer

        uintptr_t int_value = queue[0];
        uint32_t *pointer = (uint32_t *)int_value;
        free(pointer);
    }
}
// 5. delete value
int delete(int val)
{
    if (front == -1 && back == -1)
    {
        printf("\n Queue Underfow ");
        return -1;
    }
    val = queue[front];
    if (front == back)
    {
        front = back = -1;
    }
    else
    {
        if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    return val;
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    printf("\nPeek : %d", peek());
    display();
    delete_at_front();
    display();
    printf("\nPeek : %d", peek());
    delete (30);
    display();
    printf("\nPeek : %d", peek());
}
