#include <iostream>
#include <map>  //include map+Multimap

using namespace std;

int main()
{
    // 1. Initializing a multimap (Key-Value pairs, allows duplicate keys)
    multimap<int, string> mm;

    // 2. Inserting elements (allows duplicate keys)
    mm.insert({1, "Apple"});
    mm.insert({2, "Banana"});
    mm.insert({2, "Blueberry"}); // Duplicate key
    mm.insert({3, "Cherry"});
    mm.insert({3, "Cranberry"}); // Duplicate key
    mm.insert({4, "Date"});

    cout << "Multimap elements (Key-Value pairs with duplicates):" << endl;
    for (auto &pair : mm)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 3. Finding elements with a specific key
    cout << "Entries with key 2: ";
    auto range = mm.equal_range(2);
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->second << " ";
    }
    cout << endl;

    // 4. Removing a single occurrence of a key
    auto it = mm.find(3);
    if (it != mm.end())
    {
        mm.erase(it);
    }
    cout << "After removing one occurrence of key 3:" << endl;
    for (auto &pair : mm)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 5. Removing all occurrences of a key
    mm.erase(2);
    cout << "After removing all occurrences of key 2:" << endl;
    for (auto &pair : mm)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 6. Checking size
    cout << "Size of multimap: " << mm.size() << endl;

    // 7. Checking if empty
    cout << "Is multimap empty? " << (mm.empty() ? "Yes" : "No") << endl;

    // 8. Clearing the multimap
    mm.clear();
    cout << "After clearing, size of multimap: " << mm.size() << endl;

    return 0;
}
