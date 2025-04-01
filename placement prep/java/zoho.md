### NUMBER OF ISLANDS

### LONGEST PALINDROME

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

### Count Pairs Of Similar Strings

i/p  words = ["aba","aabb","abcd","bac","aabc"]
o/p 2

