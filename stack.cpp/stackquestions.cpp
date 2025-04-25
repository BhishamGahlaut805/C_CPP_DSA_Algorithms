//Stack questions
#include<iostream>
#include<stack>
using namespace std;

void reverse_sent(){
    string s;
    printf("\n Enter a Sentence ");
    getline(cin,s);

    stack<string> st;
    for (int i = 0; i < s.length();i++){
        string word = ""; // Making a String to save ans in stack
        while(s[i]!=' '&& i<s.length()){
            word += s[i];   //Pushingg the word in string word
            i++;
        }
        st.push(word);  //Pushing every word in stack

    }
while(!st.empty()){
    cout << st.top() << " ";
    st.pop();
}
cout << endl;
}

int main(){
    int option;
    do{
        printf("\n***** Stack questions ******\n");
        printf("\n 1. Reverse a sentence ");

    } while (option != 10);
    switch(option){
        case 1:
            reverse_sent();
            break;
    }

}