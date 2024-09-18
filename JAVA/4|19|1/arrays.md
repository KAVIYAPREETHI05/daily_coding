
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
