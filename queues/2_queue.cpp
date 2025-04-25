#include <iostream>
using namespace std;

// Queue implementaion using linked list
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class queue
{
public:
    node *front;
    node *back;
    queue()
    {
        front = NULL;
        back = NULL;
    }
    // Push operation
    void push(int x)
    {
        node *n = new node(x);
        if (front == NULL)
        { // Queue/list is empty
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }
    // pop operation
    void pop()
    {
        if (front == NULL)
        {
            cout << "No element in queue" << endl;
            return;
        }
        node *temp = front; // Node which is to be deleted
        front = front->next;
        delete temp;
    }

    // peek operation
    int peek()
    {
        if (front == NULL)
        {
            cout << "No element in queue" << endl;
            return -1;
        }
        return front->data;
    }
    // empty check operation
    bool empty()
    {
        if (front == NULL)
        {
            return 1;
        }
        return 0;
    }
};
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
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