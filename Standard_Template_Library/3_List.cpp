#include <iostream>
#include <list> //including a doubly linked list 
#include <algorithm> // For sort and reverse

using namespace std;

int main()
{
    // 1. Initializing a list
    list<int> l1;                   // Empty list
    list<int> l2(5, 10);            // List of size 5, all elements initialized to 10
    list<int> l3 = {1, 2, 3, 4, 5}; // Initializing using initializer list

    // 2. Adding elements
    l1.push_back(10);
    l1.push_back(20);
    l1.push_front(5);
    l1.push_front(2);

    cout << "List after push operations: ";
    for (int num : l1)
        cout << num << " ";
    cout << endl;

    // 3. Accessing elements
    cout << "First element: " << l1.front() << endl;
    cout << "Last element: " << l1.back() << endl;

    // 4. Iterating over a list
    cout << "List elements using iterator: ";
    for (auto it = l1.begin(); it != l1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 5. Removing elements
    l1.pop_back();  // Removes last element
    l1.pop_front(); // Removes first element
    cout << "After pop operations: ";
    for (int num : l1)
        cout << num << " ";
    cout << endl;

    // 6. Inserting elements
    auto it = l1.begin();
    advance(it, 1);     // Move iterator to second position
    l1.insert(it, 100); // Insert 100 at second position
    cout << "After inserting 100 at second position: ";
    for (int num : l1)
        cout << num << " ";
    cout << endl;

    // 7. Erasing elements
    it = l1.begin();
    advance(it, 1);
    l1.erase(it); // Erase second element
    cout << "After erasing second element: ";
    for (int num : l1)
        cout << num << " ";
    cout << endl;

    // 8. Checking size
    cout << "Size: " << l1.size() << endl;

    // 9. Resizing the list
    l1.resize(5, 1000); // Resize to 5 elements, fills extra with 1000
    cout << "After resizing to 5 elements: ";
    for (int num : l1)
        cout << num << " ";
    cout << endl;

    // 10. Sorting a list
    list<int> l4 = {5, 3, 8, 1, 2};
    l4.sort(); // Sorts in ascending order
    cout << "Sorted list: ";
    for (int num : l4)
        cout << num << " ";
    cout << endl;

    // 11. Reversing a list
    l4.reverse();
    cout << "Reversed list: ";
    for (int num : l4)
        cout << num << " ";
    cout << endl;

    // 12. Merging two lists
    list<int> l5 = {11, 22, 33};
    l4.merge(l5); // Merges l5 into l4 (both should be sorted)
    cout << "Merged list: ";
    for (int num : l4)
        cout << num << " ";
    cout << endl;

    // 13. Removing specific elements
    l4.remove(3); // Removes all occurrences of 3
    cout << "After removing 3: ";
    for (int num : l4)
        cout << num << " ";
    cout << endl;

    // 14. Unique (removing consecutive duplicates)
    l4.unique();
    cout << "After removing consecutive duplicates: ";
    for (int num : l4)
        cout << num << " ";
    cout << endl;

    // 15. Checking if empty and clearing list
    cout << "Is l1 empty? " << (l1.empty() ? "Yes" : "No") << endl;
    l1.clear();
    cout << "After clearing, size of l1: " << l1.size() << endl;

    return 0;
}
