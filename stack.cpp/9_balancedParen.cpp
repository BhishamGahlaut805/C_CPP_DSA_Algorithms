#include <iostream>
#include <stack>
using namespace std;

// Check if a parenthesis is valid or not
bool isValid(string s)
{
    stack<char> st;
    bool ans = true;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() and st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() and st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() and st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else
        {
            ans = false;
            break;
        }
    }
    if (!st.empty())
    {
        ans = false;
    }

    return ans;
}

int main()
{

    string s;
    cin >> s;

    // Ternary operator
    isValid(s) ? printf("Valid Parenthesis") : printf("Invalid parenthesis");
}