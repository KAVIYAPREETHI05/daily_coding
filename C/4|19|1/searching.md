### second largest
```c
#include <stdio.h>
int secondLargest(int n,int arr[]){
    int largest=-1;
    int second_largest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            second_largest=largest;
            largest=arr[i];
        }
        else if(arr[i]>second_largest && arr[i]!=largest){
            second_largest=arr[i];
        }
    }
    return second_largest;
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int num=secondLargest(n,arr);
    printf("%d",num);

    return 0;
}
```
### transition point

the first index where 1 was observed, and before that, only 0 was observed.
```c
int transitionPoint(int arr[], int n) {
        for(int i=n-1;i>=0;i--){
            if(arr[i]==1 && (i==0||arr[i-1]==0 )){
                return i;
            }
        }
        return -1;
    }
```
### floor in sorted array
```c
 static int findFloor(long arr[], int n, long x) {
        int left=0;int right=n-1;int floorIndex=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(x==arr[mid]){
                return mid;
            }
            else if(arr[mid]>x){
                right=mid-1;
            }
            else if(arr[mid]<x){
                floorIndex=mid;
                left=mid+1;
            }
        }
        return floorIndex;
        
        
    }
```
### Find Pair Given Difference
```c

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int findPair(int n, int x, int[] arr) {
    qsort(arr, n, sizeof(int), compare);
       int left=0;int right=1;
       while(right<n){
           int diff=arr[right]-arr[left];
           if(diff==x){
               return 1;
           }
           else if(diff<x){
               right++;
           }
           else{
               left++;
           }
           if(right==left){
               right++;
           }
           
       }
       return -1;
    }
}
```
### find square root
```c
long long int floorSqrt(long long int n) {
    long long int num=(long long int )sqrt(n);
    return num;
}
```
or
```c
long long int floorSqrt(long long int n) {
    long long int left=1;long long int right=n;long long int ans=0;
    while(left<=right){
        long long int mid=(left+right)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            left=mid+1;
            ans=mid;
            
        }
        else{
            right=mid-1;
        }
    }
    return ans;
}
```
### Find Kth Rotation
```c
public int findKRotation(int n,int arr[]) {
        int index=0; 
        int min=arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]<min){
                min=arr[i];
                index=i;
            }
           
        }
        return index;
    }
```
