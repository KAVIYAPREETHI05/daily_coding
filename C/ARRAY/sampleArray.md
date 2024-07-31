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
### average of elements
``time complexity=O(n)``
``space complexity=O(n)``
```c
#include <stdio.h>
int main(){
    int n;
    int arr[]={1,2,5,5};
    n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
   for(int i=0;i<n;i++){
    sum+=arr[i];
}
float avg=(float)sum/n;
printf("%f",avg);
    return 0;
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
### Check if an array is sorted in ascending order
``time complexity=O(n)``
``space complexity=O(n)``
```c
#include <stdio.h>
int main(){
    int n;
    int arr[]={1,2,5,5};
    n=sizeof(arr)/sizeof(arr[0]);
    int sorted=1;
   for(int i=0;i<n-1;i++){
    if(arr[i]>arr[i+1]){
        sorted=0;
        break;
    }
}
if (sorted){
    printf("given array is sorted");
}
else{
    printf("given array is unsorted");
}

    return 0;
}
```
### second max
``time complexity=O(n)``
``space complexity=O(n)``
```c
#include <stdio.h>
int main(){
    int n;
    int arr[]={1,2,4,5};
    n=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0];
    int second_max;
   for(int i=0;i<n;i++){
    if(arr[i]>max){
        second_max=max;
        max=arr[i];
        
    }
    else if(arr[i]<max && arr[i]!=max){
        second_max=arr[i];
    }
}
if(max==second_max){
    printf("no second largest element");
}
else{
printf("%d",second_max);    
}
return 0;
}
```
### count of even and odd
```c
#include <stdio.h>
int main(){
    int n;
    int arr[]={1,2,4,5,0};
    n=sizeof(arr)/sizeof(arr[0]);
    int odd=0;
    int even=0;
   for(int i=0;i<n;i++){
    if(arr[i]%2==0){
        even++;
    }else{
        odd++;
    }
}
printf("%d even %d odd",even,odd);

return 0;
}
```
### even and odd elements
```c
#include<stdio.h>

int main(){
    int m;
    int arr[]={1,2,3,-1,-2,5,-3};
    m=sizeof(arr)/sizeof(arr[0]);
    printf("negative elements\n");
    for(int i=0;i<m;i++){
        if(arr[i]<0){
            printf("%d ",arr[i]);
        }
    }
    printf("\npositive elements\n");
    for(int i=0;i<m;i++){
        if(arr[i]>=0){
            printf("%d ",arr[i]);
        }
    }

    }
