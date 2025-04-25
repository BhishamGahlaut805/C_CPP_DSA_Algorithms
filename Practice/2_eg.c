#include<stdio.h>
//Print nth fibonacci number
extern int a=50001;
int fib(int n){
    if(n==0||n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
void fibo(int n){
    int a=0;
    int b=1,c;
    
    for(int i=0;i<n;i++){
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
    }
}

int main(){
    //For printing a Fibonacci Series
    for(int i=0;i<10;i++){
        printf("%d ",fib(i));
    }
    printf("\n");
    fibo(10);


}