#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

// WAP for Prefix Operator
// Implementation of BODMAS
// 1.Infix ->simple expression of brackets
// 2.Prefix->operators at start ->start reading from last
// 3.Postfix->operators at end->start reading from start

int prefix(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    { // Reading from last
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); // Pushing integer value in stack
        }
        else
        {
            // else it is a operator so store value in op1 and op2
            // for implementaion

            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;

            default:
                break;
            }
        }
    }
    return st.top();
}
using namespace std;
int main()
{
    // string s;
    // cin >> s;
    // (a + b *(c + d) / f + d *e)
    // ++ a *bcd + / f *de
    // a b c d e f 1 2 3 4 5 6

    // string s = "++1*234+/6+4*5";
    // cout << prefix(s);
    string d = "++1/*2+346*45";
    cout << prefix(d);
}