```
### frequency of each element
```c
#include<stdio.h>
int main(){
    int n;
    int arr[]={-1,2,3,-4,-5,-4};
    n=sizeof(arr)/sizeof(arr[0]);
    int min=arr[0];
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
            
        }
        else if(arr[i]<min){
            min=arr[i];
        }
    }
    int range=max-min+1;
    int freq[range];
    
    for(int i=0;i<range;i++){
        freq[i]=0;
    }
    for(int i=0;i<n;i++){
        freq[arr[i]-min]++;
    }
    for(int i=min;i<=max;i++){
        printf("%d occurs %d times\n",i,freq[i-min]);
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
### count the duplicates
``time complexity=O(n)``
``space complexity=O(1)``
```c
#include<stdio.h>
int main(){
    int m;
    int arr[]={1,2,3,4,5,4,5};
    m=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0];
    for(int i=0;i<m;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int freq[max+1];
    for(int i=0;i<=max;i++){
        freq[i]=0;
    }
    for(int i=0;i<m;i++){
        freq[arr[i]]++;
    }
    int count=0;
    for(int i=0;i<=max;i++){
        if(freq[i]>1){
            count++;
        }
    }
    printf("%d",count);
    
    }
```
### deleting  duplicates
Removing duplicates from an array means creating a new array (or modifying the original one) that contains only unique elements, with all duplicate occurrences removed.
``arr = {1, 2, 3, 4, 5, 4, 5} ``
``result = {1, 2, 3, 4, 5}``
```c
#include<stdio.h>
#define MAX_SIZE 100
int main(){
    int m;
    int arr[]={1,2,3,4,5,4,5};
    m=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0];
    for(int i=0;i<m;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int freq[max+1];
    for(int i=0;i<=max;i++){
        freq[i]=0;
    }
    for(int i=0;i<m;i++){
        freq[arr[i]]++;
    }
    
   int result[MAX_SIZE];
   int size;
   for(int i=0;i<m;i++){
       int visited=0;
       for(int j=0;j<size;j++){
           if(arr[i]==result[j]){
               visited=1;
               break;
           }
       }
       if(!visited){
           result[size++]=arr[i];
       }
   }
   for(int i=0;i<size;i++){
       printf("%d ",result[i]);
   }
    }
```
### print unique element
Printing unique elements from an array means identifying and displaying elements that appear exactly once in the array, without modifying the array.
``arr = {1, 2, 3, 4, 5, 4, 5} ``
``1, 2, 3``
```c
#include<stdio.h>
int main(){
    int m;
    int arr[]={1,2,3,4,5,4,5};
    m=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0];
    for(int i=0;i<m;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int freq[max+1];
    for(int i=0;i<=max;i++){
        freq[i]=0;
    }
    for(int i=0;i<m;i++){
        freq[arr[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(freq[arr[i]]==1){
            printf("%d",arr[i]);
        }
    }
    }

```
### print duplicates
```c
#include<stdio.h>
int main(){
    int m;
    int arr[]={1,2,3,4,5,4,5};
    m=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0];
    for(int i=0;i<m;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int freq[max+1];
    for(int i=0;i<=max;i++){
        freq[i]=0;
    }
    for(int i=0;i<m;i++){
        freq[arr[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(freq[arr[i]]>1){
            freq[arr[i]]=0;
            printf("%d",arr[i]);
            
        }
    }
    }
```
### find Occurence
``time complexity=O(n^2)``
``space complexity=O(n)``

```c
#include<stdio.h>
void findOccurence(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]!=-1){
            int count=1;
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    count++;
                    arr[j]=-1;
                    
                }
            }
            printf("%d occurs %d times\n",arr[i],count);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    findOccurence(arr,n);
}
```
### rotate array
``time complexity=O(n)``
``space complexity=O(1)``
```c
#include<stdio.h>
void reverseArray(int arr[],int start,int end){
   while(start<=end){
       int temp=arr[end];
       arr[end]=arr[start];
       arr[start]=temp;
       start++;
       end--;
   }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    int k;
    scanf("%d",&k); 
/*left rotate
    reverseArray(arr,0,k-1);
    reverseArray(arr,k,n-1);
    reverseArray(arr,0,n-1);
  */  
  //right rotate
   reverseArray(arr,0,n-1);
    reverseArray(arr,k,n-1);
    reverseArray(arr,0,k-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
```
### Maximum and minimum
``time complexity=O(n)``
``space complexity=O(1)``
```c
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
        int min=arr[0];
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        else if(arr[i]>max){
            max=arr[i];
            
        }
    }
    printf("Maximum element:%d Minimum element:%d",max,min);
}
```
### move all 0's
``time complexity=O(n)``
``space complexity=O(n)``
```c
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
        int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            int temp=arr[i];
             arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }
        }
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
}
```
### insert an element
```c
#include<stdio.h>
int main(){
    int m;
    int arr[]={1,2,3,4,5};
    m=sizeof(arr)/sizeof(arr[0]);
    int element=5;
    int k=2;
    for(int i=m;i>k;i--){
        arr[i]=arr[i-1];
    }
    arr[k]=element;
    for(int i=0;i<=m;i++){
        printf("%d ",arr[i]);
    }
    }
```
### delete an element
``time complexity=O(n)``
``space complexity=O(n)``
```c
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    int index;
    scanf("%d",&index);
    if(index<0){
        printf("Invalid input");
        return 0;
    }
    else if(index>n){
        printf("Position out of range");
        return 0;
    }
    for(int i=index;i<n-1;i++){
        
            arr[i]=arr[i+1];
    }
    for(int i=0;i<n-1;i++){
        printf("%d",arr[i]);
    }
}
```
### merge array
Merging two arrays combines them into a single array, retaining all elements from both arrays. The merge operation does not remove duplicates and preserves the order of elements as they appear in the original arrays.
```c
#include<stdio.h>
int main(){
    int n,m;
    int arr[]={1,2,3};
    int brr[]={4,3,5};
    m=sizeof(arr)/sizeof(arr[0]);
    n=sizeof(brr)/sizeof(brr[0]);
    int merged[m+n];
    int k=0;
    for(int i=0;i<m;i++){
        merged[k++]=arr[i];
    }
    for(int i=0;i<n;i++){
        merged[k++]=brr[i];
    }
    for(int i=0;i<k;i++){
        printf("%d ",merged[i]);
    }
    
    }
```
### union array
The union of two arrays combines all distinct elements from both arrays into a new array, without duplicates. This concept is commonly used in set theory where the union of two sets contains all the elements that are in either set.
```c
//unsorted
#include<stdio.h>
#define MAX_SIZE 100
int ispresent(int value,int array[],int n){
    for(int i=0;i<n;i++){
        if(value==array[i]){
            return 1;
        }
    }
    return 0;
}
void unionArray(int arr[],int m,int brr[],int n,int result[],int *size){
    *size=0;
    for(int i=0;i<m;i++){
        if(!ispresent(arr[i],result,*size)){
            result[(*size)++]=arr[i];
        }
    }
    for(int j=0;j<n;j++){
        if(!ispresent(brr[j],arr,m) && !ispresent(brr[j],result,*size)){
            result[(*size)++]=brr[j];
        }
    }
}
int main(){
    int n,m;
    int arr[]={1,2,3};
    int brr[]={3,5,4};
    m=sizeof(arr)/sizeof(arr[0]);
    n=sizeof(brr)/sizeof(brr[0]);
    int result[MAX_SIZE];
    int size;
    unionArray(arr,m,brr,n,result,&size);
    for(int i=0;i<size;i++){
        printf("%d ",result[i]);
    }
    
    }

```
### count pairs with given sum
``time complexity=O(n^2);``
``space complexity=O(1);``
```c
#include <stdio.h>
int getPairsCount(int arr[],int n,int k){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i]+arr[j])==k){
                count++;
            }
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    
    printf("Number of pairs with sum %d: %d\n", k, getPairsCount(arr, n, k));
    
    return 0;
}
```
###



