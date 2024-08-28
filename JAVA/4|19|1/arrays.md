### Find the largest three distinct elements in an array
```java
import java.util.*;
class Sample
{
	public static void main(String[] args){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		int arr[]=new int[n];
		
		for(int i=0;i<n;i++){
			 arr[i]=s.nextInt();
		}
		int first=arr[0]; int second =Integer.MIN_VALUE; int third =Integer.MIN_VALUE;
		for(int i=1;i<n;i++){
			if(arr[i]>first){
				third=second;
				second=first;
				first=arr[i];
			}
			else if(arr[i]>second && arr[i]<first ){
				third=second;
				second=arr[i];
			}
			else if(arr[i]>third && arr[i]<second){
				third=arr[i];
			}
			
		}
		System.out.println(first + ".." + second +".." + third);
	}
}
```
### second largest
The idea is to keep track of the largest and second largest element while traversing the array. If an element is greater than the largest element, we update the largest as well as the second largest.
Else if an element is smaller than largest but greater than second largest, then we update the second largest only.

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
		int first=arr[0]; int second =Integer.MIN_VALUE; 
		for(int i=1;i<n;i++){
			if(arr[i]>first){
				second=first;
				first=arr[i];
			}
			else if(arr[i]>second && arr[i]<first ){
				second=arr[i];
			}
			
			
		}
		if(second==Integer.MIN_VALUE){
			System.out.println("second element does not exit");
		}
		else {
			System.out.println( second );
		}
		
	}
}
```
