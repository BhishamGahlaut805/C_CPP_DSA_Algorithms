#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

// Convert INfix to Postfix

// code for precedence of operators
int precedence(char c)
{
    if (c == '^')
    {
        return 6; // Giving higest precedence
    }
    else if (c == '*' || c == '/')
    {
        return 5;
    }
    else if (c == '+' || c == '-')
    {
        return 4;
    }
    else if (c == '<' || c == '>' || c == '<=' || c == '>=' || c == '!=')
    {
        return 3;
    }

    else if (c == '&')
    {
        return 2;
    }
    else if (c == '|')
    {
        return 1;
    }
    else
    {
        return -1; // Not an operator
    }
}

// Main function for infix to postfix
string infixToPostfix(string s)
{
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++)
    {

        // Case1:if it is a num/letter directly print it

        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            result += s[i];
        }

        // Case2: if it's a opening bracket ')' push it into stack
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        // Case3: if it's a closing bracket')' then pop all operators from stack until opening
        // bracket ')' is not found->start of next opening bracket

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) // Double sure to have empty stack
            {
                st.pop();
            }
        }

        // Case4: It's an operator pop from stack until operator with less precedence is found
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(s[i]))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    // Checking if anything left in stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string s;
    cout << "Enter Infix(brackett form):" << endl;
    cin >> s;
    cout << "Infix form is:" << endl;
    cout << s << endl;
    cout << "Postfix form is:" << endl;
    cout << infixToPostfix(s) << endl;
}