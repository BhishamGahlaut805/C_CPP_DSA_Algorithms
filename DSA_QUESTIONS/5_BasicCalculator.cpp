// Given a string s which represents an expression, evaluate this expression and return its value.
// The integer division should truncate toward zero.
// You may assume that the given expression is always valid.All intermediate results will be in the range of[-231, 231 - 1]
// Note : You are not allowed to use any built -in function which evaluates strings as mathematical expressions,such as eval().

#include <iostream>
#include <stack>
using namespace std;

int evaluateExpression(string s)
{
    stack<int> stk;
    int num = 0;
    char sign = '+';

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');  //For Handling MultiDigit Numbers
            // it works like this:
            // num = 0 * 10 + (s[i] - '0') = 0 + (s[i] - '0')
            // num = 0 * 10 + (s[i] - '0') = 0 + (s[i] - '0')
            //and we multiply by 10 to shift the previous digit to the left
            // and add the new digit to the right.
        }

        // If the current character is not a digit and not a space, or if it's the last character
        // we need to process the previous number and operator
        if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1)
        {
            if (sign == '+')
            {
                stk.push(num);
            }
            else if (sign == '-')
            {
                stk.push(-num);
            }
            else if (sign == '*')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top * num);
            }
            else if (sign == '/')
            {
                int top = stk.top();
                stk.pop();
                stk.push(top / num); // Integer division truncates towards zero
            }
            sign = s[i];
            num = 0;
        }
    }

    int result = 0;
    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }

    return result;
}

int main()
{
    string expression = "3+2*2-4/2";
    cout << "The Output of  (3 + 2 * 2 - 4 / 2 ) is : "<< evaluateExpression(expression) << endl;
}
