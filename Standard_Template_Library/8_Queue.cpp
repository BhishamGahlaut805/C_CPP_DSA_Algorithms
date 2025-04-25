#include <iostream>
#include <queue>    //include queue

using namespace std;

int main()
{
    // 1. Initializing a queue
    queue<int> q;

    // 2. Pushing elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // 3. Popping elements
    q.pop();
    cout << "After pop, new front element: " << q.front() << endl;

    // 4. Checking size
    cout << "Size of queue: " << q.size() << endl;

    // 5. Checking if empty
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    // 6. Printing queue elements (FIFO order)
    cout << "Queue elements (FIFO order): ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
