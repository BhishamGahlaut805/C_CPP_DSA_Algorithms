#include <iostream>
#include <set>      //Including a MultiSet+Set

using namespace std;

int main()
{
    // 1. Initializing a multiset
    multiset<int> ms;

    // 2. Inserting elements (allows duplicates)
    ms.insert(10);
    ms.insert(20);
    ms.insert(10); // Duplicate allowed
    ms.insert(30);
    ms.insert(40);
    ms.insert(20); // Duplicate allowed

    cout << "Multiset elements (Sorted order with duplicates): ";
    for (int num : ms)
        cout << num << " ";
    cout << endl;

    // 3. Finding an element
    cout << "Is 20 present? " << (ms.find(20) != ms.end() ? "Yes" : "No") << endl;

    // 4. Counting occurrences of an element
    cout << "Count of 10: " << ms.count(10) << endl;
    cout << "Count of 20: " << ms.count(20) << endl;

    // 5. Removing a single occurrence of an element
    ms.erase(ms.find(10));
    cout << "After erasing one occurrence of 10: ";
    for (int num : ms)
        cout << num << " ";
    cout << endl;

    // 6. Removing all occurrences of an element
    ms.erase(20);
    cout << "After removing all occurrences of 20: ";
    for (int num : ms)
        cout << num << " ";
    cout << endl;

    // 7. Checking size
    cout << "Size of multiset: " << ms.size() << endl;

    // 8. Checking if empty
    cout << "Is multiset empty? " << (ms.empty() ? "Yes" : "No") << endl;

    // 9. Clearing the multiset
    ms.clear();
    cout << "After clearing, size of multiset: " << ms.size() << endl;

    return 0;
}
