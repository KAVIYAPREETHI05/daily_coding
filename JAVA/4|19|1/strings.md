### reverse words
```java
class Solution {
    String reverseWords(String str) {
        int n=str.length();
        StringBuilder temp=new StringBuilder();
        int end=n-1;
        for(int i=n-1;i>=0;i--){
            if(str.charAt(i)=='.'){
                int start=i+1;
                while(start<=end){
                    temp.append(str.charAt(start++));
                    
                }
                temp.append('.');
                end=i-1;
                
            }
        }
        for(int i=0;i<=end;i++){
            temp.append(str.charAt(i));
        }
        return temp.toString();
    }
}//sentence reformatting
```
### String Rotated by 2 Places

```java

class Solution
{
   
    public static boolean isRotated(String str1, String str2)
    {
        if(str1.length() !=str2.length()){
            return false;
        }
        if(str1.equals(str2) || str1.length()<=1){
            return false;
        }
        String leftRotation=str1.substring(2)+str1.substring(0,2);
        String rightRotation = str1.substring(str1.length() - 2) + str1.substring(0, str1.length() - 2);
        return str2.equals(leftRotation) || str2.equals(rightRotation);

       
    
}
}
```
### roman to int
```java

class Solution {
    public int romanToDecimal(String s) {
       HashMap<Character,Integer> romanMap=new HashMap<>();
       romanMap.put('I', 1);
        romanMap.put('V', 5);
        romanMap.put('X', 10);
        romanMap.put('L', 50);
        romanMap.put('C', 100);
        romanMap.put('D', 500);
        romanMap.put('M', 1000);
        int total=0;
        int prevValue=0;
        for (int i = s.length() - 1; i >= 0; i--) {
            char currentChar = s.charAt(i);
            int currentValue = romanMap.get(currentChar);

            if(currentValue<prevValue){
                total-=currentValue;
            }
            else{
                total+=currentValue;
            }
            prevValue=currentValue;}
            return total;
    }
}
```
### anagram
```java

class Solution {
    public static boolean isAnagram(String a, String b) {
        if(a.length() !=b.length()){
            return false;
        }
        HashMap<Character,Integer> temp=new HashMap<>();
        
        for(int i=0;i<a.length();i++){
            char currChar=a.charAt(i);
            if(temp.containsKey(currChar)){
                temp.put(currChar,temp.getOrDefault(currChar,0)+1);
            }
            else{
                temp.put(currChar,1);
            }
        }
        for(int i=0;i<b.length();i++){
            char currChar=b.charAt(i);
            if(!temp.containsKey(currChar)){
                return false;
            }
        temp.put(currChar,temp.get(currChar)-1);
        if(temp.get(currChar)==0){
            temp.remove(currChar);
        }

        }
        return temp.isEmpty();
    }
}
```
### remove duplicates
```java
//time limit exceeded
class Solution {
    String removeDups(String str) {
        
        int[]temp=new int[26];
        StringBuilder newstr=new StringBuilder();
        

        Arrays.fill(temp,0);
        for(int i=0;i<str.length();i++){
            char currChar=str.toLowerCase().charAt(i);
            int idx=currChar-'a';
            if(temp[idx]==0){
                temp[idx]++;
                newstr.append(currChar);
                
                
            }
        }
        return newstr.toString();
    }
}

```
```java

class Solution {
    String removeDups(String str) {
        
       HashSet<Character> temp=new HashSet<>();
       StringBuilder newstr=new StringBuilder();
       
       String lowerStr=str.toLowerCase();
       for(int i=0;i<lowerStr.length();i++){
           char curr=lowerStr.charAt(i);
           if(temp.add(curr)){
               newstr.append(curr);
               
           }
           
       }
       return newstr.toString();
    }
}
```
### Longest Distinct characters in string
```java
import java.util.HashSet;

class Solution {
    public int longestDistinctSubstring(String S) {
        int n = S.length();
        HashSet<Character> set = new HashSet<>();
        
        int left = 0; // Left pointer for the sliding window
        int maxLength = 0; // To store the maximum length found

        for (int right = 0; right < n; right++) {
            char currChar = S.charAt(right);

            // If the character is already in the set, move the left pointer
            while (set.contains(currChar)) {
                set.remove(S.charAt(left));
                left++;
            }

            // Add the current character to the set
            set.add(currChar);
            // Update the maximum length if needed
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength; // Return the maximum length found
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String input = "geeksforgeeks";
        int result = sol.longestDistinctSubstring(input);
        System.out.println(result); // Output: 7
    }
}

```
### Implement Atoi
```java
class Solution {
    public int atoi(String input) {
       
        try {
            int output = Integer.parseInt(input);
            return output;  // Output will be -123
        } catch (NumberFormatException e) {
            return-1; // Handle invalid input
        }
    }
}
```
### Implement strstr
```java
class GfG
{
    //Function to locate the occurrence of the string x in the string s.
    int strstr(String s, String x)
    {
        int index=s.indexOf(x);
       if(index!=-1)
       return index;
       return -1;
    }
}
```
### Search Pattern (Rabin-Karp Algorithm)
```java
class Solution
{
    
    ArrayList<Integer> search(String pattern, String text)
    {
        int n=text.length();
        int m=pattern.length();
         ArrayList<Integer>temp=new ArrayList<>();
    
    for(int i=0;i<=n-m;i++){
        if(text.substring(i,i+m).equals(pattern)){
            temp.add(i+1);
        }
    }
    
         return temp;
    }
}
```
### Longest Prefix Suffix   KMP (Knuth-Morris-Pratt)
```java
//time limit exceeded
class Solution {
    int lps(String str) {
        int n=str.length();
        
        for(int i=n-1;i>=0;i--){
            String prefix=str.substring(0,i);
            String suffix=str.substring(n-i);
            if(prefix.equals(suffix)){
                return prefix.length();
            }
            
        }
        
        return 0;
        
    }
}
```
```java
class Solution {
    int lps(String str) {
        int n = str.length();
        int[] lps = new int[n];
        
        int len = 0; 
        int i = 1;

        while (i < n) {
            if (str.charAt(i) == str.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; 
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps[n - 1];
    }
}
```
### Longest Common Prefix of Strings
```java
class Solution {
    public String longestCommonPrefix(String arr[]) {
        // code here
        if(arr==null || arr.length==0){
            return "-1";
        }
        String prefix=arr[0];
        for(int i=1;i<arr.length;i++){
            while(arr[i].indexOf(prefix)!=0){
                prefix=prefix.substring(0,prefix.length()-1);
                
                if(prefix.isEmpty()){
                    return "-1";
                }
                
            }
        }
        return prefix;
    }
}
```
### uncommon characters
```java
class Solution
{
    String UncommonChars(String A, String B)
    {int n=A.length();
    int m=B.length();
        int []temp=new int[26];
        for(int i=0;i<n;i++){
                temp[A.charAt(i)-'a']=1;
            
            
        }
        for(int i=0;i<m;i++){
            if(temp[B.charAt(i)-'a']==0){
                temp[B.charAt(i)-'a']=2;
            }
            else if(temp[B.charAt(i)-'a']==1){
                temp[B.charAt(i)-'a']=-1;
            }
            
        }
        StringBuilder newstr=new StringBuilder();
        for(int i=0;i<26;i++){
            if(temp[i]==1 || temp[i]==2 ){
                newstr.append((char)(i+'a'));
            }
        }
        if(newstr.length()==0){
            return "-1";
        }
        return newstr.toString();
        
    }
}
```
