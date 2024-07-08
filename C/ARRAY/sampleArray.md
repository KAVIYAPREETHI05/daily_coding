### get input and print output
``time complexity=O(n)``
``space complexity=O(n)``
```c
#include<stdio.h>
int main(){
    int n;
     int arr[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
```
### sum of an array
``time complexity=O(n)``
``space complexity=O(n)``
```c
#include<stdio.h>
int main(){
     int arr[]={1,2,3,4,5};
     int n=sizeof(arr)/sizeof(arr[0]);
     int sum=0;
     for(int i=0;i<n;i++){
         sum+=arr[i];
    }
    printf("%d ",sum);
}
```
### find max
``time complexity=O(n)``
``space complexity=O(n)``
```c
#include<stdio.h>
int main(){
     int arr[]={1,2,3,4,5};
     int n=sizeof(arr)/sizeof(arr[0]);
     int max=arr[0];
     for(int i=0;i<n;i++){
         if(arr[i]>max){
             max=arr[i];
         }
    }
    printf("%d ",max);
}
```
### reverse an array
``time complexity=O(n)``
``space complexity=O(n)``
```c
#include<stdio.h>
int main(){
     int arr[]={1,2,3,4,5};
     int n=sizeof(arr)/sizeof(arr[0]);
     int max=arr[0];
     for(int i=0;i<n/2;i++){
         int temp=arr[i];
         arr[i]=arr[n-1-i];
         arr[n-1-i]=temp;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
```
### linear search
``time complexity=O(n)``
``space complexity=O(n)``
```c
#include<stdio.h>
int main(){
     int arr[]={1,2,3,4,5};
     int n=sizeof(arr)/sizeof(arr[0]);
     int target=3;
     int found=0;
     for(int i=0;i<n;i++){
        if(arr[i]==target){
            printf("Element %d is found at index %d",target,i);
            found=1;
            break;
        }
    }
    if(!found){
        printf("Element is not found");
    }
}
```
### binary search
``time complexity=O(log n)``
``space complexity=O(1)``
```c
#include<stdio.h>
int binarysearch(int arr[],int n,int target){
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else if(arr[mid]>target){
            right=mid-1;
        }
    }
    return -1;
}
int main(){
     int arr[]={1,2,3,4,5};
     int n=sizeof(arr)/sizeof(arr[0]);
     int target=3;
     if(binarysearch(arr,n,target)){
         printf("target found");
     }
     else{
         printf("target not found");
     }
}
```
### bubble sort
``time complexity=O(n^2)``
``space complexity=O(1)``
```c
#include<stdio.h>
void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
}
int main(){
     int arr[]={1,5,2,4,3};
     int n=sizeof(arr)/sizeof(arr[0]);
     (bubblesort(arr,n));
}
```
### selection sort
``time complexity=O(n^2)``
``space complexity=O(1)``
```c
#include<stdio.h>
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        int temp=arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
}
int main(){
     int arr[]={1,5,2,4,3};
     int n=sizeof(arr)/sizeof(arr[0]);
     selectionSort(arr,n);
}
```
### min_max
``time complexity=O(n)``
``space complexity=O(1)``
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
``time complexity=O(n)``
``space complexity=O(1)``
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
``time complexity=O(n)``
``space complexity=O(1)``

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
### sort 0s, 1s and 2s
``time complexity=O(n)``
``space complexity=O(1)``
```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sort012(int a[], int n) {
    int low = 0, mid = 0, high = n - 1;
    
    while (mid <= high) {
        switch (a[mid]) {
            case 0:
                swap(&a[low], &a[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&a[mid], &a[high]);
                high--;
                break;
        }
    }
}
```
### Move all negative elements to end
``time complexity=O(n)``
``space complexity=O(1)``
```c
#include <stdio.h>
void check(int arr[],int n){
   int positiveIndex=0;
   for(int i=0;i<n;i++){
       if(arr[i]>0){
           if(i!=positiveIndex){
               int temp=arr[i];
               arr[i]=arr[positiveIndex];
               arr[positiveIndex]=temp;
           }
           positiveIndex++;
       }
   }
}
int main()
{
    int arr[]={1, -1, 3, 2, -7, -5, 11, 6 };
    int n=sizeof(arr)/sizeof(arr[0]);
    check(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
```
