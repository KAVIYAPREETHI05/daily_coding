
### move all zero's to end
Traverse through the array if the element is not equal to 0, add them along in the track of array of j(non-element).

It moves all non-zero elements to the beginning of the array and pushes the zeros to the end.

```java
import java.util.*;
class Sample
{
	public static void main(String[] args){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		
		if(n<2){
			return;
		}
		int arr[]=new int[n];
		for(int i=0;i<n;i++){
			 arr[i]=s.nextInt();
		}int j=0;
		for(int i=0;i<n;i++){
			if(arr[i]!=0){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				j++;
			}
		}
		for(int i=0;i<n;i++){
			System.out.println(arr[i]);
		}
		
		
	}
}
```
### Rearrange array such that even positioned are greater than odd
```java
import java.util.*;
class Sample
{
	public static void main(String[] args){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		
		if(n<2){
			return;
		}
		int arr[]=new int[n];
		for(int i=0;i<n;i++){
			 arr[i]=s.nextInt();
		}
		for(int i=1;i<n;i+=2){
			if(arr[i]<arr[i-1]){
				int temp=arr[i];
				arr[i]=arr[i-1];
				arr[i-1]=temp;
				
			}
			else if(i+1<n && arr[i]<arr[i+1]){
				int temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
		for(int i=0;i<n;i++){
			System.out.println(arr[i]);
		}
		
		
	}
}
```
### segregate even and odd elements
```java
import java.util.*;
class Sample
{
	public static void main(String[] args){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		
		if(n<2){
			return;
		}
		int arr[]=new int[n];
		int result[]=new int[n];
		for(int i=0;i<n;i++){
			 arr[i]=s.nextInt();
		}int j=0;
		for(int i=0;i<n;i++){
			if(arr[i]%2==0){
				result[j++]=arr[i];
			}
		}
		for(int i=0;i<n;i++){
			if(arr[i]%2!=0){
				result[j++]=arr[i];
			}
		}
		for(j=0;j<n	;j++){
			System.out.println(result[j]);
		}
		
		s.close();
	}
}
```
### array leaders
```java

class Solution {
   
    static ArrayList<Integer> leaders(int n, int arr[]) {
        
        ArrayList<Integer>temp=new ArrayList<>();
        int last=arr[n-1];
        temp.add(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=last){
                last=arr[i];
                temp.add(arr[i]);
            }
        }
        Collections.reverse(temp);
        return temp;
    }
}
```
### Equilibrium Point
```java
class Solution {
    public static int equilibriumPoint(long arr[]) {
        int n=arr.length;
        if(n==1){
            return 1;
        }
        int total=0;
       for(int i=0;i<n;i++){
           total+=arr[i];
       }
       int leftsum=0;
       for(int i=0;i<n;i++){
           if(leftsum==total-leftsum-arr[i]){
               return i+1;
           }
           leftsum+=arr[i];
           
       }
       return -1;
    }
}
```
### Sort 0s, 1s and 2s or Dutch National Flag
```java
//User function template for Java

    class Solution
    {
        public static void sort012(int a[], int n)
        {
            // code here 
            Arrays.sort(a);
        }
    }
```
or
```java
// using arraylist
import java.util.ArrayList;
import java.util.Collections;

class Solution {

    // Function to swap elements in the ArrayList
    public void swap(ArrayList<Integer> arr, int i, int j) {
        int temp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, temp);
    }

    // Function to sort the array of 0, 1, and 2
    public void sort012(ArrayList<Integer> arr) {
        int low = 0, mid = 0, high = arr.size() - 1;

        // Dutch National Flag algorithm
        while (mid <= high) {
            switch (arr.get(mid)) {
                case 0:
                    swap(arr, low, mid);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(arr, mid, high);
                    high--;
                    break;
            }
        }
    }
}

```
### Convert array into Zig-Zag fashion
- For even indices: The element should be less than the next element.
- For odd indices: The element should be greater than the next element.

