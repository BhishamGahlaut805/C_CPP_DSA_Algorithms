#include <iostream>
#include <stack>
using namespace std;

// Reverse a word using Stack

void reverseWord(string s)
{
    stack<string> ch;
    for (int i = 0; i < s.length(); i++)
    {

        string rev = "";
        rev += s[i];
        ch.push(rev);
    }
    while (!ch.empty())
    {
        cout << ch.top();
        ch.pop();
    }
    cout << endl;
}

int main()
{
    // string s = "hello how are you";
    // reverseWord(s);

    string a;
    getline(cin, a);
    reverseWord(a);
}