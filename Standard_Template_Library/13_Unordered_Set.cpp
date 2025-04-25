#include <iostream>
#include <unordered_set>    //include unordered_Set

using namespace std;

int main()
{
    // 1. Initializing an unordered_set
    unordered_set<int> us;

    // 2. Inserting elements
    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(10); // Duplicate ignored

    cout << "Unordered set elements: ";
    for (int num : us)
        cout << num << " ";
    cout << endl;

    // 3. Checking if an element exists
    cout << "Is 20 present? " << (us.find(20) != us.end() ? "Yes" : "No") << endl;

    // 4. Removing an element
    us.erase(20);
    cout << "After removing 20: ";
    for (int num : us)
        cout << num << " ";
    cout << endl;

    // 5. Checking size
    cout << "Size of unordered set: " << us.size() << endl;

    // 6. Checking if empty
    cout << "Is unordered set empty? " << (us.empty() ? "Yes" : "No") << endl;

    // 7. Clearing the unordered set
    us.clear();
    cout << "After clearing, size of unordered set: " << us.size() << endl;

    return 0;
}
