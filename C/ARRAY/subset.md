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
### Find whether an array is subset of another array
``time complexity-O(n*m)``
``space complexity-O(1)``
```c
#include <stdio.h>
int checkSubset(int arr[],int brr[],int n,int m){
        for(int i=0;i<m;i++){
            int found=0;
        for(int j=0;j<n;j++){
            if(brr[i]==arr[j]){
                found=1;
                break;
            }
        }
        if(found==0){
            return 0;
        }
        }
        
        return 1;
}
int main()
{
    int arr[]={3,4,11,2,9,21};
    int brr[]={9,2,21};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=sizeof(brr)/sizeof(brr[0]);
    if(checkSubset(arr,brr,n,m)){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}
```
