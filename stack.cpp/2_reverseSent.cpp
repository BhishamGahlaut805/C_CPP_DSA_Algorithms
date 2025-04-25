#include <iostream>
#include <stack>
using namespace std;

// Reverse a Sentence using a Stack
void reverseSentence(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {

        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i]; // pushing the word in the string word
            i++;
        }
        st.push(word); // Pushing word into stack in same direction order as sentence
    }

    while (!st.empty())
    {
        cout << st.top() << " "; // Stack always print in opposite order LIFO
        st.pop();                // POP is necessary to print next word
    }
    cout << endl;
}

int main()
{
    string s;
    cout << "Enter a Sentence\n";
    getline(cin, s);
    cout << "Reverse of Sentence is\n";
    reverseSentence(s);

    // string s="Hello, How are you?";
    // reverseSentence(s);
}