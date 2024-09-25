
## searching
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

## sorting
### quick sort
```java
class Solution
{
    //Function to sort an array using quick sort algorithm.
    static void quickSort(int arr[], int low, int high)
    {
       if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
       }
        
    }
    static int partition(int arr[], int low, int high)
    {
    int pivot=arr[high];
    int pi=low-1;
    for(int i=low;i<high;i++){
        if(arr[i]<pivot){
            swap(arr,i,++pi);
        }
    }
    swap(arr,++pi,high);
     return pi;
    } 
    static void swap(int [] arr,int a,int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
   
}
```
### merge sort
```java
class Solution
{
    void merge(int nums[], int left, int mid, int right)
    {
        List<Integer>temp=new ArrayList<>();
        
         int l=left;int r=mid+1;
         while(l<=mid && r<=right){
             if(nums[l]<nums[r]){
                 temp.add(nums[l++]);
                 
             }
             else{
                 temp.add(nums[r++]);
             }
         }
         while(l<=mid){
             temp.add(nums[l++]);
         }
         while(r<=right){
             temp.add(nums[r++]);
         }
         for(int i=left;i<=right;i++){
             nums[i]=temp.get(i-left);
         }
    }
    void mergeSort(int arr[], int left, int right)
    {
        if(left<right){
            int mid=(left+right)/2;
            mergeSort(arr,left,mid);
            mergeSort(arr,mid+1,right);
            merge(arr,left,mid,right);
        }
    }
}
```
### Merge Without Extra Space
```java
class Solution
{
    //Function to merge the arrays.
    public static void merge(long arr1[], long arr2[], int n, int m) 
    {
        int i=n-1;int j=0;
        while(i>=0 && j<m){
            if(arr1[i]>arr2[j]){
                long temp=arr1[i];
                arr1[i]=arr2[j];
                arr2[j]=temp;
            }
            i--;j++;
        }
        Arrays.sort(arr1);
        Arrays.sort(arr2);
    }
}
```
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
### Sorting Elements of an Array by Frequency
```java
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
   static void findFreq(int n,int[]arr){
       Map<Integer,Integer>temp=new HashMap<>();
       for(int i=0;i<n;i++){
           temp.put(arr[i],temp.getOrDefault(arr[i],0)+1);
       }
       List<Integer> nums=new ArrayList<>();
       for(int i=0;i<n;i++){
           nums.add(arr[i]);
       }
       
       Comparator<Integer> comp=new Comparator<Integer>(){
           public int compare(Integer a,Integer b){
               int freqA=temp.get(a);
               int freqB=temp.get(b);
               if(freqA==freqB){
                   return Integer.compare(a,b);
               }
               else{
                   return Integer.compare(freqB,freqA);
               }
           }
       };
       Collections.sort(nums,comp);
       for(int i=0;i<n;i++){
           System.out.print(nums.get(i)+" ");
       }
       System.out.println();
    }
	public static void main (String[] args) {
	    Scanner scan=new Scanner(System.in);
	    int t=scan.nextInt();
	    while(t-->0){
	        int n=scan.nextInt();
	        int []arr=new int[n];
	        for(int i=0;i<n;i++){
	            arr[i]=scan.nextInt();
	        }
	        findFreq(n,arr);
	    }
		
	}
}
```
### Sum of Middle elements of two sorted arrays
```java
class Solution {
    public int SumofMiddleElements(int[] arr1, int[] arr2) {
        // code here
        int i=0;int j=0;
        int n=arr1.length;int m=arr2.length;
        ArrayList<Integer>temp=new ArrayList<>();
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                temp.add(arr1[i]);
                i++;
            }
            else{
                temp.add(arr2[j]);
                j++;
            }
            
        }
        while(i<n){
            temp.add(arr1[i]);
            i++;
        }
        while(j<m){
            temp.add(arr2[j]);
            j++;
        }
        int left=0;int right=temp.size()-1;
        int mid=(left+right)/2;
        
        return temp.get(mid)+temp.get(mid+1);
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

