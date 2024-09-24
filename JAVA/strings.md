### input an string and print it
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        System.out.println(str);
    }
}
```
### length of string
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        System.out.println(n);
    }
}
```


### 3. separate individual characters
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        char[] charArray=str.toCharArray();
        System.out.println(charArray);//view output as string
        for(int i=0;i<n;i++){
            System.out.println(charArray[i]);
        }
    }
}
```
### 4.separate individual characters in reverse order
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        char[] charArray=str.toCharArray();
        for(int i=n-1;i>=0;i--){
            System.out.println(charArray[i]);
        }
    }
}
```
### 5. Count words
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        String[] charArray=str.split("\\s+");
        int count=charArray.length;
        System.out.println(count);
    }
}
```
### 6.compare two strings
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        String str2=scan.nextLine();
        int n=str.length();
        if(str.equals(str2)){
          System.out.println("equal");  
        }
        else{
            System.out.println("not equal");
        }
    }
}
```
### 7.count the total number of alphabets, digits and special characters in a string.
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
       int alpha=0;int num=0;int spl=0;
       char[] charArray=str.toCharArray();
       for(int i=0;i<n;i++){
           char letter=charArray[i];
           if(Character.isLetter(letter)){
               alpha++;
           }
           else if(Character.isDigit(letter)){
               num++;
           }
           else if(!Character.isLetterOrDigit(letter) && !Character.isWhitespace(letter)){
               spl++;
           }
       }
       System.out.println(alpha+".."+num+".."+spl);
    }
}
```
### 8.copy string to another string
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        String str2=str;
        System.out.println(str2);//direct assignment
        
        String str3=new String(str);
        System.out.println(str3);//string constructor
        
        String str4=String.valueOf(str);
        System.out.println(str4);//using valueOf method
        
        String str5="".concat(str);
        System.out.println(str5);//concat method
        
        StringBuilder str6=new StringBuilder(str);
        System.out.println(str6.toString());
    
        StringBuffer str7=new StringBuffer(str);
        System.out.println(str7.toString());
        
        char[] charArray=str.toCharArray();
        char[] charCopy=Arrays.copyOf(charArray,charArray.length);
        String str8=new String(charCopy);
        System.out.println(str8);
    }
}
```
### 9.total number of vowels or consonants
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
       int vow=0;int cons=0;
       char[] charArray=str.toCharArray();
       for(int i=0;i<n;i++){
           char letter=charArray[i];
           if(Character.isLetter(letter)){
               if(letter=='a' || letter=='e'||letter=='i'||letter=='o'||letter=='u'){
               vow++;
           }
           else {
               cons++;
           }
           }       }
       System.out.println(vow+".."+cons);
    }
}
```
### 10.sorting a string
```java
//ascending
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
      
       char[] charArray=str.toCharArray();
      Arrays.sort(charArray);
       System.out.println(new String(charArray));
    }
}
```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
      
       Character[] charArray=new Character[n];
       for(int i=0;i<n;i++){
           charArray[i]=str.charAt(i);
       }
       Arrays.sort(charArray,Collections.reverseOrder());
       StringBuilder stb=new StringBuilder();
       for(int i=0;i<n;i++){
           stb.append(charArray[i]);
       }
       System.out.println(stb.toString());
    }
}
```
### 11.extract a substring from a given string
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
      
       System.out.println(str.substring(2));
       System.out.println(str.substring(2,5));

    }
}
```
### 12. substring is present in a string.
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        String str2=scan.nextLine();
        int n=str.length();
       System.out.println(str.contains(str2));

    }
}
```
### 13.upper to lower and lower to upper
```java
class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        char[] charArray=str.toCharArray();
        for(int i=0;i<n;i++){
            char letter=charArray[i];
            if(letter>='a' && letter<='z'){
                charArray[i]=(char)(letter-' ');
            }
            else if(letter>='A' && letter<='Z'){
                charArray[i]=(char)(letter+' ');
                
            }
        }
        System.out.println(new String(charArray));

    }
}


(or)

import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        char[] charArray=str.toCharArray();
        for(int i=0;i<n;i++){
            char letter=charArray[i];
            if(Character.isLowerCase(letter)){
                charArray[i]=Character.toUpperCase(letter);
            }
            else if(Character.isUpperCase(letter)){
                charArray[i]=Character.toLowerCase(letter);
            }
        }
        System.out.println(new String(charArray));

    }
}
```
### 14.frequency of the word ‘the’
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        System.out.println(n);
        
        String[] charArray=str.split("\\s+");
        int m=charArray.length;
        System.out.println(m);

        int count=0;
        for(int i=0;i<m;i++){
            if(charArray[i].equals("the")){
                count++;
            }
        }
        System.out.println(count);

    }
}
```
### 15.frequency of the word ‘the’
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int n=str.length();
        System.out.println(n);
        
        String[] charArray=str.split("\\s+");
        int m=charArray.length;
        System.out.println(m);

        int count=0;
        for(int i=0;i<m;i++){
            if(charArray[i].equals("the")){
                count++;
            }
        }
        System.out.println(count);

    }
}
```
### 16.frequency of char in string
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        char c=scan.next().charAt(0);
        int n=str.length();
       
        
        char[] charArray=str.toCharArray();
        int m=charArray.length;

        int count=0;
        for(int i=0;i<m;i++){
            if(charArray[i]==c){
                count++;
            }
        }
        System.out.println(count);

    }
}
```
### 17.merge string
```c
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        String str2=scan.nextLine();
        
        String str3=str+" "+str2;
        System.out.println(str3);
        
        String str4=str.concat(" ").concat(str2);
        System.out.println(str4);
        
        StringBuilder stb=new StringBuilder();
        stb.append(str);
        stb.append(" ");
        stb.append(str2);
        System.out.println(stb.toString());
        
        StringBuffer stbf=new StringBuffer();
        stbf.append(str);
        stbf.append(" ");
        stbf.append(str2);
        System.out.println(stbf.toString());
        
        String str5=String.join(" ",str,str2);
        System.out.println(str5);
        
        String str7=String.format("%s %s",str,str2);
        System.out.println(str7);
    }
}
```
### 18.string to uppercase
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        String str1=str.toUpperCase();
        System.out.println(str1);
    }
}
```
### 19.check hexadecimal or not
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
       try{
           Long.parseLong(str,16);
           System.out.println("it is hexa");
       }
       catch(NumberFormatException e){
        System.out.println("it is not hexa");

           
       }
    }
}
```

### 21.replace the spaces in a string with a specific character
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
       char[] charArray=str.toCharArray();
       int n=charArray.length;
       for(int i=0;i<n;i++){
           if(charArray[i]==' '){
               charArray[i]='*';
           }
       }
       System.out.println(new String(charArray));
    }
}
        
```

