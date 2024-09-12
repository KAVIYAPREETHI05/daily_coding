
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


