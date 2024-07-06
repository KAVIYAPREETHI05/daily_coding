### 1.print subarray
``time complexity=O(n3)``
``space complexity=O(n)``
```c
#include <stdio.h>
int main()
{
    int n=5;
    int arr[]={1,2,3,4,5};
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
           for(int k=i;k<=j;k++){
                printf("%d ",arr[k]);
           }
            printf("\n");
        }
    }
    return 0;
}
```
### 2.split subarray into two equal sum subarray
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
### 3.Check if subarray with given product exists in an array
``time complexity=O(n^2)``
``space complexity=O(1)``
```c
#include <stdio.h>
int checkproduct(int arr[],int n,int target){
    for(int i=0;i<n;i++){
         int product=1;
        for(int j=i;j<n;j++){
                product*=arr[j];
                if(product==target){
                return 1;
                }
            }
    }
    return 0;
}
int main()
{
    int n=5;
    int target=12;
    int arr[]={1,-2,3,-4,-5};
    if(checkproduct(arr,n,target)){
        printf("yes");
        }
    else{
        printf("no");
    }
return 0;
}
```
### 4.Subarray of size k with given sum
``time complexity=O(n.k)``
``space complexity=O(1)``
```c
#include <stdio.h>
int checksum(int arr[],int n,int sum,int k,int *start,int *end){
    for(int i=0;i<=n-k;i++){
         int curr_sum=0;
        for(int j=i;j<i+k;j++){
                curr_sum+=arr[j];
                if(curr_sum==sum){
                    *start=i;
                    *end=j;
                return 1;
                }
            }
    }
    return 0;
}
int main()
{
    int n=5;
    int sum=-6;
    int k=3;
    int arr[]={1,-2,3,-4,-5};
    int start=0;int end=0;
    if(checksum(arr,n,sum,k,&start,&end)){
        printf("yes\n");
        printf("starts from %dth index & ends at %dth index",start,end);
        }
    else{
        printf("no");
    }
return 0;
}
```
### 5.Count subarrays with all elements greater than K
``time complexity=O(n)``
``space complexity=O(1)``
```c
#include <stdio.h>
int count(int arr[],int n,int value){
    int count=0;
    int number=0;
    for(int i=0;i<n;i++){
        if(arr[i]>value){
            count+=1;
        }
        else{
            number+= (count)*(count+1)/2;
            count=0;
        }
    }
    if(count){
         number+= count*(count+1)/2;
    }
    return number;
}
int main()
{
    int arr[]={1,4,5,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int value=3;
    printf("%d",count(arr,n,value));

    return 0;
}
```
### 6.Check whether an Array is Subarray of another Array
``time complexity=O(n*m)``
``space complexity=O(1)``
```c
#include <stdio.h>
int count(int arr[],int n,int brr[],int m){
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<m;j++){
            if(arr[i+j]!=brr[j]){
                 break;
            }
             if(j==m-1){
        return 1;
    }
        }
    }
    return 0;
    }
int main()
{
    int arr[]={1,4,5,2,3,4};
    int brr[]={5,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=sizeof(brr)/sizeof(brr[0]);
    if(count(arr,n,brr,m)){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}
```
(or)
``time complexity=O(n*n)``
``space complexity=O(1)``
```c
#include <stdio.h>
int count(int arr[],int n,int brr[],int m){
    int i=0;int j=0;
    while(i<n && j<m){
        if(arr[i]==brr[j]){
            i++;
            j++;
            if(j==m){
                return 1;
            }
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    return 0;
    }
int main()
{
    int arr[]={1,4,5,2,3,4};
    int brr[]={5,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=sizeof(brr)/sizeof(brr[0]);
    if(count(arr,n,brr,m)){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}
```