```java
class Solution {
    static void swap(int[]arr,int num1,int num2){
        int temp=arr[num1];
        arr[num2]=arr[num1];
        arr[num1]=temp;
    }
    public static void zigZag(int n, int[] arr) {
        // code here
        for(int i=0;i<n-1;i++){
            if(i%2==0){
                if(arr[i]>arr[i+1]){
                    swap(arr,i,i+1);
                }
                
            }
            if(i%2!=0){
                if(arr[i]<arr[i+1]){
                    swap(arr,i,i+1);
                }
                
            }
        }
    }
}
//pattern generating
```
### Rearrange Array Alternately
```java
// data shuffling,tabluar col ui
public static void rearrange(long arr[], int n){
        
       long[]temp=new long[n];
       int evenidx=0;int oddidx=1;
       int start=0;int end=n-1;
       while(start<=end){
           if(evenidx<n){
               temp[evenidx]=arr[end--];
               evenidx+=2;
               }
           if(oddidx<n){
               temp[oddidx]=arr[start++];
               oddidx+=2;
                }
      
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
    
}
}
```
### Missing in Array
```java
class Solution {

    // Note that the size of the array is n-1
    int missingNumber(int n, int arr[]) {
int arr_total=0;
int len=arr.length;
        for(int i=0;i<len;i++){
            arr_total+=arr[i];
        }
        int actual_sum=n*(n+1)/2;
        return actual_sum-arr_total;
    }
}
```
### K-th element of two Arrays
```java
class Solution {
    public long kthElement(int k, int arr1[], int arr2[]) {
        // code here
        int n=arr1.length;
        int m=arr2.length;
        int[]temp=new int[n+m];
        int i=0;int j=0;int idx=0;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                temp[idx++]=arr1[i++];
            }
            else{
                temp[idx++]=arr2[j++];
            }
            
        }
        while(i<n){
              temp[idx++]=arr1[i++];
            
        }
        while(j<m){
             temp[idx++]=arr2[j++];
        }
        for(int a=0;a<=idx;a++){
            if(k==(a+1)){
                return temp[k-1];
            }
        }
        return -1;
}
}
// ranking system
```
### Check Equal Arrays
```java
// time limit exceeded
class Solution {
    // Function to check if two arrays are equal or not.
    public static boolean check(int[] arr1, int[] arr2) {
        // Your code here
        int n=arr1.length;
        int m=arr2.length;
        int [] temp=new int[10000000];
        for(int i=0;i<n;i++){
            temp[arr1[i]]++;
        }
        for(int j=0;j<m;j++){
            temp[arr2[j]]--;
        }
        for(int i=0;i<10000000;i++){
            if(temp[i]!=0){
                return false;
            }
        }
        return true;
    }
}
```
```java

class Solution {
    // Function to check if two arrays are equal or not.
    public static boolean check(int[] arr1, int[] arr2) {
        // Your code here
        int n=arr1.length;
        int m=arr2.length;
        if(n!=m){
            return false;
        }
       Arrays.sort(arr1);
       Arrays.sort(arr2);
       for(int i=0;i<n;i++){
           if(arr1[i]!=arr2[i]){
               return false;
           }
       }
        return true;
    }
}
```
```java
//using hashmap

class Solution {
    // Function to check if two arrays are equal or not.
    public static boolean check(int[] arr1, int[] arr2) {
        if(arr1.length!=arr2.length){
            return false;
        }
        HashMap<Integer,Integer>temp=new HashMap<>();
        for(int i=0;i<arr1.length;i++){
            int num=arr1[i];
            if(temp.containsKey(num)){
                temp.put(num,temp.get(num)+1);
            }
            else{
                 temp.put(num,1);
            }
        }
        for(int i=0;i<arr2.length;i++){
            int num=arr2[i];
            if(!temp.containsKey(num)){
                return false;
            }
            temp.put(num,temp.get(num)-1);
            if(temp.get(num)==0){
                temp.remove(num);
            }
        }
        return temp.isEmpty();
    }
}

```
### Kadane's Algorithm
```java
class Solution {
 int maxSubarraySum(int[] arr) {
        int n=arr.length;
        int max_sum=Integer.MIN_VALUE;
         int  curr_sum=0;
        for(int i=0;i<n;i++){
          
                curr_sum+=arr[i];
                if(curr_sum>max_sum){
                    max_sum=curr_sum;
                }
                 if (curr_sum < 0) {
                curr_sum = 0;
            }//-79 -68 -18 -58 25 52 -68 -30 6 10
            
            
        }
        return max_sum;
    }
}
//stock price and temperature analysis
```
### Indexes of Subarray Sum(sliding window approach)
```java
class Solution {
    public static ArrayList<Integer> subarraySum(int[] arr, int n, int s) {
        ArrayList<Integer>temp=new ArrayList<>();
        int arr_sum=0;int start=0;int i;
        for( i=0;i<n;i++){
            arr_sum+=arr[i];
            while(arr_sum>s && start<i){
            arr_sum-=arr[start];
            start++;
          
        }
        if(arr_sum==s){
            temp.add(start+1);
            temp.add(i+1);
            return temp;
        }
       
        }
        
         
            temp.add(-1);
        
        
        return temp;
    }
//transaction fraud detection
```
### Trapping Rain Water
```java
class Solution {

    
    static long trappingWater(int arr[]) {
        int n = arr.length;
        if (n <= 2) {
            return 0;  
        }
int left=0;int right=n-1;
int left_max=0;int right_max=0;
long totalwater=0;
while(left<=right){
    if(arr[left]<=arr[right]){
        if(arr[left]>=left_max){
            left_max=arr[left];
        }
        else{
            totalwater+=left_max-arr[left];
        }
        left++;
    }
    else{
        if(arr[right]>=right_max){
            right_max=arr[right];
        }
        else{
            totalwater+=right_max-arr[right];
        }
        right--;
    }
}
return totalwater;
}
}
```
### Minimum Platforms
```java

class Solution {
    
    static int findPlatform(int arr[], int dep[]) {
        int n=arr.length;
        Arrays.sort(arr);
        Arrays.sort(dep);
        int platform=1,maxplat=1, i=1,j =0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                platform++;
                i++;
            }
               
                else{
                    platform--;
                    j++;
                }
                maxplat=Math.max(maxplat,platform);
            
        }
        return maxplat;
    }
}
```
### Best time to buy and sell
```java

class Solution {
    // Function to find the days of buying and selling stock for max profit.
    ArrayList<ArrayList<Integer>> stockBuySell(int arr[], int n) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        
        int i = 0;
        while (i < n - 1) {
            while ((i < n - 1) && (arr[i + 1] <= arr[i])) {
                i++;
            }
            
            if (i == n - 1) {
                break;
            }
            
            int buy = i++;
            
            while ((i < n) && (arr[i] >= arr[i - 1])) {
                i++;
            }
            
            int sell = i - 1;
            ArrayList<Integer> transaction = new ArrayList<>();
            transaction.add(buy);
            transaction.add(sell);
            result.add(transaction);
        }
        
        return result;
    }
}
```
### Largest Number formed from an Array
```java

class Solution {
    String printLargest(int n, String[] arr) {
        StringBuilder temp=new StringBuilder();
        Arrays.sort(arr,new Comparator<String>(){
            public int compare(String a,String b){
                String order1=a+b;
                String order2=b+a;
                return order2.compareTo(order1);
            }
        });
        if(arr[0].equals("0")){
            return "0";
        }
        for(int i=0;i<arr.length;i++){
            temp.append(arr[i]);
        }
        return temp.toString();
        
    }
}
```
### Largest subarray with 0 sum
```java
// time limit exceeded
class GfG {
    int maxLen(int arr[], int n) {
        int maxLen = 0; // Initialize the maximum length of subarray
        
        // Loop to traverse all subarrays
        for (int i = 0; i < n; i++) {
            int sum = 0; // Initialize sum for current subarray
            
            // Check every subarray starting from i
            for (int j = i; j < n; j++) {
                sum += arr[j]; // Add current element to sum
                
                // If the sum is zero, update maxLen
                if (sum == 0) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen; // Return the maximum length found
    }
}

```
or
```java
class GfG {
    int maxLen(int arr[], int n) {
        // HashMap to store sum of elements so far
        HashMap<Integer, Integer> sumMap = new HashMap<>();
        
        int sum = 0; // Initialize the sum of elements
        int maxLen = 0; // Initialize the max length of subarray
        
        // Traverse through the given array
        for (int i = 0; i < n; i++) {
            sum += arr[i]; // Add current element to sum
            
            // If the sum is zero, update maxLen to i + 1
            if (sum == 0) {
                maxLen = i + 1;
            }
            
            // If this sum has been seen before, a subarray with zero sum exists
            if (sumMap.containsKey(sum)) {
                // Update maxLen if we find a longer subarray
                maxLen = Math.max(maxLen, i - sumMap.get(sum));
            } else {
                // Store sum with the index if it's not already present
                sumMap.put(sum, i);
            }
        }
        
        return maxLen; // Return the maximum length found
    }
}
```
### Swapping pairs make sum equal

