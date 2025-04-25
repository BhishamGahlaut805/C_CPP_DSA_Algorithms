#include <iostream>
#include <utility> // For including pair

using namespace std;

int main()
{
    // 1. Initializing pairs
    pair<int, string> p1 = {1, "Apple"};
    pair<float, char> p2(3.14, 'A');

    // 2. Accessing pair elements
    cout << "Pair 1: " << p1.first << " -> " << p1.second << endl;
    cout << "Pair 2: " << p2.first << " -> " << p2.second << endl;

    // 3. Using make_pair()
    pair<int, double> p3 = make_pair(10, 99.99);
    cout << "Pair 3: " << p3.first << " -> " << p3.second << endl;

    // 4. Swapping pairs
    pair<int, string> p4 = {2, "Banana"};
    cout << "Before swap: p1 = " << p1.second << ", p4 = " << p4.second << endl;
    p1.swap(p4);
    cout << "After swap: p1 = " << p1.second << ", p4 = " << p4.second << endl;

    // 5. Using pair inside a container
    pair<int, pair<string, double>> nestedPair = {1, {"Mango", 45.6}};
    cout << "Nested Pair: " << nestedPair.first << " -> " << nestedPair.second.first << " : " << nestedPair.second.second << endl;

    return 0;
}
