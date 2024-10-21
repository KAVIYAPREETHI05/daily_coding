### array leader
```c
#include <stdio.h>
#include<stdlib.h>
void func(int n,int arr[n]){
    int leader=arr[n-1];
    int *temp=(int*)malloc(n*sizeof(int));
    int j=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>leader || i==n-1){
            leader=arr[i];
            temp[j++]=leader;
        }
    }
    for(int i=j-1;i>=0;i--){
        printf("%d ",temp[i]);
    }
    free(temp);
}
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    func(n,arr);

    return 0;
}
```
### equilibrium point
```c
#include <stdio.h>
#include<stdlib.h>
void func(int n,int arr[n]){
    if(n==1){
        printf("%d",n);
    }int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    int leftsum=0;
    for(int i=0;i<n;i++){
        if(leftsum==total-leftsum-arr[i]){
            printf("%d",i+1);
            break;
        }
        leftsum+=arr[i];
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    func(n,arr);

    return 0;
}
```
### sort 0's and 1's
```c
#include <stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void func(int n,int arr[n]){
    int left=0;int right=n-1;int mid=0;
    while(mid<=right){
       switch(arr[mid]){
        case 0:
            swap(&arr[mid],&arr[left]);
            left++;
            mid++;
            break;
        
        case 1:
            mid++;
            break;
        case 2:
            swap(&arr[mid],&arr[right]);
            right--;
            break;
       }    }
        for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    }
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    func(n,arr);

    return 0;
}
```
### reverse array in groups
```c
#include <stdio.h>
#include<stdlib.h>
void reverse(int  arr[],int start,int end){
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
void func(int n,int arr[n],int k){
     int end=0;
    for(int i=0;i<n;i+=k){
        int  start=i;
       
        if((i+k-1)<n-1){
            end=i+k-1;
        }
        else{
            end=n-1;
        }
        reverse(arr,start,end);
    }
        for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k=2;
    func(n,arr,k);

    return 0;
}
```
### zigzag array
```c
#include <stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}
void func(int n,int arr[n]){
    for(int i=0;i<n-1;i++){
        if(i%2==0){
            if(arr[i]>arr[i+1]){
                swap(&arr[i],&arr[i+1]);
            }
        }
        else{
            if(arr[i]<arr[i+1]){
                swap(&arr[i],&arr[i+1]);
            }
        }
    }
        for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    func(n,arr);
    return 0;
}
```
### rearrange array alternatively
```c
#include <stdio.h>
#include<stdlib.h>
void func(int n,int arr[n]){
    int * temp=(int *)malloc(n*sizeof(int));
    int start=0;int end=n-1;int j=0;
    while(start<=end){
         if (start == end) {  
            temp[j++] = arr[start];  
            
             
         } else {
            temp[j++] = arr[end];  
            temp[j++] = arr[start];  
        }
        start++;
        end--;
    }
        for(int i=0;i<j;i++){
        printf("%d ",temp[i]);
    }
    free(temp);
}
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    func(n,arr);
    return 0;
}
```
(or)
```c
#include <stdio.h>
#include<stdlib.h>

void func(int n,int arr[n]){
    int start=0;int end=n-1;int j=0;
    while(start<end){
        printf("%d ",arr[end]);
        printf("%d ",arr[start]);
        start++;
        end--;
    }
       if(n%2!=0){
           printf("%d",arr[start]);
       }
}
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    func(n,arr);
    return 0;
}
```
### missing element in array
```c
int missingNumber(int n, int arr[]) {

    int total=0;
    for(int i=0;i<n-1;i++){
        total+=arr[i];
    }
    int sum_num=(n*(n+1))/2;
    return sum_num-total;
}
```
### kth element of two sorted array
```c
#include <stdio.h>
#include<stdlib.h>

void func(int n1,int n2,int arr[n1],int brr[n2],int r){
    int m=n1+n2;
   int * temp=(int *)malloc(m*sizeof(int));
   int i=0;int j=0;int k=0;
   while(i<n1 && j<n2){
       if(arr[i]<brr[j]){
           temp[k++]=arr[i++];
       }
       else{
           temp[k++]=brr[j++];
       }
   }
   while(i<n1){
       temp[k++]=arr[i++];
       
   }
   while(j<n2){
       temp[k++]=brr[j++];
   }
   if(r>=0 && r<k){
       printf("%d",temp[r]);
   }
   else{
       printf("out of bounds");
   }
   free(temp);
}
int main() {
    int n1;
    scanf("%d",&n1);
   int n2;
    scanf("%d",&n2);    
    int arr[n1];
    for(int i=0;i<n1;i++){
        scanf("%d",&arr[i]);
    }
    int brr[n2];
    for(int i=0;i<n2;i++){
        scanf("%d",&brr[i]);
    }
    int k=3;
    func(n1,n2,arr,brr,k);
    return 0;
}
```
### check array are equal or not
```c
#include <stdio.h>
#include<stdlib.h>
#define max 100

void func(int n1,int n2,int arr[n1],int brr[n2]){
     int found=0;
    if(n1!=n2){
        found=1;
    }
    int* temp=(int*)malloc(max*sizeof(int));
    for(int i=0;i<max;i++){
        temp[i]=0;
    }
    for(int i=0;i<n1;i++){
        temp[arr[i]]++;
    }
    for(int j=0;j<n2;j++){
        temp[brr[j]]--;
    }
   
    for(int i=0;i<max;i++){
        if(temp[i]!=0){
        found=1;
            break;
        }
    }
    if(found){
        printf("not equal");
    }
    else{
        printf("equal");
    }
    free(temp);
   
    }
   
int main() {
    int n1;
    scanf("%d",&n1);
   int n2;
    scanf("%d",&n2);    
    int arr[n1];
    for(int i=0;i<n1;i++){
        scanf("%d",&arr[i]);
    }
    int brr[n2];
    for(int i=0;i<n2;i++){
        scanf("%d",&brr[i]);
    }
    int k=3;
    func(n1,n2,arr,brr);
    return 0;
}
```
## Part II

