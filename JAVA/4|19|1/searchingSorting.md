### count invertions
```java
//time limit exceeded
class Solution {
   
    static long inversionCount(long arr[]) {
        int n=arr.length;
        long count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j] && i<j){
                    count++;
                }
            }
        }
        return count;
    }
}
//tracking changes in rank,stock market
```
### Search in Rotated Sorted Array
```java
class Solution {
    public int search(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
           if(arr[mid]==target){
               return mid;
           }
           if(arr[left]<=arr[mid]){
               if(arr[left]<=target && target<arr[mid]){
                   right=mid-1;
               }
               else{
                   left=mid+1;
               }
               
           }
           else{
               if(arr[mid]<target && target<=arr[right]){
                   left=mid+1;
               }
               else{
                   right=mid-1;
               }
               
           }
        }
        return -1;
    }
}
```
### Kth Smallest
```java
class Solution {
    public static int kthSmallest(int[] arr, int k) {
        // Your code here
        Arrays.sort(arr);
        return arr[k-1];
    }
}
```
### binary search
```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums==null || nums.length==0){
            return 0;
        }
        int left=0;int right=nums.length-1;
        while(left<=right){
                    int mid=left+(right-left)/2;

            if(nums[mid]==target){
                return mid;
            }
            if(target<nums[mid]){
                right=mid-1;
            }
            else if(target>nums[mid]){
                left=mid+1;
            }
        }
        return -1;
        
    }
}
```
### peak element
```java
class Solution {
    public int findPeakElement(int[] arr) {
        int n = arr.length;

        if (n == 1) {
            return 0;
        }

        if (arr[0] > arr[1]) {
            return 0;
        }

        if (arr[n - 1] > arr[n - 2]) {
            return n - 1;
        }

        // Check the middle elements
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                return i; 
            }
        }

        return -1; 
}

```
