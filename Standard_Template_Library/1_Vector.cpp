#include <iostream>
#include <vector>   //include Vector
#include <algorithm> // for sort, reverse
using namespace std;

int main()
{
    // 1. Initializing a vector
    vector<int> v1;                   // Empty vector
    vector<int> v2(5, 10);            // Vector of size 5, all elements initialized to 10
    vector<int> v3 = {1, 2, 3, 4, 5}; // Initializing using initializer list

    // 2. Adding elements
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    // 3. Accessing elements
    cout << "First element: " << v1[0] << endl;
    cout << "Element at index 1 using at(): " << v1.at(1) << endl;
    cout << "Front element: " << v1.front() << endl;
    cout << "Back element: " << v1.back() << endl;

    // 4. Iterating over a vector
    cout << "Vector elements using iterator: ";
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 5. Modifying elements
    v1[1] = 50; // Changing element at index 1
    cout << "After modifying second element: ";
    for (int num : v1)
        cout << num << " ";
    cout << endl;

    // 6. Removing elements
    v1.pop_back(); // Removes last element
    cout << "After pop_back: ";
    for (int num : v1)
        cout << num << " ";
    cout << endl;

    v1.erase(v1.begin()); // Removes first element
    cout << "After erasing first element: ";
    for (int num : v1)
        cout << num << " ";
    cout << endl;

    // 7. Inserting elements
    v1.insert(v1.begin(), 100); // Insert at the beginning
    cout << "After inserting 100 at beginning: ";
    for (int num : v1)
        cout << num << " ";
    cout << endl;

    // 8. Checking size and capacity
    cout << "Size: " << v1.size() << ", Capacity: " << v1.capacity() << endl;

    // 9. Resizing the vector
    v1.resize(5, 99); // Resizes to 5 elements, fills extra with 99
    cout << "After resizing to 5 elements: ";
    for (int num : v1)
        cout << num << " ";
    cout << endl;

    // 10. Sorting a vector
    vector<int> v4 = {5, 3, 8, 1, 2};
    sort(v4.begin(), v4.end()); // Sorts in ascending order
    cout << "Sorted vector: ";
    for (int num : v4)
        cout << num << " ";
    cout << endl;

    // 11. Reversing a vector
    reverse(v4.begin(), v4.end());
    cout << "Reversed vector: ";
    for (int num : v4)
        cout << num << " ";
    cout << endl;

    // 12. Checking if empty and clearing vector
    cout << "Is v1 empty? " << (v1.empty() ? "Yes" : "No") << endl;
    v1.clear();
    cout << "After clearing, size of v1: " << v1.size() << endl;

    return 0;
}