```java
import java.util.HashSet;

class Solution {
    long findSwapValues(long a[], int n, long b[], int m) {
        long sumA = 0, sumB = 0;
        
        // Calculate the sum of elements in array a[] and b[]
        for (int i = 0; i < n; i++) {
            sumA += a[i];
        }
        for (int i = 0; i < m; i++) {
            sumB += b[i];
        }
        
        // If the difference between the sums is odd, return -1
        long diff = sumB - sumA;
        if (diff % 2 != 0) {
            return -1;
        }
        
        // Calculate the target difference
        long target = diff / 2;
        
        // Store elements of array b[] in a set for fast lookup
        HashSet<Long> setB = new HashSet<>();
        for (int i = 0; i < m; i++) {
            setB.add(b[i]);
        }
        
        // Try to find a pair (x, y) such that y - x = target
        for (int i = 0; i < n; i++) {
            long x = a[i];
            long y = x + target;
            if (setB.contains(y)) {
                return 1; // Pair found
            }
        }
        
        return -1; // No pair found
    }
}

```
## part II
### min and max in array

```java
class Solution {
    public Pair<Long, Long> getMinMax(int[] arr) {
        int n=arr.length;
        Arrays.sort(arr);
        long min=arr[0];
        long max=arr[n-1];
        return new Pair<>(min,max);
        
    }
}
```
### reverse array
```java
class Solution {
    public void reverseArray(int arr[]) {
        int n=arr.length;
        List<Integer> temp=new ArrayList<>();
        for(int i=0;i<n;i++){
            temp.add(arr[i]);
        }
        Collections.reverse(temp);
        for(int i=0;i<temp.size();i++){
           arr[i]=temp.get(i); 
        }
        
    }
}
```
### rotate array by 1
```java
class Solution {
    public void rotate(int[] arr) {
        int n=arr.length;
        int temp=arr[n-1];
        for(int i=n-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
    }
}
```
### array duplicates
```java
class Solution {
    public static ArrayList<Integer> duplicates(int[] arr) {
        int n=arr.length;
        ArrayList<Integer> temp=new ArrayList<>();
        HashSet<Integer> unique=new HashSet<>();
        for(int i=0;i<n;i++){
            if(unique.contains(arr[i]) && !temp.contains(arr[i])){
                temp.add(arr[i]);
            }
            else{
                unique.add(arr[i]);
            }
        }
        Collections.sort(temp);
        if(temp.isEmpty()){
            temp.add(-1);
        }
        return temp;
    }
}
```
(or)
```java



class Solution {
    public static ArrayList<Integer> duplicates(int[] arr) {
    
        int n=arr.length;
        ArrayList<Integer> result=new ArrayList<>();
       
           int maxValue = Arrays.stream(arr).max().orElse(0);
            int[] temparr=new int[maxValue+1];
       for(int i=0;i<=maxValue;i++){
           temparr[i]=0;
       }
        for(int i=0;i<n;i++){
            temparr[arr[i]]++;
        }
        for(int i=0;i<=maxValue;i++){
            if(temparr[i]>1){
                result.add(i);
                
            }
        }
        if(result.isEmpty()){
            result.add(-1);
        }
        return result;
    }



    }
```
### count occurence
```java
class Main
{
    // Returns number of times x occurs in arr[0..n-1]
    static int countOccurrences(int arr[], int n, int x)
    {
        int res = 0;
        for (int i=0; i<n; i++)
            if (x == arr[i])
              res++;
        return res;
    }
    
    public static void main(String args[])
    {
        int arr[] = {1, 2, 2, 2, 2, 3, 4, 7 ,8 ,8 };
        int n = arr.length;
        int x = 2;
        System.out.println(countOccurrences(arr, n, x));
    }
}
```
### sort 0's 1's 2's
```java


class Solution {
  
    public void sort012(ArrayList<Integer> arr) {
    int n=arr.size();
    int start=0;int end=n-1;int mid=0;
    while(mid<=end){
        if(arr.get(mid)==0){
            Collections.swap(arr,start,mid);
            start++;
            mid++;
            
        }
        else if(arr.get(mid)==1){
            
            mid++;
        }
        else if(arr.get(mid)==2){
             Collections.swap(arr,end,mid);
                end--;
            
        }
    }
    }
}
```
### move all negative to one side
```java
class Solution {
    public void segregateElements(int[] arr) {
        int n=arr.length;
        int []temp=new int[n];
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
    }
}
```


