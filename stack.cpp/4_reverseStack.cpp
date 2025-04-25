#include <iostream>
#include <stack>
using namespace std;

// WAP to Reverse a stack by not adding into another stack

void insertatBottom(stack<int> &st, int element)
{

    if (st.empty())
    {
        st.push(element);
        return;
    }
    int top_element = st.top();
    st.pop();
    insertatBottom(st, element); // Recursive call
    st.push(top_element);
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int element = st.top();
    st.pop();
    reverseStack(st);
    insertatBottom(st, element);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    // cout << "Original stack:\n";
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;

    reverseStack(st);
    cout << "Reverse stack:\n";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}