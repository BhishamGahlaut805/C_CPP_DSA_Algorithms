#include <iostream>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;
// WAP to convert Infix to Prefix
// same as infix to Postfix just use reverse of string with bracketts in correction

int precedence(char c)
{
    if (c == '^')
    {
        return 3; // Giving higest precedence
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1; // Not an operator
    }
}

string infixToPrefix(string s)
{

    stack<char> st;
    reverse(s.begin(), s.end()); // Reverse The string

    string result;

    for (int i = 0; i < s.length(); i++)
    {

        // Case1 Number/letter
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            result += s[i];
        }

        // Case2: '(' Push in stack
        //(assume) Reversing opening and closing brackets so that no addional fuction to be made for it
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }

        // Case3:')'
        //(assume) Reversing opening and closing brackets so that no addional fuction to be made for it
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }

        // Case4:operators
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(s[i]))
            {
                result += st.top();
                st.pop();
            }
            // Found with lower precendence push into stack
            st.push(s[i]);
        }
    }
    // Checking if anything left in stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    // reversing result to make it prefix
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string s;
    cout << "Enter Infix(brackett form):" << endl;
    cin >> s;
    cout << "Infix form is:" << endl;
    cout << s << endl;
    cout << "Prefix form is:" << endl;
    cout << infixToPrefix(s) << endl;
}