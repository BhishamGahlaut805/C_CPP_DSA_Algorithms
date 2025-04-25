#include <iostream>
#include <forward_list> //include forward_list
#include <algorithm> // for sort and reverse

using namespace std;

int main()
{
    // 1. Initializing a forward list
    forward_list<int> fl1;                        // Empty forward_list
    forward_list<int> fl2 = {10, 20, 30, 80, 50}; // Initializing using initializer list

    // 2. Adding elements
    fl1.push_front(10);
    fl1.push_front(20);
    fl1.push_front(30);

    cout << "Forward List after push operations: ";
    for (int num : fl1)
        cout << num << " ";
    cout << endl;

    // 3. Accessing first element
    cout << "First element: " << fl1.front() << endl;

    // 4. Removing elements
    fl1.pop_front(); // Removes first element
    cout << "After pop_front operation: ";
    for (int num : fl1)
        cout << num << " ";
    cout << endl;

    // 5. Inserting elements after a specific position
    auto it = fl1.begin();
    fl1.insert_after(it, 100);
    cout << "After inserting 100: ";
    for (int num : fl1)
        cout << num << " ";
    cout << endl;

    // 6. Removing elements by value
    fl1.remove(100);
    cout << "After removing 100: ";
    for (int num : fl1)
        cout << num << " ";
    cout << endl;

    // 7. Sorting the list
    fl2.sort();
    cout << "Sorted forward_list: ";
    for (int num : fl2)
        cout << num << " ";
    cout << endl;

    // 8. Reversing the list
    fl2.reverse();
    cout << "Reversed forward_list: ";
    for (int num : fl2)
        cout << num << " ";
    cout << endl;

    // 9. Merging two lists
    forward_list<int> fl3 = {5, 15, 2};
    fl2.merge(fl3); // Merging fl3 into fl2 (must be sorted)
    cout << "Merged forward_list: ";
    for (int num : fl2)
        cout << num << " ";
    cout << endl;

    return 0;
}
