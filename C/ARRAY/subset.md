### print all subset of an array
``time complexity-O(n*2^n)``
``space complexity-O(n)``
```c
#include<stdio.h>
#include<math.h>
void printSubset(int subsetSize,int subset[]){
    printf("{ ");
    for(int i=0;i<subsetSize;i++){
        printf("%d ",subset[i]);
    }
    printf(" }");
}
void subseq(int arr[],int n){
    //int no_of_subseq=pow(2,n);(instead of this use 1<<n to optimize the code)
    int no_of_subseq=1<<n;
    for(int i=0;i<no_of_subseq;i++){
        int subset[n];int subsetSize=0;
        for(int j=0;j<n;j++){
        if(i&(1<<j)){
            subset[subsetSize++]=arr[j];
        }
    }
    printSubset(subsetSize,subset);
    printf("\n");
    }
        }
int main(){
    int n=4;
    int arr[]={1,2,3,4};
    subseq(arr,n);
}
```