### 23. string before the new line character.
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        int index=str.indexOf("\n");
        if(index!=-1){
            System.out.println(str.substring(0,index));
        }
        else{
       System.out.println(str);
        }
    }
}
```
### 24.remove space
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
       str= str.replaceAll("\\s","");
       System.out.println(str);
        
    }
}
```

### 26. split strings by space into words.
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        String[] stringArray=str.split("\\s+");
        int n=stringArray.length;
        for(int i=0;i<n;i++){
            System.out.println(stringArray[i]);
        }
    }
}


```
### 27.first duplicate
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        char[] charArray=str.toCharArray();
        int n=charArray.length;
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n){
                if(charArray[i]==charArray[j]){
                    System.out.println(charArray[i]);
                    return;
                }
                j++;
            }
        }
        System.out.println("no duplicates");
    }
}
```
### 28.occurance of each char
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        char[] charArray=str.toCharArray();
        int n=charArray.length;
        for(int i=0;i<n;i++){
            int j=i+1;int count=1;
            while(j<n){
                if( charArray[i]==charArray[j]){
                    count++;
                   
                }
                j++;
            }
            System.out.println(charArray[i]+" occurs "+count);
            while(i+1<n && charArray[i]==charArray[i+1]){
                i++;
            }
        }
     
    }
}
(or)
#include <stdio.h>
int main()
{
    char s[100];
    fgets(s,sizeof(s),stdin);
    int i=0;
    while(s[i]!='\0'){
        int count=1;
        int j=i+1;
        while(s[j]!='\0'){
            if(s[i]==s[j]){                
                count++;
                s[j]='\0';
            }
            j++;            
        }
        printf("%c occurs %d times\n",s[i],count);
        i++;
    }
    return 0;
}
```


### 30. open brackets and closed brackets are same type of brackets.
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>

bool test(char *s, int len) {
    int ctr = 0, x = 0, y = 0, z = 0;
    char *string2;
    string2 = (char *)malloc(len); 

    while (*s != 0) {
        if (*s == '(') {
            x++;
            string2[++ctr] = 1; 
        }
        if (*s == '[') {
            y++;
            string2[++ctr] = 2; 
        }
        if (*s == '{') {
            z++;
            string2[++ctr] = 3; 
        }
        if (*s == ')') {
            if (string2[ctr] == 1) {
                x--;
                ctr--;
            } else {
                free(string2); 
                return false;
            }
        }
        if (*s == ']') {
            if (string2[ctr] == 2) {
                y--;
                ctr--;
            } else {
                free(string2);
                return false;
            }
        }
        if (*s == '}') {
            if (string2[ctr] == 3) {
                z--;
                ctr--;
            } else {
                free(string2);
                return false;
            }
        }
        s++;
    }

    free(string2); 

    if (x > 0 || y > 0 || z > 0)
        return false;

    return true;
}

int main() {
    char string1[80];
    int n, i, x;
    printf("Input a string: ");
    scanf("%s", string1);
    n = strlen(string1);
    printf(" %d", test(string1, n));
    return 0;
}
```
### 31. Replace specific char with another char and numbers with 'n' . 'a' -> 'b', 't' -> 'g', number -> 'n' Input: "Education4all", Output : "Educbgionnbll"
```c
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 100
int main()
{
   char s[MAX_SIZE];
   scanf("%s",s);
int i=0;
while(s[i]!='\0'){
    if(s[i]=='a'){
        s[i]='b';
    }
    else if(s[i]=='t'){
        s[i]='g';
    }
    else if(isdigit(s[i])){
        s[i]='n';
    }
    i++;
}
for(int i=0;i<strlen(s);i++){
    printf("%c",s[i]);
}
    
    return 0;
}
```
### 32.Find the largest and smallest word in a string. Input: The bottle is full Output: is bottle
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        String[] charArray=str.split("\\s+");
        String maxstring="";String minstring="";
        int n=charArray.length;int maxlen=0;int minlen=0;
        for(int i=0;i<n;i++){
            int len=charArray[i].length();
            if(len>maxlen){
                maxlen=len;
                maxstring=charArray[i];
            }
            else{
                minlen=len;
                minstring=charArray[i];
            }
           
        }
        System.out.println(maxstring+".."+minstring);
     
    }
}
```
### 33.Remove duplicate characters in a string input engineering output engir
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String s=scan.nextLine();
        String t=s.toLowerCase();
        int n=s.length();
        StringBuilder stb=new StringBuilder();
        char[] charArray=t.toCharArray();
        for(int i=0;i<n-1;i++){
            if(charArray[i]!='0'){
            stb.append(charArray[i]);
                for(int j=i+1;j<n;j++){
                if(charArray[i]==charArray[j]){
                    charArray[j]='0';
                }
            }
            }
        }
        System.out.println(stb.toString());
            
    }
}
(or)
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String s=scan.nextLine();
        String t=s.toLowerCase();
        int n=s.length();
        StringBuilder stb=new StringBuilder();
        int [] temp=new int[26];
        char[] charArray=t.toCharArray();
        for(int i=0;i<n-1;i++){
            char letter=charArray[i];
            if(temp[letter-'a']==0){
                stb.append(letter);
              
            }
               temp[letter-'a']++;
        }
        System.out.println(stb.toString());
        
    }
}
```
### 34.unique elements 
```c
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 100

int main(){
   char s[MAX_LENGTH];
   fgets(s,sizeof(s),stdin);
   int i=0;
   while(s[i]!='\0'&& s[i]!='\n'){
       int j=0;
       int count=0;
       while(s[j]!='\0' ){
           if(s[i]==s[j]){
               count++;
               if(count>1){
                   break;
               }              
           }
           j++;
       }
       if(count==1){
           printf("%c",s[i]);
       }
       i++;
   }    
}
```
### 35.Print the string replacing the space with given character -- input : string - "Hello World" replace :- "$" -- output : "Hello$World"
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String s=scan.nextLine();
        char o=scan.next().charAt(0);
        char n=scan.next().charAt(0);
       s=s.replace(o,n);
        System.out.println(s);
        
    }
}
```
### 36.Get number of words from user and get the words and print even positions words   
```c
#include <stdio.h>
#include<string.h>
#define max 100
int main()
{
    char s[max];
    char words[max][max];
    int i=0;
    fgets(s,sizeof(s),stdin);
    s[strcspn(s,"\n")]='\0';
    char *token=strtok(s," ");
    while(token !=NULL){
        strcpy(words[i],token);
        i++;
        token=strtok(NULL," ");
    }
    for(int j=1;j<i;j+=2){
        printf("%s",words[j]);
    }
    return 0;
}
```

### 38.Count the no of vowels
```c
#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s[100];int count=0;
    fgets(s,sizeof(s),stdin);
    int i=0;
    while(s[i]!='\0'){
         char ch=s[i];
        if(ch=='a' || ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'){
            count++;
        }
        i++;
    }
