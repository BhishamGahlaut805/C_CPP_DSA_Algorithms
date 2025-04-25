#include <iostream>
#include <array>    //including array STL
#include <algorithm> // For sort and reverse

using namespace std;

int main()
{
    // 1. Initializing an array
    array<int, 5> arr1 = {1, 2, 3, 4, 5}; // Fixed-size array of size 5
    array<int, 5> arr2 = {10, 20, 30, 40, 50};

    // 2. Accessing elements
    cout << "First element: " << arr1.front() << endl;
    cout << "Last element: " << arr1.back() << endl;
    cout << "Element at index 2 using at(): " << arr1.at(2) << endl;

    // 3. Modifying elements
    arr1[1] = 100;
    cout << "After modifying second element: ";
    for (int num : arr1)
        cout << num << " ";
    cout << endl;

    // 4. Sorting an array
    sort(arr1.begin(), arr1.end());
    cout << "Sorted array: ";
    for (int num : arr1)
        cout << num << " ";
    cout << endl;

    // 5. Reversing an array
    reverse(arr1.begin(), arr1.end());
    cout << "Reversed array: ";
    for (int num : arr1)
        cout << num << " ";
    cout << endl;

    // 6. Checking size of the array
    cout << "Size of array: " << arr1.size() << endl;

    // 7. Swapping two arrays
    arr1.swap(arr2);
    cout << "After swapping with arr2: ";
    for (int num : arr1)
        cout << num << " ";
    cout << endl;

    array<int, 0> arr4 = {};
    // 8. Checking if array is empty
    cout << "Is array empty? " << (arr4.empty() ? "Yes" : "No") << endl;
    cout << "Is array empty? " << (arr1.empty() ? "Yes" : "No") << endl;

    return 0;
}
