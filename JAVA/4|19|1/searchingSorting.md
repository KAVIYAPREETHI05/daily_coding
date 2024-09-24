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
### 378. Kth Smallest Element in a Sorted Matrix
```java
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n=matrix.length;
        int m=matrix[0].length;
        int [] arr=new int[n*m];
        int l=0;
        arr= Arrays.stream(matrix).flatMapToInt(Arrays::stream).toArray();
        Arrays.sort(arr);
        return arr[k-1];

}
}
```
### 153. Find Minimum in Rotated Sorted Array
```java
class Solution {
    public int findMin(int[] nums) {
        int n=nums.length;
        int min=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            if(nums[i]<min){
                min=nums[i];
            }
        }
        return min;
    }

}
```
### 278. First Bad Version

```java
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left=1;int right=n;
        while(left<right){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)){
                right=mid;
            }
            else {
                left=mid+1;

            }
           
        }
        return left;
    }
}
```
### 74. Search a 2D Matrix
```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n=matrix.length;
        int m=matrix[0].length;
        for(int i=0;i<n;i++){
           if(target<=matrix[i][m-1]){
             for(int j=0;j<m;j++){
                if(target==matrix[i][j]){
                    return true;
                }
                

            }

           }
        }
        return false;
    }
}
```

