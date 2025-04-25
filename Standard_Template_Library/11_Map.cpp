#include <iostream>
#include <map>  //include a Map STL(KEY-VALUE PAIRS)

using namespace std;

int main()
{
    // 1. Initializing a map (Key-Value pairs)
    map<int, string> m;

    // 2. Inserting elements
    m[1] = "Apple";
    m[2] = "Banana";
    m[3] = "Cherry";
    m.insert({4, "Date"});
    m.insert(make_pair(5, "Elderberry"));

    cout << "Map elements (Key-Value pairs):" << endl;
    for (auto &pair : m)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 3. Accessing elements
    cout << "Element with key 3: " << m[3] << endl;

    // 4. Checking if a key exists
    cout << "Is key 2 present? " << (m.find(2) != m.end() ? "Yes" : "No") << endl;

    // 5. Removing an element by key
    m.erase(2);
    cout << "After removing key 2:" << endl;
    for (auto &pair : m)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 6. Checking size
    cout << "Size of map: " << m.size() << endl;

    // 7. Checking if empty
    cout << "Is map empty? " << (m.empty() ? "Yes" : "No") << endl;

    // 8. Clearing the map
    m.clear();
    cout << "After clearing, size of map: " << m.size() << endl;

    return 0;
}