### min and max in array
```c
strut Pair{
    long min;
    long max;
};
struct Pair getMinMax(int arr[],int n){
    struct Pair result;
        result.min=arr[0];
        result.max=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<result.min){
                result.min=arr[i];
            }
            else if(arr[i]>result.max){
                result.max=arr[i];
            }
        }
        return result;
        
    }
```
### reverse array
```c
void reverseArray(int arr[],int n) {
        for(int i=0;i<n/2;i++){
            int temp=arr[i];
            arr[i]=arr[n-1-i];
            arr[n-1-i]=temp;
            
        }
```
### rotate array by 1
```c
 void rotate(int[] arr) {
        int n=arr.length;
        int temp=arr[n-1];
        for(int i=n-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
    }
```
### array duplicates
```c
int* duplicates(long long arr[], int n, int* returnSize) {
    int* result = (int*)malloc(n * sizeof(int)); // Allocate memory for result array
    int resIndex = 0; // Initialize index for result array

    for (int i = 0; i < n; i++) {
        int index = arr[i] % n;
        arr[index] += n;
    }

    for (int i = 0; i < n; i++) {
        if ((arr[i] / n) > 1) {
            result[resIndex++] = i; // Add index to result if condition is met
        }
    }

    if (resIndex == 0) {
        result[resIndex++] = -1; // Add -1 if no duplicates found
    }

    *returnSize = resIndex; // Set the size of the result array
    return result; // Return the result array
}

```
### count occurence
```c
 int countOccurrences(int arr[], int n, int x)
    {
        int res = 0;
        for (int i=0; i<n; i++)
            if (x == arr[i])
              res++;
        return res;
    }
    
```
### sort 0's 1's 2's
```c
//User function Template for C
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
### move all zeros to one side
```c
void segregateElements(int arr[],int n) {
       int* temp = (int*)malloc(n * sizeof(int)); 
       
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                temp[j++]=arr[i];
                
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                temp[j++]=arr[i];
                
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=temp[i];
        }
        free(temp);
    }
```
