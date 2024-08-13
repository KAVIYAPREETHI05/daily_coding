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
###

