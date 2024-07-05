### min_max

```c
#include <stdio.h>
 void min_max(int arr[],int n,int result[]){
    int max=arr[0];int min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        else if(arr[i]>max){
            max=arr[i];
        }
    }
    result[0]=min;
    result[1]=max;
}
int main()
{
    int n=5;
    int arr[5]={1,2,3,4,5};
    int result[2];
    min_max(arr,n,result);
    printf("%d\n",result[0]);
    printf("%d",result[1]);
    return 0;
}
```
### removeDuplicate
##### [https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150]
```c
int removeDuplicates(int* arr, int numsSize) {
    if(numsSize==0){
        return 0;
    }
    int j=0;
    for(int i=0;i<numsSize-1;i++){
        if(arr[i]!=arr[i+1]){
            arr[j++]=arr[i];
        }
    }
    arr[j++]=arr[numsSize-1];
    return j;
    
}
```
### removeElement
##### [https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150]
```c
int removeElement(int* nums, int numsSize, int val) {
    int count=0;int k=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=val){
            nums[k++]=nums[i];
            count++;

        }
    }
    return count;
    
}
```
### sort an array
``time complexity=O(n^2)``
``space complexity=O(n)``
```c
#include<stdio.h>
void swap(int *a,int *b){
    int temp= *a;
    *a=*b;
    *b=temp;
}
int main(){
    int n=5;
    int arr[]={3,6,1,2,0};
    for(int i=0;i<n-1;i++){
       for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
           swap(&arr[i],&arr[j]);
        }
       }
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
```

