#include<iostream>
#include<stack>
using namespace std;

//binary to sentence conversion
void binary(int arr[],int n){
    int ans[n];
    int x=1;
    for(int i=0;i<n;i++){
        while(arr[i]>0){
        int lastdigit=arr[i]%10;
        ans[i]=lastdigit*x;
        x*=2;
        arr[i]/=10;

        }
       // arr[i]=ans[i];
        
    }
    for(int i=0;i<n;i++){
        printf(" %c ",ans[i]);
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    binary(arr,n);
    

}