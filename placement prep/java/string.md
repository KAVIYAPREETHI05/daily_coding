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
