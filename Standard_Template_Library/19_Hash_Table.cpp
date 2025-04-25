#include <iostream>
#include <unordered_map>
//Unordered_Map as a Hash Table
using namespace std;

int main()
{
    // 1. Initializing an unordered_map (acts as a hash table)
    unordered_map<string, int> hashTable;

    // 2. Inserting key-value pairs
    hashTable["Apple"] = 50;
    hashTable["Banana"] = 30;
    hashTable["Orange"] = 40;
    hashTable.insert({"Mango", 60});

    // 3. Accessing elements
    cout << "Price of Apple: " << hashTable["Apple"] << endl;

    // 4. Iterating over hash table
    cout << "Hash Table Elements:" << endl;
    for (auto &pair : hashTable)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 5. Finding an element
    if (hashTable.find("Banana") != hashTable.end())
    {
        cout << "Banana is present with price: " << hashTable["Banana"] << endl;
    }

    // 6. Erasing an element
    hashTable.erase("Orange");
    cout << "After removing Orange:" << endl;
    for (auto &pair : hashTable)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
