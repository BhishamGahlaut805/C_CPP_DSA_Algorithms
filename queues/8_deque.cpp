#include <iostream>
#include <deque>
using namespace std;
// Deque->Doubly ended queue
int main()
{
    deque<int> dq;
    // dq.push_back(1);
    // dq.push_back(2);
    // dq.push_back(3);
    // for (auto i : dq)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // for (int i = dq.front(); i <= dq.size(); i++)
    // {
    //     cout << i << " ";
    // }
    // dq.push_front(100);
    // dq.push_front(50);

    //Sliding Window Problem
    int n,k;
    int arr[n];
    cout << "Enter size of array : ";
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    cin >> k;

    for (int i = 0; i < n;i++){
        dq.push_back(arr[i]);
    }
    for (int i = dq.front(); i <= dq.size(); i++)
    {
        cout << i << " ";
    }

}