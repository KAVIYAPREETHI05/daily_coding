### check palindrome
```java
import java.util.Scanner;

public class palindrome{
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        String s1=s.nextLine();
        boolean found=true;
        int n=s1.length();

        for(int i=0;i<n/2;i++){
            if(s1.charAt(i)!=(s1.charAt(n-1-i))){
                found=false;
                break;

            }
        }
        if(found){
            System.out.print("yes it is palindrome");
        }
        else{
            System.out.print("no it is not palindrome");
        }
        s.close();
    }
}
```
### reverse word
```java
import java.util.Scanner;
public class reverse {
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        String s1=s.nextLine();

        int n=s1.length();
        StringBuilder sb=new StringBuilder(s1);


        for(int i=0;i<n/2;i++){
            char temp=sb.charAt(i);
            sb.setCharAt(i,sb.charAt(n-1-i));
            sb.setCharAt(n-1-i,temp);

        }
        System.out.print(sb.toString());
        s.close();
    }
    
}

```

### reverse words

```java
import java.util.Scanner;

public class reverseWords {
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        String s1=s.nextLine();

        int n=s1.length();
        int i=n-1;int end=n-1;

        while(i>=0){
            if(s1.charAt(i)=='.'){
                int start=i+1;
                for(int j=start;j<=end;j++){
                    System.out.print(s1.charAt(j));
                }
                System.out.print('.');
                while(i>=0 && s1.charAt(i)=='.'){
                    i--;
                }
                end=i;
            }


i--;

        }
        i=0;
        while(s1.charAt(i)!='.'){
            System.out.print(s1.charAt(i));
            i++;
        }
    }
    
}

```


### Check if Strings Are Rotations of Each Other

```java
import java.util.Scanner;
// Check if Strings Are Rotations of Each Other

public class checkSubstring {
    static boolean contains(String temp,String s2){
        int n=temp.length();
        int m=s2.length();
        if(m>n){
            return false;
        }

        for(int i=0;i<n-m;i++){
            int j=0;
            while(j<m && temp.charAt(i+j)==s2.charAt(j)){
                j++;
            }
            if(j==m){
                return true;
            }
        }

        return false;
    }
    static boolean isRotation(String s1,String s2){
        int n=s1.length();
        int m=s2.length();
        if(n!=m){
            // since we are checking rotation, s2 should contain all char from s1
            return false;
        }
        String temp=s1+s1;
        if(contains(temp,s2)){
            return true;
        }
        return false;
    }
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        String s1=s.nextLine();
        String s2=s.nextLine();

        if(isRotation(s1,s2)){
            System.out.print("true");
        }
        else{
            System.out.print("false");
        }
    }
    
}
```


### REVERSE VOWELS IN STRING

```java
import java.util.Scanner;

public class Main
{
    private static boolean isVowel(char c){
         if(c=='a' || c=='e' || c=='i' ||c=='o' ||c=='u' || c=='A' || c=='E' || c=='I' ||c=='O' ||c=='U' ){
        return true;
    }
    else{
        return false;
    }
    }
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	    String str=s.nextLine();
	     int n=str.length();
	     char[] arr=str.toCharArray();
    
    int start=0;int end=arr.length-1;
    
    while(start<end){
        if(isVowel(arr[start]) && isVowel(arr[end])){
            char temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
        else if(!isVowel(arr[start])){
            start++;
        }
        else if(!isVowel(arr[end])){
            end--;
        }
    }
    
System.out.print(new String(arr));
	}
}
```

### VALID PALINDROME

