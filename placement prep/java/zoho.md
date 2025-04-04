
### 28.1 NUMBER OF ISLANDS

### 28.2 LONGEST PALINDROME

i/p babad
o/p bab

```java
import java.util.Scanner;

 class longestPalindrome{

    static boolean  isPalin(String str){
        int m=str.length();
        for(int i=0;i<m/2;i++){
            if(str.charAt(i)!=str.charAt(m-i-1)){
                return false;
            }
        }
        return true;
    }

   static  String longestPalin(String str){
        int n=str.length();
        String longest="";

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                String substring=str.substring(i,j+1);
                if(isPalin(substring) && substring.length()> longest.length()){
                    longest=substring;
                }
            }

        }
        return longest;
    }
    
public static void main(String[] args){
    Scanner s=new Scanner(System.in);
    String str=s.nextLine();

    System.out.println(longestPalin(str));


}
}
```
### 28.3 COUNT PAIRS OF STRINGS

```java
package file1;

import java.util.Scanner;
import java.util.HashMap;

class pairCount{
	static int countPairs(int n,String[] str1) {
		String[] str2unique=new String[n]; int a=0;
		
		for(int i=0;i<n;i++) {
			String str=str1[i];
			int[] temp=new int[26];
			for(int j=0;j<str.length();j++) {
				temp[str.charAt(j)-'a']++;
			}
			
			StringBuilder sb=new StringBuilder();
			
			for(int k=0;k<26;k++) {
				if(temp[k]!=0) {
					sb.append((char)(k+'a'));
					temp[k]=0;
					
				}
			}
			str2unique[a++]=sb.toString();
			
		}
		for(int i=0;i<n;i++) {
			System.out.print(str2unique[i]+" ");
		}
		int pairs=0;
		for(int i=0;i<n;i++) {
			int count=1;
			for(int j=i+1;j<n;j++) {
				if(!str2unique[i].equals("0") && str2unique[i].equals(str2unique[j])) {
					count++;
					str2unique[j]="0";
					
				}
			}
			pairs+= (count*(count-1))/2;
			
		}
		return pairs;
	}
    
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        s.nextLine();
        String[] str=new String[n];

        for(int i=0;i<n;i++) {
        	str[i]=s.nextLine();
        }
        
        System.out.print(countPairs(n,str));


    }
}

```
### 29.1 FIND PIVOT INDEX

```java
package file1;

import java.util.Scanner;
import java.util.HashMap;

class pivotIndex{
	static int findPivot(int n,int[] arr) {
		int totalsum=0;int leftsum=0;
		
		for(int i=0;i<n;i++) {
			totalsum+=arr[i];
		}
		
		for(int i=0;i<n;i++) {
			if(leftsum== totalsum-leftsum-arr[i]) {
				return i;
			}
			leftsum+=arr[i];
			
		}
		return -1;
		
	}	
    
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int[] arr=new int[n];

        for(int i=0;i<n;i++) {
        	arr[i]=s.nextInt();
        }
        
        System.out.print(findPivot(n,arr));


    }
}
```
### 29.2 GROUP ANAGRAM


### 29.3 CLIMBING STAIRS

```java
class Solution {
    int findways(int n){
        if(n<=2){
            return n;
        }
       int first=1;int second=2;
       int[] arr=new int[n];int third=0;
       for(int i=3;i<=n;i++){
       third=first+second;
        first=second;
        second=third;

       }
       return third;
    }
    public int climbStairs(int n) {
        return findways(n);
        
    }
}
```

### 30.1 MAXIMUM PRODUCT SUBARRAY

```java
package file1;

import java.util.Scanner;


class subarray{
	static int productSubarray(int n,int[] arr) {
		int maxproduct=arr[0]; int minproduct=arr[0]; int result=arr[0];
		
		for(int i=1;i<n;i++) {
 if (arr[i] < 0) {
                int temp = maxproduct;
                maxproduct = minproduct;
                minproduct = temp;
            }
			
			maxproduct=Math.max(arr[i], maxproduct*arr[i]);
			minproduct=Math.min(arr[i], minproduct*arr[i]);
			
			result=Math.max(maxproduct, result);
			
		}
		
		return result;
		
	}
	
	
    
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int[] arr=new int[n];

        for(int i=0;i<n;i++) {
        	arr[i]=s.nextInt();
        }
        
        System.out.print(productSubarray(n,arr));


    }
}
```

### 30.2 MOVE ZEROS TO END

```java
package file1;

import java.util.Scanner;


class moveZerosToEnd{
	static void moveZeros(int n,int[] arr) {
		int j=0;
		
		for(int i=0;i<n;i++) {
			if(arr[i]!=0) {
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				j++;
			}
			
		}
		
		for(int i=0;i<n;i++) {
			System.out.print(arr[i]+" ");
		}
		
	}	
    
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int[] arr=new int[n];

        for(int i=0;i<n;i++) {
        	arr[i]=s.nextInt();
        }        
        moveZeros(n,arr);
    }
}

```

### 30.3 SPIRAL MATRIX

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
                ArrayList<Integer> arr=new ArrayList<>();

         if (matrix == null || matrix.length == 0) {
            return arr;
        }

        int n=matrix.length;
        int m=matrix[0].length;
        int left=0;int right=m-1;int top=0;int bottom=n-1;int j=0;

        while(left<=right && top<=bottom){
            for(j=left;j<=right;j++){
            arr.add(matrix[top][j]);

        }
        top++;

        for(j=top;j<=bottom;j++){
            arr.add(matrix[j][right]);
        }
        right--;

        if(top<=bottom){
            for(j=right;j>=left;j--){
            arr.add(matrix[bottom][j]);
        }
        bottom--;
        }

       if(left<=right){
         for(j=bottom;j>=top;j--){
            arr.add(matrix[j][left]);
        }
        left++;
       }
        }
        return arr;
        
    }
}
```

### 31.1

### 31.2

### 31.3 NEXT GREATER

```java
package file1;

import java.util.Scanner;


class romanInteger{
	static void nextGreater(int n,int[] arr) {

		for(int i=0;i<n-1;i++) {
			int max=arr[i+1];
			for(int j=i+1;j<n;j++) {
				if(arr[j]>max) {
					max=arr[j];
				}				
			}			
			arr[i]=max;
					}
		arr[n-1]=-1;
				for(int i=0;i<n;i++) {
			System.out.print(arr[i]+" ");
		}
			
	}	    
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int[] arr=new int[n];

        for(int i=0;i<n;i++) {
        	arr[i]=s.nextInt();
        }        
        nextGreater(n,arr);
    }
}

```


### 1.1 ROMAN TO INTEGER

```java
package file1;

import java.util.Scanner;
import java.util.HashMap;

class romanInteger{
    static int romanToInteger(String str){
        int n=str.length(); int sum=0;
        HashMap<Character,Integer> map=new HashMap<>();
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);

        for(int i=0;i<n;i++){
            sum+=map.get(str.charAt(i));
        }

        return sum;
    }
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        String str=s.nextLine();

        System.out.print(romanToInteger(str));


    }
}
```

### 1.2 EQUILIBRIUM POINT

same as pivot point

### 1.3 LONGEST COMMON SUBSEQUENCE

### string

### PATTERN PRINTING

```

1            1             1
    2        2        2
        3    3    3
1   2   3    4    5   6    7
        5    5    5
    6	     6        6
7            7             7
```