printf("%d",count);
    return 0;
}
(or)
#include <stdio.h>
#include<string.h>

int main()
{
    int count=0;
    char s[]="aeiouAEIOU";
    char str[]="kaviya";
    for(int i=0;str[i]!='\0';i++){
        
        if(strchr(s,str[i])){
            count++;
        }
    }
printf("%d",count);
    return 0;
}
```
### 39.Find the first capital letter. input:codeZone output:Z
```c
#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s[100];
    fgets(s,sizeof(s),stdin);
    int i=0;
    while(s[i]!='\0'){
         char ch=s[i];
        if(isupper(s[i])){
            printf("%c",s[i]);
            break;
        }
        i++;
    }

    return 0;
}
```
### 40.Swap adjacent characters in a given string input:OpenAI||output:pOneIA
```c
#include <stdio.h>
int main()
{
    char s[]="kaviya";
    
    int i=0;
    while(s[i]!='\0'){
         char temp=s[i];
         s[i]=s[i+1];
         s[i+1]=temp;
         
        i+=2;
    }
    printf("%s",s);
    return 0;
}
```
### 41.Count the total characters in a string and check the number is odd,even,prime
```c
#include <stdio.h>
#include<string.h>
int isprime(int num){
    if(num<=1){
        return 0;
    }
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    char s[]="kaviyaw";
    int length=strlen(s);    
   
    if(length%2==0){
        printf("even\n");
    }
    else {
        printf("odd\n");
    }
    if(isprime(length)){
        printf("prime\n");
    }
    else{
        printf("not a prime");
    }
    return 0;
}
```
### 42.Smallest appeared character in a string
```c
#include<stdio.h>
#include<string.h>
#include<limits.h>
int main(){
    char s[100];
    char smallest_char=CHAR_MAX;
    fgets(s,sizeof(s),stdin);
    s[strcspn(s,"\n")]='\0';
    int i=0;
    while(s[i]!='\0'){
        if(s[i]<smallest_char){
            smallest_char=s[i];
        }
        i++;
    }
    printf("%c",smallest_char);
}
```
### 43.Smallest word in a String!   (Input: I like cricket,  Output: I )
```c
#include<stdio.h>
#include<string.h>
#include<limits.h>
#define max 100
int main(){
    
    char s[max],smallest_word[max],word[max],ch;
    int i,smallest_length,word_length;
    char smallest_char=CHAR_MAX;
    smallest_length=max;word_length=0;  
    
    fgets(s,sizeof(s),stdin);
    s[strcspn(s,"\n")]='\0';
    i=0;
    while(s[i]!='\0'){
        while(s[i]==' '){
            i++;
        }
        while(s[i]!=' '&& s[i]!='\0'){
            word[word_length++]=s[i];
            i++;
        }
        word[word_length]='\0';
        if(word_length>0){
            if(word_length<smallest_length){
                smallest_length=word_length;
                strcpy(smallest_word,word);
            }
            word_length=0;
        }        
        i++;
       }
    printf("%s",smallest_word);
  }
```
### 44.Rotate a matrix to 90 degree!  
```c
#include <stdio.h>
#define N 3
void rotateMatrix(int matrix[N][N]){
    for(int i=0;i<N;i++){
      for(int j=i;j<N;j++){
          int temp=matrix[i][j];
         matrix[i][j]= matrix[j][i];
         matrix[j][i]=temp;
      }
    
  }
   for(int i=0;i<N;i++){
      for(int j=0,k=N-1;j<k;j++,k--){
          int temp=matrix[i][j];
         matrix[i][j]= matrix[i][k];
         matrix[i][k]=temp;
      }
    
  }
}

