#include <iostream>
//Template_CPP_STL
using namespace std;

// Template function for finding the maximum of two numbers
template <typename T>
T findMax(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    // Using template function with integers
    cout << "Max(10, 20) = " << findMax(10, 20) << endl;

    // Using template function with floating-point numbers
    cout << "Max(5.5, 2.3) = " << findMax(5.5, 2.3) << endl;

    // Using template function with characters
    cout << "Max('A', 'B') = " << findMax('A', 'B') << endl;

    return 0;
}
