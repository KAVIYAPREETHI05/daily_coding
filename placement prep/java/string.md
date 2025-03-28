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

