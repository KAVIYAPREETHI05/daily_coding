### second largest
```java
int secondLargest(int n,int []arr){
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
```
### transition point
the first index where 1 was observed, and before that, only 0 was observed.
```java
class Solution {
    int transitionPoint(int arr[], int n) {
        for(int i=n-1;i>=0;i--){
            if(arr[i]==1 && (i==0||arr[i-1]==0 )){
                return i;
            }
        }
        return -1;
    }
}
```
### floor in sorted array
```java
class Solution {

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
}

```
### Find Pair Given Difference

```java
class Solution {
    public int findPair(int n, int x, int[] arr) {
        Arrays.sort(arr);
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
```java
class Solution {
    long floorSqrt(long n) {
        
        long num=(long)Math.sqrt(n);
        return num;
    }
}
```
### Find Kth Rotation

```java
class Solution {
    public int findKRotation(List<Integer> arr) {
        int index=0; int n=arr.size();
        int min=arr.get(0);
        for(int i=0;i<n;i++){
            if(arr.get(i)<min){
                min=arr.get(i);
                index=i;
            }
           
        }
        return index;
    }
}
```
