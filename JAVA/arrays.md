
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
### 496. Next Greater Element I
```java
class Solution {
    int nextgreater(int j,int num,int []nums2,int n2){
        for(int i=j+1;i<n2;i++){
            if(nums2[i]>num){
                return nums2[i];
            }
        }
        return -1;
    }
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n1=nums1.length;
        int n2=nums2.length;
        ArrayList<Integer>result=new ArrayList<>();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    int ans=nextgreater(j,nums2[j],nums2,n2);
                    result.add(ans);
                    break;

                    
                }
            }
        }

        return result.stream().mapToInt(i -> i).toArray();
    }
}
```
### 503. Next Greater Element II
```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        int[] res=new int[n];
        Arrays.fill(res,-1);
       Stack <Integer> s=new Stack<>();
       for(int i=0;i<2*n;i++){
        if(!s.isEmpty() && nums[s.peek()]<nums[i%n]){
            res[s.pop()]=nums[i%n];
        }
        if(i<n){
            s.push(i);
        }
       }
       return res;
    }
}
```
### 739. Daily Temperatures
```java
//time limit exceeded
class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n=temp.length;
        int[] ans=new int[n];
        for(int i=0;i<n-1;i++){
            int start=i+1;
            int count=1;
            if(temp[i]<temp[start]){
                ans[i]=1;

            }
            else{
                while(start<n){
                     if(temp[i]<temp[start]){
                        ans[i]=count;
                         break;           }
            start++;
            count++;
            
                }
            }
        }
return ans;
        
    }
}
```

optimized code

```java
import java.util.Stack;

class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n = temp.length;
        int[] ans = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && temp[i] > temp[stack.peek()]) {
                int index = stack.pop();
                ans[index] = i - index;  
            }
            stack.push(i);
        }


        return ans;
    }
}

```
### move zeros
```java
class Solution {
    void swap(int[] nums,int i,int start){
        int temp=nums[i];
        nums[i]=nums[start];
        nums[start]=temp;
    }
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        int start=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums,i,start);
                 start++;

            }
           
        }
     
    }
}
```
### valid parenthesis
```java
class Solution {
    public boolean checkValidString(String s) {
        int low = 0; 
        int high = 0; 

        for (char c : s.toCharArray()) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low = Math.max(low - 1, 0); 
                high--;
            } else if (c == '*') {
                // '*' can be '(', ')' or empty
                low = Math.max(low - 1, 0); // Treat '*' as ')' or empty
                high++; // Treat '*' as '('
            }

            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
}

```
### 482. license key formatting
```java
class Solution {
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder cleaned = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c != '-') {
                cleaned.append(Character.toUpperCase(c));
            }
        }
        
        if (cleaned.length() == 0) {
            return "";
        }

        StringBuilder result = new StringBuilder();
        int length = cleaned.length();
        
        int firstGroupLength = length % k == 0 ? k : length % k;
        result.append(cleaned.substring(0, firstGroupLength));
        
        for (int i = firstGroupLength; i < length; i += k) {
            result.append("-").append(cleaned.substring(i, Math.min(i + k, length)));
        }
        
        return result.toString();
    }
}
```
### most occurrence
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        int []temp=new int[26];
        
        for(int i=0;i<n;i++){
            char letter=Character.toLowerCase(str.charAt(i));
            if(letter>='a' && letter<='z'){
                int idx=letter-'a';
                temp[idx]++;
            }
        
            
        }
        int max=0;char maxChar=' ';
        for(int i=0;i<26;i++){
            if(temp[i]>max){
                max=temp[i];
                maxChar=(char)(i+'a');
            }
        }
        
        System.out.println(maxChar);
        
    }
}
```
### valid time or not
```java
import java.util.Scanner;

public class TimeValidator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter time (HH:mm:ss): ");
        String time = scanner.nextLine();
        
        if (isValidTime(time)) {
            System.out.println("Valid time");
        } else {
            System.out.println("Invalid time");
        }
    }

    public static boolean isValidTime(String time) {
        if (!time.matches("\\d{2}:\\d{2}:\\d{2}")) {
            return false;
        }
        
        String[] parts = time.split(":");
        int hours = Integer.parseInt(parts[0]);
        int minutes = Integer.parseInt(parts[1]);
        int seconds = Integer.parseInt(parts[2]);

        return (hours >= 0 && hours < 24) && 
               (minutes >= 0 && minutes < 60) && 
               (seconds >= 0 && seconds < 60);
    }
}

```
### verion check
```java
import java.util.Scanner;

public class VersionCompare {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter version 1: ");
        String v1 = scanner.nextLine();
        
        System.out.print("Enter version 2: ");
        String v2 = scanner.nextLine();
        
        int result = compare(v1, v2);
        if (result == 0) {
            System.out.println("Both are equal");
        } else if (result > 0) {
            System.out.println("v1 is greater than v2");
        } else {
            System.out.println("v1 is less than v2");
        }
    }

    public static int compare(String v1, String v2) {
        String[] parts1 = v1.split("\\.");
        String[] parts2 = v2.split("\\.");
        
        int length = Math.max(parts1.length, parts2.length);
        
        for (int i = 0; i < length; i++) {
            int num1 = i < parts1.length ? Integer.parseInt(parts1[i]) : 0;
            int num2 = i < parts2.length ? Integer.parseInt(parts2[i]) : 0;
            
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
        }
        
        return 0;
    }
}

```
### count words in string
```java
import java.util.Scanner;

public class WordCount {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        
        int wordCount = countWords(input);
        System.out.println("Number of words: " + wordCount);
    }

    public static int countWords(String str) {
        // Trim the string to remove leading and trailing spaces
        str = str.trim();
        
        // Check for empty string
        if (str.isEmpty()) {
            return 0;
        }
        
        // Split the string based on one or more spaces
        String[] words = str.split("\\s+");
        return words.length;
    }
}

```
### count alpha,num,spl char
```java
import java.util.Scanner;

public class CharacterCount {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        
        int alphaCount = 0;
        int digitCount = 0;
        int specialCount = 0;

        for (char c : input.toCharArray()) {
            if (Character.isLetter(c)) {
                alphaCount++;
            } else if (Character.isDigit(c)) {
                digitCount++;
            } else if (!Character.isWhitespace(c)) { // Exclude whitespace
                specialCount++;
            }
        }

        System.out.println("Number of alphabetic characters: " + alphaCount);
        System.out.println("Number of digits: " + digitCount);
        System.out.println("Number of special characters: " + specialCount);
    }
}

```
### sorting string
```java
import java.util.Arrays;
import java.util.Scanner;

public class SortString {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        
        String sortedString = sortString(input);
        System.out.println("Sorted string: " + sortedString);
    }

    public static String sortString(String str) {
        // Convert string to character array
        char[] charArray = str.toCharArray();
        
        // Sort the character array
        Arrays.sort(charArray);
        
        // Convert sorted character array back to string
        return new String(charArray);
    }
}

```

### sumof digonal matrix

```java
import java.util.Scanner;
public class Main
{
    public static void sumDiagonal(int[][] matrix){
        int row=matrix.length;
        int col=matrix[0].length;
        int sum=0;int inverse=0;
        for(int i=0;i<row;i++){
                    sum+=matrix[i][i];
                    inverse+=matrix[i][row-1-i];
                
            
        }
        System.out.print(sum + " "+ inverse);
    }
	public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
	    int[][] matrix={{1,2,3},{4,3,2},{2,5,7}};
	    sumDiagonal(matrix);
	}
}
```
