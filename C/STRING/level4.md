### check char occurs in string
```c
#include <stdio.h>

int main() {
   char str[100];
   fgets(str,sizeof(str),stdin);
   char letter;
   int count=0;
   scanf("%c",&letter);
   for(int i=0;str[i]!='\0';i++){
       if(str[i]==letter){
           count++;
       }
   }
   printf("%c occurs %d times",letter,count);

    return 0;
}
```
###
```c
#include <stdio.h>
#include<string.h>
int main() {
   char str[100];
   fgets(str,sizeof(str),stdin);
   char phone[11]={0};
   char gender[2]={0};
   char age[3]={0};
   char seat[3]={0};
   int i=0;
   strncpy(phone,str,10);
   strncpy(gender,str+10,1);
   strncpy(age,str+12,2);
   strncpy(seat,str+13,2);
   
   printf("%s\n",phone);
printf("%s\n",gender);
printf("%s\n",age);
printf("%s\n",seat);
    return 0;
}
```
### most occurrence char
```c
#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
   char str[100];
   char temp[26];
   fgets(str,sizeof(str),stdin);
  for(int i=0;str[i]!='\0';i++){
      char letter=tolower(str[i]);
     if(letter>='a' && letter<='z'){
          temp[letter-'a']++;
     }
      }int max=0;
  char maxchar=' ';
   for(int i=0;i<26;i++){
      if(temp[i]>max){
          max=str[i];
          maxchar=i+'a';
      }
  }
  printf("%c occurs mostly",maxchar);
        return 0;
}
```
### first non-repeating
```c
#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
   char str[100];
   int temp[255]={0};
   fgets(str,sizeof(str),stdin);
  for(int i=0;str[i]!='\0';i++){
     
          temp[(unsigned char)str[i]]++;
     
      }
  char maxchar=' ';
   for(int i=0;str[i] != '\0';i++){
      if(temp[(unsigned char)str[i]]==1){
           maxchar=str[i];
           break;
      }
  }
  printf("%c first non-repeating",maxchar);
        return 0;
}
```
### reverse word
```c
#include <stdio.h>
#include<string.h>
int main() {
    
    char str[255];
    fgets(str,sizeof(str),stdin);
    char reverse[255];
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }int j=0;int start;int end=n-1;
    for(int i=n-1;i>=0;i--){
        if(str[i]==' '){
            start=i+1;
            for(int i=start;i<=end;i++){
                reverse[j++]=str[i];
            }
            end=i-1;
            reverse[j++]=' ';
        }
    }
    for(int i=0;i<=end;i++){
        reverse[j++]=str[i];
    }
    reverse[j]='\0';
    printf("%s",reverse);
    

    return 0;
}
```
### longest word
```c
#include <stdio.h>
#include <string.h>
#define MAX_STRINGS 100
#define MAX_LENGTH 100

int main(){
    int num_strings;
    char str[MAX_STRINGS][MAX_LENGTH];
    int max_len=0;
    int longest_index=0;
    scanf("%d",&num_strings);
    getchar();
    for(int i=0;i<num_strings;i++){
        fgets(str[i],MAX_LENGTH,stdin);
        int len=strlen(str[i]);
        if(len>0 && str[i][len-1]=='\n'){
            str[i][len-1]='\0';
            len--;
        }
        if(len>max_len){
            max_len=len;
            longest_index=i;
        }
    }
printf("%s\n longest word",str[longest_index]);
printf("%d index of longest word",max_len);
    return 0;
}
```
### second longest word
```c
#include <stdio.h>
#include <string.h>

int main() {
    int elements;
    scanf("%d", &elements);
    getchar();  
    char str[elements][100];
    for (int i = 0; i < elements; i++) {
        fgets(str[i], sizeof(str[i]), stdin);
        int n = strlen(str[i]);
        if (str[i][n-1] == '\n') {
            str[i][n-1] = '\0';
        }
    }
    int max = 0;
    int sec_max = -1;
    for (int i = 1; i < elements; i++) {
        if (strlen(str[i]) > strlen(str[max])) {
            sec_max = max;
            max = i;
        } else if (strlen(str[i]) <= strlen(str[max]) && (sec_max == -1 || strlen(str[i]) > strlen(str[sec_max]))) {
            sec_max = i;
        }
    }
    printf("%s\n", str[max]);
    if (sec_max != -1) {
        printf("Second Longest: %s\n", str[sec_max]);
    } else {
        printf("No second longest string exists.\n");
    }
    return 0;
}

```
### remove leading zeros and check whether both string are equal
```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 256
char* removeLeadingZeros(char* str){
    while(*str=='0' && *(str+1)!='\0'){
        str++;
    }
    return str;
}
int main(){
    char str1[MAX];
    char str2[MAX];
    scanf("%s",str1);
    scanf("%s",str2);
    char* num1=removeLeadingZeros(str1);
    char* num2=removeLeadingZeros(str2);
    if(strcmp(num1,num2)==0){
        printf("they are equal %s and %s",num1,num2);
    }
    else{
       printf("they are not equal %s and %s",num1,num2); 
    }
    
}
```
### remove duplicate 
```c
#include<stdio.h>
#include<string.h>
#define MAX 256
int main(){
    char str[MAX];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    int temp[MAX]={0};char unique[MAX];int j=0;
    for(int i=0;i<n;i++){
        if(temp[(unsigned char)str[i]]==0){
            temp[(unsigned char)str[i]]=1;
            unique[j++]=str[i];
        }
    }
    unique[j]='\0';
    printf("%s",unique);
    
}
```
### remove vowel and print
```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 256
int main(){
    char str[MAX];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    char unique[MAX];int j=0;
    for(int i=0;i<n;i++){
        char s=tolower((unsigned char)str[i]);
        if(s!='a' && s!='e' && s!='i' && s!='o' && s!='u'){
            unique[j++]=s;
        }
    }
    unique[j]='\0';
    printf("%s",unique);
    
}
```
### print consecutive repeated characters
```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 256
int main(){
    char str[MAX];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    char unique[MAX];int j=0;
    for(int i=0;i<n;i++){
       
        if(str[i]==str[i+1]){
            unique[j++]=str[i];
            while(str[i]==str[i+1]){
                i++;
            }
        }
    }
    unique[j]='\0';
    printf("%s",unique);
    
}
```
### check isomorphic
```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 256
int areIsomorphic(char* str1,char* str2){
    int m1[MAX]={0};
    int m2[MAX]={0};
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len1!=len2){
        return 0;
    }
    for(int i=0;i<len1;i++){
        int c1=(unsigned char)str1[i];
        int c2=(unsigned char)str2[i];
        if(m1[c1]==0 && m2[c2]==0){
            m1[c1]=c2;
            m2[c2]=c1;
        }
        else{
            if(m1[c1]!=c2 || m2[c2]!=c1){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    char str1[MAX];char str2[MAX];
    fgets(str1,sizeof(str1),stdin);
    fgets(str2,sizeof(str2),stdin);
    
   str1[strcspn(str1,"\n")]='\0';
   str2[strcspn(str2,"\n")]='\0';
    
    if(areIsomorphic(str1,str2)){
        printf("%s and  %s are isomorphic",str1,str2);
    }
    else{
        printf(" %s and  %s are not isomorphic",str1,str2);
    }
}
```
### anagrams
```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 256
int areAnagrams(char* str1,char* str2){
    int count[MAX]={0};
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len1!=len2){
        return 0;
    }
    for(int i=0;i<len1;i++){
        count[(unsigned char)str1[i]]++;
        count[(unsigned char)str2[i]]--;
            }
            for(int i=0;i<MAX;i++){
                if(count[i]!=0){
                    return 0;
                }
            }
            
    return 1;
}
int main(){
    char str1[MAX];char str2[MAX];
    fgets(str1,sizeof(str1),stdin);
    fgets(str2,sizeof(str2),stdin);
    
   str1[strcspn(str1,"\n")]='\0';
   str2[strcspn(str2,"\n")]='\0';
    
    if(areAnagrams(str1,str2)){
        printf("%s and  %s are anagrams",str1,str2);
    }
    else{
        printf(" %s and  %s are not anagrams",str1,str2);
    }
}
```
### check pangram
```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 26
int isPangram(char* str){
    int count[MAX]={0};
    int len1=strlen(str);
    int i=0;
    while(str[i]!='\0'){
          char s=tolower((unsigned char)str[i]);
          if(s>='a' && s<='z'){
             int  index= s - 'a';
              count[index]=1;
          }
          i++;
    }
     for(int i=0;i<MAX;i++){
         if(count[i]==0){
             return 0;
         }
     }
    return 1;
}
int main(){
    char str1[MAX];char str2[MAX];
    fgets(str1,sizeof(str1),stdin);
     str1[strcspn(str1,"\n")]='\0';
  
    if(!isPangram(str1)){
        printf("string is pangram");
    }
    else{
        printf(" string is not pangram");
    }
}
```



