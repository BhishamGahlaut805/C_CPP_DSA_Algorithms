#include <iostream>
#include <set> //include a Set

using namespace std;

int main()
{
    // 1. Initializing a set
    set<int> s;

    // 2. Inserting elements
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(10); // Duplicate elements are ignored
    s.insert(50);
    s.insert(40);

    cout << "Set elements (Sorted order): ";
    for (int num : s)
        cout << num << " ";
    cout << endl;

    // 3. Finding an element
    cout << "Is 20 present? " << (s.find(20) != s.end() ? "Yes" : "No") << endl;
    cout << "Is 25 present? " << (s.find(25) != s.end() ? "Yes" : "No") << endl;

    // 4. Removing an element
    s.erase(20);
    cout << "After removing 20: ";
    for (int num : s)
        cout << num << " ";
    cout << endl;

    // 5. Checking size
    cout << "Size of set: " << s.size() << endl;

    // 6. Checking if empty
    cout << "Is set empty? " << (s.empty() ? "Yes" : "No") << endl;

    // 7. Clearing the set
    s.clear();
    cout << "After clearing, size of set: " << s.size() << endl;

    return 0;
}