#define N 3  
int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(matrix);

  for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
          printf("%d ",matrix[i][j]);
      }
      printf("\n");
  }

    return 0;
}
```
### 45.palindrome
```c
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int check(char str[MAX_LENGTH]){
int length=strlen(str);
int start=0;
int end=length-1;
    for(int i=start;i<end;i++,end--){
        if(str[i]!=str[end]){
            return 0;           
        }        
    }
    return 1;
    }
int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 
   
    if(check(str)){
        printf("yes");
    }
    else{
        printf("no");
    }

    return 0;
}
```
### 47.largest Palindrome
```c
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int isPalindrome(const char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Palindrome
}

void largestPalindrome(const char *str) {
    int maxLength = 1;
    int start = 0;
    int len = strlen(str);
    int low, high;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (isPalindrome(str, i, j)) {
                if (j - i + 1 > maxLength) {
                    start = i;
                    maxLength = j - i + 1;
                }
            }
        }
    }

    printf("Largest palindrome substring: ");
    for (int k = start; k < start + maxLength; k++) {
        printf("%c", str[k]);
    }
    printf("\n");
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the trailing newline

    largestPalindrome(str);

    return 0;
}
```
### 48.reverse a string
```c
#include <stdio.h>
#include<string.h>
int main()
{
char s[]="kaviya";
int length=strlen(s);
for(int i=length;i>=0;i--){
    printf("%c",s[i]);
}
    return 0;
}
(or)
#include <stdio.h>
#include<string.h>
int main()
{
char s[]="kaviya";
int length=strlen(s);
for(int i=0;i<length/2;i++){
    char temp=s[i];
    s[i]=s[length-i-1];
    s[length-i-1]=temp;
  
}
  printf("%s",s);
    return 0;
}
```
### 49.palindrome string 
```c
#include <stdio.h>
#include<string.h>
int main()
{
char s[]="mom";
int length=strlen(s);
for(int i=0;i<length/2;i++){
  
    if(s[i]!=s[length-i-1]){
        printf("no");
        break;        
    }
    else{
        printf("yes");
    }
   } 
    return 0;
}
```
### 50.vowel or consonant
```c
#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
char s[]="kaviya";
int length=strlen(s);
int vow=0;
int cons=0;
for(int i=0;i<length;i++){
   char ch=tolower(s[i]);
  
    if(ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' ){
        vow++;
            }
    else{
        cons++;
    }
   }
   printf("%d vowels %d consonants ",vow,cons);
 
    return 0;
}
```
### 51.length of string without strlen
```c
#include <stdio.h>
int main()
{
char s[]="kaviya";
int length=0;
int i=0;
while(s[i]!='\0'){
    length++;
    i++;
}
printf("%d",length);
    return 0;
}
```
### 52. Remove space
```c
#include <stdio.h>
int main()
{
char s[]="kaviya is good";
int length=0;
int i=0;
int j=0;
while(s[i]!='\0' ){
    if(s[i]!=' '){
   s[j++]=s[i];
    }
    i++;
}
s[j]='\0';
printf("%s",s);
    return 0;
}
```
### 53.duplicate char in string
```c
#include<stdio.h>
int main(){
    char s[]="kaaiviya";
    int count[256]={0};
    for(int i=0;s[i];i++){
        count[s[i]]++;
    }
    for(int i=0;i<256;i++){
        if(count[i]>1){
            printf("%c",i);
        }
    }
}
```
### 54.count words in string
```c
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
int main(){
    char s[]="hello    t   world";
    int count=0;
    bool inword=false;
    for(int i=0;s[i]!='\0';i++){
        if(isspace(s[i])){
            inword=false;
        }
        else if(!inword){
            inword=true;
            count++;
        }
    }
    printf("%d",count);
}
```
### 55.concatenate two strings
```c
#include<stdio.h>
#include<string.h>
int main(){
    char s[50]="hello    t   world ";
    char t[]="kaviya";
    strcat(s, t);
    printf("%s",s);   
}
(or)
#include<stdio.h>
#include<string.h>
int main(){
    char s[50]="hello    t   world ";
    char t[]="kaviya";
    int j=0;
    for(int i=0;s[i]!='\0';i++){
        s[j++]=s[i];
         }
     for(int i=0;t[i]!='\0';i++){
        s[j++]=t[i];
         }
    printf("%s",s);
 }
```
### 56.compare two string
```c
#include<stdio.h>
#include<string.h>
int main(){
    char s[50]="hello    t   world ";
    char t[]="kaviya";
if(strcmp(s, t)==0){
    printf("yes equal");
}
    else{
        printf("not equal");
    }
}
(or)
#include<stdio.h>
#include<string.h>
int main(){
    char s[50]="kaviya";
    char t[]="kaviya";
    int isequal=1;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!=t[i]){
            isequal=0;
            break;
        }
}
if(isequal){
    printf("yes equal");
}
else{
    printf("not equal");
}
}
```
### 57.frequency of char in string
```c
#include<stdio.h>
#include<string.h>
int main(){
    char s[50]="kaviya";
   char ch='a';
    int count=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==ch){
            count++;
        }
}
    printf("%d",count);

}
```
### 58.remove specific char in string
```c
#include<stdio.h>
#include<string.h>
int main(){
    char s[50]="kaviya";
   char ch='a';
    int count=0;int j=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!=ch){
            s[j++]=s[i];
        }
}
s[j]='\0';
    printf("%s",s);
}
```
### 59.first non-repeating char
```c
#include<stdio.h>
#include<string.h>
int main(){
    char s[50]="kaviya";
    int count[256]={0};
    for(int i=0;s[i];i++){
        count[s[i]]++;
        }
        for(int i=0;s[i];i++){
            if(count[s[i]]==1){
                printf("%c",s[i]);
                break;
            }
        }
}
```
### 60.remove duplicates
```c
#include<stdio.h>
#include<string.h>
int main(){
    char s[50]="kaaviyya";
    int count[256]={0};
    int j=0;
        for(int i=0;s[i];i++){
            if(!count[s[i]]){
                count[s[i]]=1;
                s[j++]=s[i];
            }
        }
        s[j]='\0';
        printf("%s",s);
}
```
### 61.anagrams(same letters at differ place)
```c
#include<stdio.h>
#include<string.h>
int isAnagrams(char s[],char t[]){
     int count1[256]={0};
    int count2[256]={0};
    for(int i=0;s[i];i++){
        count1[s[i]]++;
    }
     for(int i=0;t[i];i++){
        count2[t[i]]++;
    }
    if(strlen(s)!=strlen(t)){
             return 0;
        
    }
        for(int i=0;i<256;i++){
            if(count1[i]!=count2[i]){
                    return 0;
           
            }
        }
        return 1;
    }
