#include <iostream>
#include <unordered_map>    //include the unordered_map

using namespace std;

int main()
{
    // 1. Initializing an unordered_map (Key-Value pairs)
    unordered_map<int, string> um;

    // 2. Inserting elements
    um[1] = "Apple";
    um[2] = "Banana";
    um[3] = "Cherry";
    um.insert({4, "Date"});
    um.insert(make_pair(5, "Elderberry"));

    cout << "Unordered map elements (Key-Value pairs):" << endl;
    for (auto &pair : um)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 3. Accessing elements
    cout << "Element with key 3: " << um[3] << endl;

    // 4. Checking if a key exists
    cout << "Is key 2 present? " << (um.find(2) != um.end() ? "Yes" : "No") << endl;

    // 5. Removing an element by key
    um.erase(2);
    cout << "After removing key 2:" << endl;
    for (auto &pair : um)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 6. Checking size
    cout << "Size of unordered map: " << um.size() << endl;

    // 7. Clearing the unordered map
    um.clear();
    cout << "After clearing, size of unordered map: " << um.size() << endl;

    return 0;
}