```java
import java.util.Scanner;

public class Main
{
    private static boolean isletter(char c){
        if((c>='a' && c<='z') ||(c>='A' &&c<='Z') ){
        return true;
    }
    else{
        return false;
    }
    }
	public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	    String str=s.nextLine();
	     int n=str.length();
	     char[] arr=str.toCharArray();
	     char[] temp=new char[100];
	     
	     int j=0;
    for(int i=0;i<n;i++){
        if(isletter(arr[i])){
            temp[j++]=Character.toLowerCase(arr[i]);
        }
    }


    boolean palin=true;
    for(int i=0;i<j/2;i++){
        if(temp[i]!=temp[j-1-i]){
            palin=false;
            break;
            
        }
    }
    
    if(palin){
        System.out.print("true");
        
    }
    else{
        System.out.print("false");
    }
	}
}
```
### EVEN WORDS IN STRING

```java
package file1;
import java.util.Scanner;


public class Demo {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String str=s.nextLine();
		int count =0;int end=str.length()-1;
		for(int i=str.length()-1;i>=0;i--) {
			if(str.charAt(i)!=' ') {
				count++;
			}
			else {
				if(count%2==0) {
					int start=i+1;
					while(start<=end) {
						System.out.print(str.charAt(start));
						start++;
					}
					
					end=i-1;
					count=0;
				}
			}
			
		}
		
	
		
		

	}

}
(or)

package file1;
import java.util.Scanner;


public class Demo {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String str=s.nextLine();

		String[] newStr= str.split("\\s+");
		for(int i=0;i<newStr.length;i++) {
			if(newStr[i].length() %2==0) {
				System.out.print(newStr[i]+" ");
				
			}
			
		}
		
	}
}

```
### REVERSE STRING

```java
package file1;
import java.util.Scanner;


public class Demo {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String str=s.nextLine();

		StringBuilder newStr=new StringBuilder(str);
		
		newStr.reverse();
		
		System.out.print(newStr.toString());
		
	}
}
```
### REVERSE WORDS IN STRING

```java
package file1;
import java.util.Scanner;


public class Demo {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String str=s.nextLine();

		String[] newStr= str.split("\\s+");
		for(int i=newStr.length-1;i>=0;i--) {
				System.out.print(newStr[i]+" ");
							
		}
		
	}
}
```
### CHECK PALINDROME

```java
package file1;
import java.util.Scanner;


public class Demo {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String str=s.nextLine();
		
		StringBuilder newStr=new StringBuilder(str);
		newStr.reverse();
		
		
		if(str.equalsIgnoreCase(newStr.toString())) {
			System.out.print("palindorme");
			
		}
		else {
			System.out.print("not palindrome");
		}
		
		

		
		
	}
}
```
### REPLACE LETTER IN STRING

```java
package file1;
import java.util.Scanner;


public class Demo {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String str=s.nextLine();
		
String newStr=str.replaceAll("a","z");		

System.out.print(newStr);		
		
	}
}
```
### REMOVE SPACE

```java
package file1;
import java.util.Scanner;


public class Demo {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String str=s.nextLine();
		
String newStr=str.replaceAll("\\s+","");		

System.out.print(newStr);		
		
	}
}
```
 ### CONVERT CHARACTER CASE

 ```java
package file1;
import java.util.Scanner;


public class Demo {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String str=s.nextLine();
		
		StringBuilder newStr=new StringBuilder();
		
		for(char ch: str.toCharArray()) {
			if(Character.isUpperCase(ch)) {
				newStr.append(Character.toLowerCase(ch));
				
			}
			else {
				newStr.append(Character.toUpperCase(ch));
			}
		}
		
		System.out.print(newStr);
	

		
	}
}
```
### COUNT VOWEL AND CONSONANT

```java
package file1;
import java.util.Scanner;


public class Demo {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String str=s.nextLine();
		
		StringBuilder newStr=new StringBuilder();
		int vowel=0; int consonant=0;
		
		for(char ch: str.toCharArray()) {
			if(Character.isLetter(ch)) {
				if("aeiou".indexOf(ch)!=-1) {
					//checks ch is inside aeiou
					//if yes returns its index else returns -1
					vowel++;
				}
				else {
					consonant++;
				}
				
		}
		
		
	}
		System.out.print(vowel + " "+ consonant);

}
}
```