int main(){
    char s[]="kaviya";
    char t[]="kayaiv";
    if(isAnagrams(s,t)){
        printf("yes anagrams");
    }
    else{
        printf("not anagrams");
    }
   }
```
### 62.substring
```c
#include<stdio.h>
#include<string.h>

int main(){
    char s[]="kaviya is sky";
    char t[]="sky";
    if(strstr(s,t)){
        printf("yes found");
    }
    else{
        printf("not found");
    }
   }
(or)
#include<stdio.h>
int substring(char s[],char t[]){
int j;
    for(int i=0;s[i]!='\0';i++){
        for(j=0;t[j]!='\0';j++){
            if(s[i+j]!=t[j]){
                break;
            }
        }
        if(t[j]=='\0'){
            return 1;
        }
    }
    return 0;
}
int main(){
    char s[]="kaviya is sky";
    char t[]="sky";
    if(substring(s,t)){
        printf("yes");
    }
    else{
        printf("no");
    }
}
```
### 63.string to int
```c
#include<stdio.h>
#include<stdlib.h>
int main(){
    char s[]="123";
    int num=atoi(s);
    printf("%d",num);
}
```
### 64.int to string
```c
#include<stdio.h>
#include<stdlib.h>
int main(){
   int num=1234;
   char s[50];
   sprintf(s,"%d",num);
   printf("%s",s);
}
```
### 65.first word caps
```c
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int capsletter(char str[]){
    int newwrod=1;
    for(int i=0;str[i]!='\0';i++){
        if(isspace(str[i])){
            newwrod=1;
        }
        else if(newwrod){
            str[i]=toupper(str[i]);
            newwrod=0;
        }
    }
}
int main() {
    char str[] = "kaviya is sky";
    capsletter(str);
    printf("%s\n", str);
    return 0;
}
```
### 66.string to title case
```c
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int capsletter(char str[]){
    int newwrod=1;
    for(int i=0;str[i]!='\0';i++){
        if(isspace(str[i])){
            newwrod=1;
        }
        else if(newwrod){
            str[i]=toupper(str[i]);
            newwrod=0;
        }
        else{
            str[i]=tolower(str[i]);
        }
    }
}
int main() {
    char str[] = "kaviya is SKY";//Kaviya Is Sky
    capsletter(str);
    printf("%s\n", str);
    return 0;
}
```
### 67.first occurrence
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[] = "kaviya is SKY";
    char ch='a';
    int length=strlen(str);
  for(int i=0;str[i]!='\0';i++){
      if(str[i]==ch){
         printf("%c\n%d", str[i],i); 
         break;
      }
  }
    return 0;
}
```
### 68.last occurrence
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[] = "kaviya is SKY";
    char ch='a';
    int length=strlen(str);
  for(int i=0;str[i]!='\0';i++){
      if(str[i]==ch){
         printf("%c\n%d", str[i],i);          
      }
  }
    return 0;
}
```
### 69.Toggle Case
```c
#include<stdio.h>
#include<string.h>
int main(){
    char str[]="Kaviya";
    int length=strlen(str);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]=str[i]-32;
        }
        else if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]+32;
        }
    }
    printf("%s",str);
}
```
### 70.reverseString 
```c
char* reverseWord(char* str) {
    int n=strlen(str);
    
    for(int i=0;i<n/2;i++){
        int temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
    return str;
}
```
### 71.copy one string to another
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    char temp[100];
    fgets(str,sizeof(str),stdin);
    strcpy(temp,str);
    printf("%s",temp);
    return 0;
}
(or)

#include <stdio.h>
int main() {
    char str[100];
    char temp[100];
    fgets(str,sizeof(str),stdin);
   // printf("%s",str);
   int i=0;
   for(int i=0;str[i]!='\0';i++){
       temp[i]=str[i];
   }
    printf("%s",temp);
    return 0;
}
```
### 72.concatenate two strings
```c

#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    char temp[100];
    fgets(str,sizeof(str),stdin);
    fgets(temp,sizeof(temp),stdin);
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='\n'){
            str[i]='\0';
        }
        i++;
    }
    strcat(str," ");
    strcat(str, temp);
    printf("%s",str);
    return 0;
}
(or)


#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    char temp[100];
    fgets(str,sizeof(str),stdin);
    fgets(temp,sizeof(temp),stdin);
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='\n'){
            str[i]='\0';
            break;
        }
        i++;
    }
    str[i++]=' ';
    int j=0;
    while(temp[j]!='\0'){
        str[i++]=temp[j++];
            }
    printf("%s",str);
    return 0;
}
```
### 73.compare two strings
```c

#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    char temp[100];
    fgets(str,sizeof(str),stdin);
    fgets(temp,sizeof(temp),stdin);
    int res;
    res=strcmp(str,temp);
    if(res==0){
        printf("both string are equal");
    }
    else if(res<0){
        printf("str is lexicographically smaller than the temp");
    }
    else{
        printf("temp is lexicographically smaller than str");
    }
   
    return 0;
}
(or)

#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    char temp[100];
    fgets(str,sizeof(str),stdin);
    fgets(temp,sizeof(temp),stdin);
    int i=0;int found=0;
    while(str[i]!='\0' && temp[i]!='\0'){
        if(str[i]!=temp[i]){
            found=1;
            break;
        }
        i++;
    }
    if(found){
        if(str[i]>temp[i]){
                    printf("str is larger than temp");

        }
        else{
        printf("temp is larger than str");
            
        }
    }
    else{
         printf("both strings are equal");
       
    }
   
    return 0;
}
```
### 74.convert string to lower
```c

#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[100];
   fgets(str,sizeof(str),stdin);
   for(int i=0;str[i]!='\0';i++){
       str[i]=tolower(str[i]);
   }
   printf("%s",str);
   
    return 0;
}
(or)

#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[100];
   fgets(str,sizeof(str),stdin);
   for(int i=0;str[i]!='\0';i++){
      if(str[i]>='A' && str[i]<='Z'){
          str[i]=str[i]+('a'-'A');
      }
   }
   printf("%s",str);
   
    return 0;
}
```
### 75.convert string to upper
```c

#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[100];
   fgets(str,sizeof(str),stdin);
   for(int i=0;str[i]!='\0';i++){
       str[i]=toupper(str[i]);
   }
   printf("%s",str);
   
    return 0;
}
(or)
#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[100];
   fgets(str,sizeof(str),stdin);
   for(int i=0;str[i]!='\0';i++){
      if(str[i]>='a' && str[i]<='z'){
          str[i]=str[i]-('a'-'A');
      }
   }
   printf("%s",str);
   
    return 0;
}
```
### 76.convert string to toggle
```c

#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[100];
   fgets(str,sizeof(str),stdin);
   for(int i=0;str[i]!='\0';i++){
      if(islower(str[i])){
          str[i]=toupper(str[i]);
      }
      else if(isupper(str[i])){
          str[i]=tolower(str[i]);
      }
   }
   printf("%s",str);
   
    return 0;
}
(or)



#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[100];
   fgets(str,sizeof(str),stdin);
   for(int i=0;str[i]!='\0';i++){
      if(str[i]>='a' && str[i]<='z'){
          str[i]=str[i]-('a'-'A');
      }
      else if(str[i]>='A' && str[i]<='Z'){
            str[i]=str[i]+('a'-'A');
      }
   }
   printf("%s",str);
   
    return 0;
}
```
### 77.count alph,num,spl
```c

#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[100];
   fgets(str,sizeof(str),stdin);
   int alph=0;int num=0;int spl=0;
   for(int i=0;str[i]!='\0';i++){
      if(isalpha(str[i])){
          alph++;
      }
      else if(isdigit(str[i])){
            num++;
      }
      else if(!isspace(str[i])){
          spl++;
      }
   }
   printf("%d alph %d num %d spl ",alph,num,spl);
   
    return 0;
}
(or)

#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
    char str[100];
   fgets(str,sizeof(str),stdin);
   int alph=0;int num=0;int spl=0;
   for(int i=0;str[i]!='\0';i++){
      if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
          alph++;
      }
      else if(str[i]>='0' && str[i]<='9'){
            num++;
      }
      else{
          spl++;
      }
   }
   printf("%d alph %d num %d spl ",alph,num,spl);
   
    return 0;
}
```
### 78. count vowel and consonant
```c
#include <stdio.h>
#include<ctype.h>
int main() {
   char str[100];
   fgets(str,sizeof(str),stdin);
   int vowel=0;int consonant=0;
   int i=0;
   while(str[i]!='\0'){
       if(str[i]=='\n'){
           str[i]='\0';
       }
       i++;
   }
   for(int i=0;str[i]!='\0';i++){
       str[i]=tolower(str[i]);
       if(isalpha(str[i])){
           if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
           vowel++;
       }
       else{
           consonant++;
       }
       }
   }
   printf("%d vowel %d consonant",vowel, consonant);
    return 0;
}

```
### 79. count words
```c
#include <stdio.h>
#include<ctype.h>
int main() {
   char str[100];
   fgets(str,sizeof(str),stdin);
   int count=0;char prev=' ';
   for(int i=0;str[i]!='\0';i++){
       if(str[i]==' ' || str[i]=='\n' || str[i]=='\0' || str[i]=='\t'){
           
       if(prev!=' ' && prev!='\t'&& prev!='\n' ){
           count++;
       }
       
   }
   prev=str[i];
   }
   printf("%d ",count);
    return 0;
}

```
### 80.reverse string
```
#include <stdio.h>
#include<string.h>
int main() {
   char str[100];
   fgets(str,sizeof(str),stdin);
   int n=strlen(str);
   if(str[n-1]=='\n'){
       str[n-1]='\0';
       n--;
   }
   for(int i=n-1;i>=0;i--){
printf("%c",str[i]);
   }
    return 0;
}
(or)
#include <stdio.h>
#include<string.h>
int main() {
   char str[100];
   fgets(str,sizeof(str),stdin);
   int n=strlen(str);
   if(str[n-1]=='\n'){
       str[n-1]='\0';
       n--;
   }
   for(int i=0;i<n/2;i++){
       int temp=str[i];
       str[i]=str[n-1-i];
       str[n-1-i]=temp;
   }
   
  printf("%s",str);
    return 0;
}


```
### 81.check palindrome
```c
#include <stdio.h>
#include<string.h>
int main() {
   char str[100];
   fgets(str,sizeof(str),stdin);
   int n=strlen(str);
   if(str[n-1]=='\n'){
       str[n-1]='\0';
       n--;
   }int found=1;
   for(int i=0;i<n/2;i++){
      if(str[i]!=str[n-1-i]){
          found=0;
      }
   }
   if(found){
       printf("yes,palindrome");
   }
   else{
       printf("no,not palindrome");
   }
   
  
    return 0;
}

```
### 82.reverse word
```c
// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    char reverse[100]={0};
    int n=strlen(str);
    if(n>0&& str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
   int size=0;
    int end=n-1;
    char prev=' ';
    for(int i=end;i>=0;i--){
        if(str[i]==' ' || str[i]=='\n' ||str[i]=='\t'){
             if(prev!=' ' && prev!='\n' && prev!='\t'){
               int start=i+1;
               while(start<=end){
                   reverse[size++]=str[start++];
               }
               reverse[size++]=' ';
               end=i-1;
            }
        }
        prev=str[i];
            }
    if(end>=0){
        int start=0;
        while(start<=end){
            reverse[size++]=str[start++];
        }
            }
    reverse[size]='\0';
    printf("%s",reverse);
    return 0;
}
```
### 83.first occurrence in string
```c
#include <stdio.h>

int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    char ch;
    scanf("%c",&ch);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==ch){
            printf("%d",i);
            break;
        }
    }
    return 0;
}
```
### 84.last occurrence in string
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    char ch;
    scanf("%c",&ch);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    for(int i=n-1;i>=0;i--){
        if(str[i]==ch){
            printf("%d",i);
            break;
        }
    }
    return 0;
}
```
### 85. all occurrence of char in string
```c
#include <stdio.h>

