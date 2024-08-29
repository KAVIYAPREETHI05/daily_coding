### Find the largest three distinct elements in an array
The idea is to keep track of the largest three distinct element while traversing the array. If an element is greater than the first largest element, we update the first largest as well as the second largest and also third.

Else if an element is larger than second largest but smaller than first largest, then we update the second largest as well as third largest. 

Else if an element is larger than third largest but smaller than first smaller than second largest then we update third only.

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
