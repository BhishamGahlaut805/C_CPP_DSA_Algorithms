#include <iostream>
using namespace std;

long long tobinary(int n)
{
    // initializing ans with 0;
    long long ans = 0;
    int i = 1;
    while (n > 0)
    {
        int rem = n % 2; // reminder on dividing by 2
        n /= 2;
        ans += rem * i; // so that rem will add in our ans in its correct place(ones,tens,hundreds...)
        i = i * 10;     // same to make next order(tens,hundreds...)
    }
    return ans;
}
void convert(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        int val = int(s[i]);
        string ans = "";
        ans = ans + to_string(tobinary(val));

        cout << ans << " ";
    }
}
int main()
{
    string s;
    getline(cin, s);
    convert(s);
}
