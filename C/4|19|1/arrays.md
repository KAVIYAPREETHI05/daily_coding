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
    while(start<end){
        temp[j++]=arr[end];
        temp[j++]=arr[start];
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
