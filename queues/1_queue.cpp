#include <iostream>

using namespace std;
#define n 20

// Queue is a linear data structure that stores the data in First In First Out (FIFO)
// fashion.

// Defining Queue using arrays

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    // pushing an element in a queue
    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue Overflow" << endl;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }
    // Removing an element from a queue
    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in Queue" << endl;
            return;
        }
        front++;
    }
    // return peek element of a queue
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in Queue" << endl;
            return -1;
        }
        return arr[front];
    }

    // Check if a queue is empty
    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    queue q;
    for (int i = 0; i < 10; i++)
    {
        q.push(arr[i]);
        cout << "Element " << i + 1 << " is " << q.peek() << endl;
        q.pop();
    }
    // cout<<q.peek()<<endl;
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // cout<<q.peek()<<endl;
    cout << q.empty() << endl;
}