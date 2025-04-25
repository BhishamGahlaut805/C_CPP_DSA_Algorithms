#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    // **Random Access Iterator** (vector) - Can move anywhere
    vector<int> v = {10, 20, 30, 40, 50};

    // **begin() & end()** - Iterating normally
    cout << "Using begin() & end(): ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // **rbegin() & rend()** - Reverse iterators
    cout << "Using rbegin() & rend(): ";
    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // **cbegin() & cend()** - Constant iterators (read-only)
    cout << "Using cbegin() & cend(): ";
    for (auto it = v.cbegin(); it != v.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // **crbegin() & crend()** - Constant reverse iterators
    cout << "Using crbegin() & crend(): ";
    for (auto it = v.crbegin(); it != v.crend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // **Bidirectional Iterator** (list) - Can move forward & backward
    list<int> lst = {1, 2, 3, 4, 5};
    cout << "Using bidirectional iterator (list): ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // **Forward Iterator** (works like bidirectional but only forward)
    cout << "Using forward iterator (list): ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // **Input Iterator** (Read-Only, Single-Pass)
    cout << "Using input iterator: ";
    istream_iterator<int> in(cin);
    istream_iterator<int> eof;
    cout << "You entered: ";
    while (in != eof)
    {
        cout << *in << " ";
        ++in;
    }
    cout << endl;

    // **Output Iterator** (Write-Only, Single-Pass)
    cout << "Using output iterator: ";
    ostream_iterator<int> out(cout, " ");
    *out = 100;
    ++out;
    *out = 200;
    ++out;
    *out = 300;
    cout << endl;

    return 0;
}
