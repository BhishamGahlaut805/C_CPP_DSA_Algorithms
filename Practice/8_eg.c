#include<stdio.h>
#include<stdbool.h>
//sort using recursion

bool sort(int arr[],int n){
    if(n==1){
        return true;
    }

    bool restarray= sort(arr,n-1);
    return(arr[0]<arr[1]&& restarray);

}

int main(){
int arr[10]={2,5,1,4,11,3,234,2322,12,111};
if(sort(arr,10)){
for(int i=0;i<10;i++){
    printf("%d ",arr[i]);
}
}
else{
    printf("-1");
}

}