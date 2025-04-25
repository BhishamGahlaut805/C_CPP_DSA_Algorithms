#include <iostream>
#include <deque>    //include the doubly ended queue
#include <algorithm> // For sort and reverse

using namespace std;

int main()
{
    // 1. Initializing a deque
    deque<int> d1;                   // Empty deque
    deque<int> d2(5, 10);            // Deque of size 5, all elements initialized to 10
    deque<int> d3 = {1, 2, 3, 4, 5}; // Initializing using initializer list

    // 2. Adding elements
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(5);
    d1.push_front(2);

    cout << "Deque after push operations: ";
    for (int num : d1)
        cout << num << " ";
    cout << endl;

    // 3. Accessing elements
    cout << "First element: " << d1.front() << endl;
    cout << "Last element: " << d1.back() << endl;
    cout << "Element at index 1 using at(): " << d1.at(1) << endl;

    // 4. Iterating over a deque
    cout << "Deque elements using iterator: ";
    for (auto it = d1.begin(); it != d1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 5. Removing elements
    d1.pop_back();  // Removes last element
    d1.pop_front(); // Removes first element
    cout << "After pop operations: ";
    for (int num : d1)
        cout << num << " ";
    cout << endl;

    // 6. Inserting elements
    d1.insert(d1.begin() + 1, 100); // Insert 100 at second position
    cout << "After inserting 100 at second position: ";
    for (int num : d1)
        cout << num << " ";
    cout << endl;

    // 7. Erasing elements
    d1.erase(d1.begin() + 1); // Erase second element
    cout << "After erasing second element: ";
    for (int num : d1)
        cout << num << " ";
    cout << endl;

    // 8. Checking size and capacity
    cout << "Size: " << d1.size() << endl;

    // 9. Resizing the deque
    d1.resize(5, 99); // Resize to 5 elements, fills extra with 99
    cout << "After resizing to 5 elements: ";
    for (int num : d1)
        cout << num << " ";
    cout << endl;

    // 10. Sorting a deque
    deque<int> d4 = {5, 3, 8, 1, 2};
    sort(d4.begin(), d4.end()); // Sorts in ascending order
    cout << "Sorted deque: ";
    for (int num : d4)
        cout << num << " ";
    cout << endl;

    // 11. Reversing a deque
    reverse(d4.begin(), d4.end());
    cout << "Reversed deque: ";
    for (int num : d4)
        cout << num << " ";
    cout << endl;

    // 12. Checking if empty and clearing deque
    cout << "Is d1 empty? " << (d1.empty() ? "Yes" : "No") << endl;
    d1.clear();
    cout << "After clearing, size of d1: " << d1.size() << endl;

    return 0;
}