int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    char ch;
    scanf("%c",&ch);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==ch){
            printf("%d ",i);
            }
    }
    return 0;
}
```
### 86.count all occurrence
```c
#include <stdio.h>

int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    char ch;
    scanf("%c",&ch);
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==ch){
            count++;
            }
    }
    printf("%d",count);
    return 0;
}
```
### 87.maximum occurrence char
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
     char temp[256]={0};
    for(int i=0;str[i]!='\0';i++){
        temp[str[i]]++;
    }
    int maxcount=0;
    char maxchar='\0';
    for(int i=0;i<256;i++){
        if(temp[i]>maxcount){
            maxcount=temp[i];
            maxchar=(char)i;
        }
    }
    printf("%c",maxchar);
    
    return 0;
}
```
### 88.minimum occurrence
```c
#include <stdio.h>
#include<string.h>
#include<limits.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
     char temp[256]={0};
    for(int i=0;str[i]!='\0';i++){
        temp[str[i]]++;
    }
    int mincount=INT_MAX;
    char minchar='\0';
    for(int i=0;i<256;i++){
        if(temp[i]>0 && temp[i]<mincount && i!='\n'){
            mincount=temp[i];
            minchar=(char)i;
        }
    }
    printf("%c",minchar);
    
    return 0;
}
```
### 89.freq of each char
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
     int temp[256]={0};
    for(int i=0;str[i]!='\0';i++){
        temp[(unsigned char)str[i]]++;
    }
    int maxcount=0;
    char maxchar='\0';
    for(int i=0;i<256;i++){
       if(temp[i]>0){
            printf("%c occurs %d times\n",i,temp[i]);
       }
    }
    
    
    return 0;
}
```
### 90.remove first occurrence
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    char ch;
    scanf("%c",&ch);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }int index;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==ch){
            index=i;
            break;
        }
    }
    int i=0;
    while(i<n && i!=index){
        i++;
    }
    while(i<n){
        str[i]=str[i+1];
        i++;
    }
    printf("%s",str);
    return 0;
}
```
### 91. remove last occurrence
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    char ch;
    scanf("%c",&ch);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }int index;
    for(int i=n-1;i>=0;i--){
        if(str[i]==ch){
            index=i;
            break;
        }
    }
    int i=0;
    while(i<n && i!=index){
        i++;
    }
    while(i<n){
        str[i]=str[i+1];
        i++;
    }
    printf("%s",str);
    return 0;
}
```
### 92.remove all occurrence
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
    char ch;
    scanf("%c",&ch);
    char temp[100];
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }int size=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=ch){
            temp[size++]=str[i];
        }
    }
    temp[size]='\0';
    printf("%s",temp);
   
    return 0;
}
```
### 93.remove all repeated char
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    char result[100];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
     int seen[256]={0};
     int j=0;
     for(int i=0;str[i]!='\0';i++){
         unsigned char index=(unsigned char)str[i];
         if(!seen[index]){
             seen[index]=1;
             result[j++]=str[i];
         }
     }
     result[j]='\0';
     printf("%s",result);
    
    
    
    return 0;
}
```
### 93.replace all occurrence of char with another
```c
#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
   
    char replace;    char replacewith;
    scanf(" %c",&replace);
    scanf(" %c",&replacewith);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==replace){
            str[i]=replacewith;
        }
    }
    
    printf("%s",str);
   
    return 0;
}
```
### 93.replace first occurrence of char with another
```c

