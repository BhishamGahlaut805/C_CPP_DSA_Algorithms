#include <iostream>
#include <stack>    //include Stack STL

using namespace std;

int main()
{
    // 1. Initializing a stack
    stack<int> s;

    // 2. Pushing elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Top element of stack: " << s.top() << endl;

    // 3. Popping elements
    s.pop();
    cout << "After pop, new top element: " << s.top() << endl;

    // 4. Checking size of stack
    cout << "Size of stack: " << s.size() << endl;

    // 5. Checking if stack is empty
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    // 6. Printing the stack contents
    cout << "Stack elements (LIFO order): ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
