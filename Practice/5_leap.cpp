#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool leap(int n){
   
   if(n%400==0){
    return true;
   }
   else if(n%100==0){
    return false;
   }
   else if(n%4==0){
    return true;
   }
   else{
    return false;
   }
}

int length(char s[]){
    int count=0,i=0;
    while(s[i]!='\0'){
        count++;
        i++;

    }
    return count;
}
int main(){
//    int n;
//    scanf("%d",&n);
//    leap(n)? printf("leap"):printf("Non leap");
char s[10000]="BhishamGahlaut";
      printf("%d",length(s));

}