#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
   
    int n=strlen(str);
            if(str[n-1]=='\n'){
            str[n-1]='\0';
            n--;
        }
         char present;char changeto;
    scanf("%c",&present);
    scanf(" %c",&changeto);
    for(int i=0;i<n;i++){
        if(str[i]==present){
            str[i]=changeto;
            break;
        }
    }       printf("%s",str);
    return 0;
}
```
### 93.replace last occurrence of char with another
```c

#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    fgets(str,sizeof(str),stdin);
   
    int n=strlen(str);
            if(str[n-1]=='\n'){
            str[n-1]='\0';
            n--;
        }
         char present;char changeto;
    scanf("%c",&present);
    scanf(" %c",&changeto);
    for(int i=n-1;i>=0;i--){
        if(str[i]==present){
            str[i]=changeto;
            break;
        }
    }       printf("%s",str);
    return 0;
}
```
### find first occurrence of word from string
```c
#include <stdio.h>
#include<string.h>
#define MAX_SIZE 255
int main() {
    char str[MAX_SIZE];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    char word[MAX_SIZE];
    fgets(word,sizeof(word),stdin);
    int m=strlen(word);
    if(word[m-1]=='\n'){
        word[m-1]='\0';
        m--;
    }
    int i=0;int found=1;
    while(str[i]!='\0'){
        if(str[i]==word[0]){
            int j=0;found=0;
            while(word[j]!='\0'){
                if(str[i+j]!=word[j]){
                    found=1;
                    break;
                }
                j++;
            }
            if(!found){
                break;
            }
        }
        i++;
    }
    if(!found){
        printf("%d",i);
    }
    else{
        printf("no word found");
    }
    return 0;
}
```
### find last occurrence of word from string
```c
#include <stdio.h>
#include<string.h>
#define MAX_SIZE 255
int main() {
    char str[MAX_SIZE];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    char word[MAX_SIZE];
    fgets(word,sizeof(word),stdin);
    int m=strlen(word);
    if(word[m-1]=='\n'){
        word[m-1]='\0';
        m--;
    }
    int i=n-1;int found=1;
    while(i>=0){
        if(str[i]==word[m-1]){
            int j=m-1;found=0;
            while(j>=m){
                if(str[i-(m-1-j)]!=word[j]){
                    found=1;
                    break;
                }
                j--;
            }
            if(!found){
                break;
            }
        }
        i--;
    }
    if(!found){
        printf("%d",i-(m-1));
    }
    else{
        printf("no word found");
    }
    return 0;
}
```
###  search all occurrence of word from string
```c
#include <stdio.h>
#include<string.h>
#define MAX_SIZE 255
int main() {
    char str[MAX_SIZE];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    char word[MAX_SIZE];
    fgets(word,sizeof(word),stdin);
    int m=strlen(word);
    if(word[m-1]=='\n'){
        word[m-1]='\0';
        m--;
    }
    int i=0;int found=1;
    while(str[i]!='\0'){
        if(str[i]==word[0]){
            int j=0;found=0;
            while(word[j]!='\0'){
                if(str[i+j]!=word[j]){
                    found=1;
                    break;
                }
                j++;
            }
            if(!found){
                printf("%d ",i);
            }
        }
        i++;
    }
   
    if(found){
        printf("no word found");
    }
    return 0;
}
```
### remove all occurrence of word in string
```c
#include <stdio.h>
#include<string.h>
#define MAX_SIZE 255
int main() {
    char str[MAX_SIZE];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    char word[MAX_SIZE];
    fgets(word,sizeof(word),stdin);
    int m=strlen(word);
    if(word[m-1]=='\n'){
        word[m-1]='\0';
        m--;
    }
    int i=0;int found=1;
    while(str[i]!='\0'){
        if(str[i]==word[0]){
            int j=0;found=0;
            while(word[j]!='\0'){
                if(str[i+j]!=word[j]){
                    found=1;
                    break;
                }
                j++;
            }
            if(!found){
                int k=i;
                    while(str[k+m]!='\0'){
                        str[k]=str[k+m+1];
                        k++;
                    }
                    str[k]='\0';
                    n-=m;
                    
                                }
        }
        i++;
    }
   printf("%s",str);
    return 0;
}
```
### remove first occurrence of a word in given string 
```c
#include <stdio.h>
#include<string.h>
#define MAX_SIZE 255
int main() {
    char str[MAX_SIZE];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    char word[MAX_SIZE];
    fgets(word,sizeof(word),stdin);
    int m=strlen(word);
    if(word[m-1]=='\n'){
        word[m-1]='\0';
        m--;
    }
    int i=0;int found=1;
    while(str[i]!='\0'){
        if(str[i]==word[0]){
            int j=0;found=0;
            while(word[j]!='\0'){
                if(str[i+j]!=word[j]){
                    found=1;
                    break;
                }
                j++;
            }
            if(!found){
                break;
            }
        }
        i++;
    }
    if(!found){
                int k=i;
                    while(str[k+m]!='\0'){
                        str[k]=str[k+m+1];
                        k++;
                    }
                    str[k]='\0';
                    n-=m;
                    
                                }
   printf("%s",str);
    return 0;
}
```
### remove last occurrence of a word in given string 
```c
#include <stdio.h>
#include<string.h>
#define MAX_SIZE 255
int main() {
    char str[MAX_SIZE];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    char word[MAX_SIZE];
    fgets(word,sizeof(word),stdin);
    int m=strlen(word);
    if(word[m-1]=='\n'){
        word[m-1]='\0';
        m--;
    }
    int i=n-1;int found=1;
    while(i>=0){
        if(str[i]==word[m-1]){
            int j=m-1;found=0;
            while(j>=0){
                if(str[i-(m-1-j)]!=word[j]){
                    found=1;
                    break;
                }
                j--;
            }
            if(!found){
                break;
            }
        }
        i--;
    }
    if(!found){
        int k=i-m+1;
       while(str[k+m]!='\0'){
           str[k]=str[k+m+1];
           k++;
       }
       str[k]='\0';
       n-=m;
    }
    else{
        printf("no word found");
    }
    printf("%s",str);
    return 0;
}
```
### remove front space
```c


#include <stdio.h>
#include<string.h>
int main()
{
    char str[100];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    int i=0;
    while(str[i]==' '){
        
        i++;
    }
    int index=0;
    while(str[index]!='\0'){
        str[index++]=str[i++];
    }
    str[index]='\0';
    printf("%s",str);

    return 0;
}
```
### remove all space
```c


#include <stdio.h>
#include<string.h>
int main()
{
    char str[100];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }int i=0;int j=0;
    while(str[i]!='\0'){
        if(str[i]!=' '){
            str[j++]=str[i];
        }
        i++;
    }
    str[j]='\0';
    
    printf("%s",str);

    return 0;
}
```



























  
    

  
    



    











