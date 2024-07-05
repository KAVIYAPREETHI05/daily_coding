### 1.print all subsequence of an array
``time complexity-O(n*2^n)``
``space complexity-O(n)``
```c
#include<stdio.h>
#include<math.h>

void subseq(int arr[],int n){
    //int no_of_subseq=pow(2,n);(instead of this use 1<<n to optimize the code)
    int no_of_subseq=1<<n;
    for(int i=0;i<no_of_subseq;i++){
        for(int j=0;j<n;j++){
        if(i&(1<<j)){
            printf("%d ",arr[j]);
        }
    }
    printf("\n");
    }
        }
int main(){
    int n=4;
    int arr[]={1,2,3,4};
    subseq(arr,n);
}
```
