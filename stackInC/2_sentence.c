#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define n 500
struct stack
{
    int size;
    int *arr;
    int top;
};

void push(struct stack *s, int x)
{
    if (s->top == s->size - 1)
    {
        printf("Stack overflow No elements can be added\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = x;
    }
}

void pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("No more elements to pop");
        return;
    }
    s->top--;
}

int Top(struct stack *s)
{
    if (s->top == -1)
    {
        printf("No more elements present");
        return -1;
    }
    return s->arr[s->top];
}
bool empty(struct stack *s)
{
    return s->top == -1;
}

void reverse(char s[n]){
    struct stack st;
    //Basic idea is to push every word into stack and then LIFO print

    for(int i=0;i<strlen(s);i++){
        char word[n]="";
        while(s[i]!=' '&& i<strlen(s)){
            word[i]+=s[i];
            i++; //for pushing full word till ' '

        }
        //push(st,word);
    }


}
int main(){


}