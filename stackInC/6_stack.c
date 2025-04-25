// Stack questions
#include<stdio.h>
#include<string.h>
#define max 100

//Making a Stack
char stack[max];
int top = -1;
void push(char val){
    if(top==(max-1)){
        printf("\nstack overflow");
    }
    else{
        top++;
        stack[top] = val;
    }
}
void reverse_sent()
{
    char string[max];
    printf("\n Enter a Sentence");
    fgets(string, max, stdin);
    int l = strlen(string);


    for (int i = 0; i < l;i++){
        char word[max] = "";
        while(string[i]!=' '&& i>=l){
            word[i] += string[i];
            i++;
        }
        push(word);
    }
}

int main()
{
    int option;
    do
    {
        printf("\n***** Stack questions ******\n");
        printf("\n 1. Reverse a sentence ");

    } while (option != 10);
    switch (option)
    {
    case 1:
        reverse_sent();
        break;
    }
}