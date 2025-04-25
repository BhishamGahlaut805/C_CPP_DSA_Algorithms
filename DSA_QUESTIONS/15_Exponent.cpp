#include <bits/stdc++.h>
using namespace std;

// conventional->O(n)
int exp(int n, int p)
{
    int ans = 1;
    for (int i = 0; i < p; i++)
    {
        ans *= n;
    }
    return ans;
}

// Divide and conquer O(log n)
int exp_DivideNconquer(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    else
    {
        int temp = exp_DivideNconquer(n, p / 2);
        if (p % 2 == 0)
        {
            return temp * temp;
        }
        else
        {
            return temp * temp * n;
        }
    }
    return -1;
}

int main()
{
    cout << exp(2, 3) << endl;
    cout << exp_DivideNconquer(2, 3);
}
