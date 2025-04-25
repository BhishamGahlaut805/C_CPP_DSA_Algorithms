#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

// WAP for Prefix Operator
// Implementation of BODMAS
// 1.Infix ->simple expression of brackets
// 2.Prefix->operators at start ->start reading from last
// 3.Postfix->operators at end->start reading from start

int postfix(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    { // Reading from starting
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); // Pushing integer value in stack
        }
        else
        {
            // else it is a operator so store value in op1 and op2
            // for implementaion

            int op2 = st.top(); // Taking operators value in reverse order as postfix
            st.pop();
            int op1 = st.top();
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
{ // a=1,b=2,c=3,d=4,e=5,f=6,g=7
    // ABCD + *F / +DE *+
    // abcd+f/*de*++
    //A+B*(C+D)/F+D*E

    string s = "1234+*6/+45*+";
    // cin >> s;
    cout << postfix(s) << endl;
    cout << 1 + 2 * (3 + 4) / 6 + 4 * 5 << endl;
    string d = "1234+6/*45*++";
    // cin >> s;
    cout << postfix(d) << endl;
}
