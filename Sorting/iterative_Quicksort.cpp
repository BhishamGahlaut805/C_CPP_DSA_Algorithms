#include<stdio.h>

//Iterative Quick Sort
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partititon(int arr[], int s, int e)
{
    int x = arr[e];
    int i = s - 1;
    for (int j = s; j < e;j++){
        if(arr[j]<=x){
            i++;
            swap(&arr[i], &arr[j]);
        }

    }
    swap(&arr[i+1], &arr[e]);
    return i + 1;
}

void quick_sort(int arr[],int s,int e){
    int stack[e - s + 1];
    int top = -1;

    //Push s and e into stack
    stack[++top] = s;
    stack[++top] = e;

    while(top>=0){
        e = stack[top--];
        s = stack[top--];

        int x = partititon(arr, s, e);

        //Push elements index left to pivot in stack-->Same as Recursion doing for us
        if(x-1>s){
            stack[++top] = s;           //Here starting idx is pushed first because we are doing pop of ending idx first
            stack[++top] = x - 1;
        }
        if(x+1<e){
            stack[++top] = x + 1;   //Here starting idx is pushed first because we are doing pop of ending idx first
            stack[++top] = e;
        }
        
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}