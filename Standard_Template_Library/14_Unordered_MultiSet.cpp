#include <iostream>
#include <unordered_set>    //include the unordered_Set+unordered_Multiset

using namespace std;

int main()
{
    // 1. Initializing an unordered_multiset
    unordered_multiset<int> ums;

    // 2. Inserting elements (allows duplicates)
    ums.insert(10);
    ums.insert(20);
    ums.insert(10); // Duplicate allowed
    ums.insert(30);
    ums.insert(20); // Duplicate allowed

    cout << "Unordered multiset elements: ";
    for (int num : ums)
        cout << num << " ";
    cout << endl;

    // 3. Counting occurrences of an element
    cout << "Count of 10: " << ums.count(10) << endl;
    cout << "Count of 20: " << ums.count(20) << endl;

    // 4. Removing a single occurrence of an element
    auto it = ums.find(10);
    if (it != ums.end())
        ums.erase(it);
    cout << "After removing one occurrence of 10: ";
    for (int num : ums)
        cout << num << " ";
    cout << endl;

    // 5. Removing all occurrences of an element
    ums.erase(20);
    cout << "After removing all occurrences of 20: ";
    for (int num : ums)
        cout << num << " ";
    cout << endl;

    // 6. Checking size
    cout << "Size of unordered multiset: " << ums.size() << endl;

    // 7. Clearing the unordered multiset
    ums.clear();
    cout << "After clearing, size of unordered multiset: " << ums.size() << endl;

    return 0;
}
