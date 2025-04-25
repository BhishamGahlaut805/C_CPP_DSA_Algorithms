#include <iostream>
using namespace std;
#define n 100

class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n]; // Dynamically allocating memory to a stack
        int top = -1;     // Just initializer
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow->No more elements can be added" << endl;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "No more elements to pop" << endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "No more elements present" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};
int main()
{
    stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    cout << stk.Top() << endl;
    stk.pop();
    stk.pop();
    cout << stk.Top() << endl;
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    cout << stk.empty() << endl;
    
}