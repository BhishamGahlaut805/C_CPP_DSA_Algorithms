#include <iostream>
#include <queue>    //Inlcude queue+Priority Queue
#include <vector>

using namespace std;

int main()
{
    // 1. Initializing a max-heap (default behavior)
    priority_queue<int> pq;

    // 2. Pushing elements
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Top element (Max Heap): " << pq.top() << endl;

    // 3. Popping elements
    pq.pop();
    cout << "After pop, new top element: " << pq.top() << endl;

    // 4. Checking size
    cout << "Size of priority queue: " << pq.size() << endl;

    // 5. Checking if empty
    cout << "Is priority queue empty? " << (pq.empty() ? "Yes" : "No") << endl;

    // 6. Printing the elements (must pop elements to print)
    cout << "Priority queue elements (Max-Heap order): ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // 7. Initializing a min-heap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(30);
    min_pq.push(10);
    min_pq.push(50);
    min_pq.push(20);

    cout << "Top element (Min Heap): " << min_pq.top() << endl;

    return 0;
}
