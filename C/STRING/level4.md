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


