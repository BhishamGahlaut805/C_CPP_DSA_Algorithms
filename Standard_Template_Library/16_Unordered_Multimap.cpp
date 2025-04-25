#include <iostream>
#include <unordered_map>    //include unordered_Multimap

using namespace std;

int main()
{
    // 1. Initializing an unordered_multimap (Key-Value pairs, allows duplicate keys)
    unordered_multimap<int, string> umm;

    // 2. Inserting elements (allows duplicate keys)
    umm.insert({1, "Apple"});
    umm.insert({2, "Banana"});
    umm.insert({2, "Blueberry"}); // Duplicate key
    umm.insert({3, "Cherry"});
    umm.insert({3, "Cranberry"}); // Duplicate key
    umm.insert({4, "Date"});

    cout << "Unordered multimap elements (Key-Value pairs with duplicates):" << endl;
    for (auto &pair : umm)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 3. Finding elements with a specific key
    cout << "Entries with key 2: ";
    auto range = umm.equal_range(2);
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->second << " ";
    }
    cout << endl;

    // 4. Removing a single occurrence of a key
    auto it = umm.find(3);
    if (it != umm.end())
    {
        umm.erase(it);
    }
    cout << "After removing one occurrence of key 3:" << endl;
    for (auto &pair : umm)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 5. Removing all occurrences of a key
    umm.erase(2);
    cout << "After removing all occurrences of key 2:" << endl;
    for (auto &pair : umm)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 6. Checking size
    cout << "Size of unordered multimap: " << umm.size() << endl;

    // 7. Clearing the unordered multimap
    umm.clear();
    cout << "After clearing, size of unordered multimap: " << umm.size() << endl;

    return 0;
}
