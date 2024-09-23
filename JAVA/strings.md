### 796. Rotate String
```java
class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        String doubled=s+s;
        return doubled.contains(goal);

        
    }
}
```
### separate character
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        for(int i=0;i<n;i++){
            System.out.printf("%c ",str.charAt(i));
        }
    }
}
```
### count words
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
      
         String[] letter=str.split("\\s+");
        int count=letter.length;
         System.out.print(count);

    }
}
```
### extract a substring from a given string
```java
public class SubstringExample {
    public static void main(String[] args) {
        String str = "Hello, World!";
        
        // Extracting substring from index 0 to 5
        String result = str.substring(0, 5);
        System.out.println(result);  // Output: "Hello"
    }
}
```
### substring is present in string
```java
public class SubstringCheck {
    public static void main(String[] args) {
        String str = "Hello, World!";
        String substr = "World";

        // Check if the substring is present
        if (str.contains(substr)) {
            System.out.println("The substring is present.");
        } else {
            System.out.println("The substring is not present.");
        }
    }
}

```
```java
public class SubstringCheck {
    public static void main(String[] args) {
        String str = "Hello, World!";
        String substr = "World";

        // Check if the substring is present using indexOf
        if (str.indexOf(substr) != -1) {
            System.out.println("The substring is present.");
        } else {
            System.out.println("The substring is not present.");
        }
    }
}

```
```java
public class SubstringCheck {
    public static void main(String[] args) {
        String str = "Hello, World!";
        String substr = "World";
        
        // Check if 'str' contains 'substr' using matches() and regex
        if (str.matches(".*" + substr + ".*")) {
            System.out.println("The substring is present.");
        } else {
            System.out.println("The substring is not present.");
        }
    }
}

```
### occurrence of 'the' 
```java
import java.util.Scanner;

public class WordFrequency {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter a string:");
        String str = scan.nextLine();
        str = str.toLowerCase();

        String[] words = str.split("\\s+");

        int count = 0;
        for (int i = 0; i < words.length; i++) {
            if (words[i].equals("the")) {
                count++;
            }
        }
 
        System.out.println("The word 'the' appears " + count + " times.");
    }
}

```
### replace the spaces in a string with a specific character 
```java
public class ReplaceSpaces {
    public static void main(String[] args) {
        // Original string
        String str = "Hello World, How are you?";
        
        // Replace spaces with a specific character, e.g., '-'
        String replacedStr = str.replace(' ', '-');
        
        // Output the result
        System.out.println(replacedStr);  // Output: Hello-World,-How-are-you?
    }
}
//String replacedStr = str.replaceAll("\\s+", "-");

```

