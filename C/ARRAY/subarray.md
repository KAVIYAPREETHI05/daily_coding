### split subarray into two equal sum subarray
``time complexity=O(n)``
``space complexity=O(1)``
```c
#include<stdio.h>
int split(int arr[],int n){
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=arr[i];
    }
    int leftsum=0;
    for(int i=0;i<n;i++){
        leftsum+=arr[i];
        int rightsum=totalsum-leftsum;
       
        if(leftsum==rightsum){
            return i+1;
        }
    }
    return -1;
}
void findSum(int arr[],int n){
    int splitnum=split(arr,n);
    if(splitnum==-1 || splitnum==n){
        printf("not possible");
        return;
    }
     for(int i=0;i<n;i++){
          if(splitnum==i){
        printf("\n");
       
    }
         printf("%d ",arr[i]);
     }
    printf("\n");
    }
int main()
{
    int arr[]={1,2,3,6};
    int n=4;
    findSum(arr,n);
    return 0;
}
```
