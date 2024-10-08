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
### search in matrix
```java
class Sol
{
    public static int matSearch(int mat[][], int row, int col, int x)
    {
        for(int i=0;i<row;i++){
            if(mat[i][col-1]>=x){
                for(int j=0;j<col;j++){
                    if(mat[i][j]==x){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
}
```

### bitonic point
first strictly increasing and then maybe strictly decreasing, find the maximum element in the array.
```java

class Solution {
    int findMaximum(int[] arr, int n) {
        int max=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }
}
```
### search in rotated sorted array
```java
class Solution {
    int search(int[] arr, int key) {
        int n=arr.length;
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
}
```
### majority element
A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.
```java
class Solution {
    static int majorityElement(int arr[]) {
        int n=arr.length;
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
}
```
### kth smallest
```java

class Solution {
    public static int kthSmallest(int[] arr, int k) {
        Arrays.sort(arr);
        return arr[k-1];
    }
}

```
### Number of occurrence

```java
//time limit exceeded
class Solution {
    int count(int[] arr, int n, int x) {
	    int count=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]==x && arr[i]<=x){
	            count++;
	        }
	    }
	    return count;
    }
}
```
or
```java
class Solution {
    int count(int[] arr, int n, int x) {
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
}
```
### minimum platform
```java
class Solution {
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    static int findPlatform(int arr[], int dep[]) {
        
        int maxPlat=1; int plat=1;
        int n=arr.length;
       
        Arrays.sort(arr);
        Arrays.sort(dep);
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
            maxPlat=Math.max(plat,maxPlat);
        }
        return maxPlat;
    }
}
```
### peak element
```java
class Solution
{

	public int peakElement(int[] arr,int n)
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
  
    }
```
### Find triplets with zero sum

```java
//two-pointer technique
class Solution
{

	public boolean findTriplets(int arr[] , int n)
    {
        Arrays.sort(arr);
        for(int i=0;i<n-2;i++){
            int left=i+1;int right=n-1;
            while(left<right){
                int currentSum=arr[i]+arr[left]+arr[right];
                if(currentSum==0){
                    return true;
                }
                else if(currentSum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return false;
    }
}
```
### First and Last Occurrences
```java
class GFG
{
    ArrayList<Integer> find(int arr[], int n, int x)
    {
        ArrayList<Integer> temp=new ArrayList<>();
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                temp.add(i);
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==x){
                temp.add(i);
                break;
            }
        }
        if(temp.isEmpty()){
            temp.add(-1);
            temp.add(-1);
        }
        return temp;
    }
}
```
### Search in a row-column sorted Matrix
```java
class Solution 
{ 
    //Function to search a given number in row-column sorted matrix.
	static boolean search(int mat[][], int row, int col, int x) 
	{  

     for(int i=0;i<row;i++){
            if(mat[i][col-1]>=x && mat[i][0]<=x){
                for(int j=0;j<col;j++){
                    if(mat[i][j]==x){
                        return true;
                    }
                }
              
            }
        }
        return false;
    
}
	}
```



