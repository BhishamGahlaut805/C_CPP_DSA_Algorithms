#include <iostream>
#include <string.h>
using namespace std;

void reverse(string str)
{
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        str[i] = str[n - i + 1];
    }
}
long long convert(int n)
{
    long long bin = 0;
    int rem, i = 1;

    while (n != 0)
    {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}
void maincode(string str)
{
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        int val = int(str[i]);

        string ans = "";
        ans = ans + to_string(convert(val));
        // reverse(ans);
        cout << ans << " ";
    }
}

int main()
{
    string s;
    getline(cin, s);
    maincode(s);
}