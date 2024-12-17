## Linear Search

```c
#include <stdio.h>
int linearSearch(int n,int arr[],int find){
    for(int i=0;i<n;i++){
       if(arr[i]==find){
           return 1;
       }
   }
   return 0;
}

int main() {
   int n;
   int arr[]={1,2,3,5,6,3,9,8,0};
   n=sizeof(arr)/sizeof(arr[0]);
   int find=6;
   
   if(linearSearch(n,arr,find)){
       printf("%d is found", find);
   }
   else{
       printf("%d is not found", find);
   }
   

    return 0;
}
```

## Binary Search
```c
#include <stdio.h>
int binarySearch(int n,int arr[],int find){
    int left=0;int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==find){
            return 1;
        }
        else if(arr[mid]>find){
            right=mid-1;
        }
        else if(arr[mid]<find){
            left=mid+1;
        }
    }
    return 0;
}

int main() {
   int n;
   int arr[]={13,45,56,67,78,89};
   n=sizeof(arr)/sizeof(arr[0]);
   int find=78;
   
   if(binarySearch(n,arr,find)){
       printf("%d is found", find);
   }
   else{
       printf("%d is not found", find);
   }
   

    return 0;
}
```
## gfg

### missing number in array
```c
#include <stdio.h>

int missingNumber(int arr[], int n) {
    int origiSum = 0, arrSum = 0;

    // Calculate the sum of elements in the array
    for (int i = 0; i < n; i++) {
        arrSum += arr[i];
    }

    // Calculate the sum of numbers from 1 to n+1
    for (int i = 1; i <= n + 1; i++) {
        origiSum += i;
    }

    // Return the missing number
    return origiSum - arrSum;
}

int main() {
    int arr[] = {1, 2, 4, 6, 5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Number of elements in the array
    printf("The missing number is: %d\n", missingNumber(arr, n));
    return 0;
}

```
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
### search in matrix
```c
int matSearch (int row, int col, int mat[row][col], int x)
{
     for(int i=0;i<row;i++){
            if(mat[i][col-1]>=x && mat[i][0]<=x){
                for(int j=0;j<col;j++){
                    if(mat[i][j]==x){
                        return 1;
                    }
                }
              
            }
        }
        return 0;
    
}
```
### bitonic point
first strictly increasing and then maybe strictly decreasing, find the maximum element in the array.
```c
 int findMaximum(int arr[], int n) {
        int max=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }
```
### search in rotated sorted array
```c

    int search(int n,int arr[], int key) {
    
        int left=0;int right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]==key){
                return mid;
            }
            else if(arr[left]<=arr[mid]){
                if(key>=arr[left] && key<arr[mid]){
                     right=mid-1;
                }
                else{
                    left=mid+1;
                }
               
                
            }
            else{
                if(key>arr[mid] && key<=arr[right]){
                    left=mid+1;
                    
                }
                else{
                    right=mid-1; 
                }
            }
        }
        return -1;
    }

```
### majority element
A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.
```c
int majorityElement(int n,int arr[]) {
        if(n==1){
            return arr[0];
        }
        int strictSize=n/2;
        int count=0;
        for(int i=0;i<n;i++){
            count=1;
           if(arr[i]!=-1){
                for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    count++;
                    arr[j]=-1;
                }
                
            }
           }
            if(count>strictSize){
                return arr[i];
            }
        }
        return -1;
    }
```
### kth smallest
```c
//time limit exceeded
int compare(const void *a,const void *b){
    return (*(int*)a- *(int *)b);
}
int kthSmallest(int arr[], int n, int k) {
    qsort(arr,n,sizeof(int),compare);
    
    return arr[k-1];
    
}
```
### number of occurence
```c

    int count(int arr[], int n, int x) {
	    int firstIndex=-1; int lastIndex=-1;
	    for(int i=0;i<n;i++){
	        if(arr[i]==x ){
	            firstIndex=i;
	            break;
	        }
	    }
	    if(firstIndex==-1){
	        return 0;
	    }
	    for(int i=n-1;i>=0;i--){
	        if(arr[i]==x ){
	            lastIndex=i;
	            break;
	        }
	        
	    }
	    return (lastIndex-firstIndex)+1;
    }

```
### minimum platform
```c
int compare(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}

 int findPlatform(int n,int arr[], int dep[]) {
        
        int maxPlat=1; int plat=1;
        qsort(arr,n,sizeof(int),compare);
        qsort(dep,n,sizeof(int),compare);
 
        int i=1;int j=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                plat++;
                i++;
                
            }
            else{
                plat--;
                j++;
            }
            if(plat>maxPlat){
                maxPlat=plat;
            }
        }
        return maxPlat;
    }
}
```
### peak element
```c
int peakElement(int arr[],int n)
    {
        if(n==1){
            return 0;
        }
        if(arr[0]>arr[1]){
            return 0;
        }
        else if(arr[n-1]>arr[n-2]){
            return n-1;
        }
        for(int i=1;i<n-1;i++){
            if(arr[i]>=arr[i+1] && arr[i]>=arr[i-1]){
                return i;
            }
        }
          return 0;
    }
  
```
### Find triplets with zero sum

```c
// two-pointer technique
int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}
int findTriplets(int arr[], int n)
    { 
        qsort(arr,n,sizeof(int),compare);
        for(int i=0;i<n-2;i++){
            int left=i+1;int right=n-1;
            while(left<right){
                int currentSum=arr[i]+arr[left]+arr[right];
                if(currentSum==0){
                    return 1;
                }
                else if(currentSum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return 0;
    }
```
### First and Last Occurrences
```c
void find(int arr[], int n, int x, int result[]) {
    result[0] = -1; 
    result[1] = -1; 

    // Find the first occurrence
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            result[0] = i;
            break; 
        }
    }

    // Find the last occurrence
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == x) {
            result[1] = i;
            break; 
        }
    }
}
```
### Search in a row-column sorted Matrix
```c

	int search(int row, int col, int mat[][col], int x) 
	{  

     for(int i=0;i<row;i++){
            if(mat[i][col-1]>=x && mat[i][0]<=x){
                for(int j=0;j<col;j++){
                    if(mat[i][j]==x){
                        return 1;
                    }
                }
              
            }
        }
        return 0;
	}
```
