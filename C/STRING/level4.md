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
#define MAX_STRINGS 100
#define MAX_LENGTH 100

int main(){
    int num_strings;
    char str[MAX_STRINGS][MAX_LENGTH];
    int max_len=0;int sec_max=0;
    int longest_index=0; int sec_long=-1;
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
            sec_max=max_len;
            sec_long=longest_index;
            max_len=len;
            longest_index=i;
        }
        else if(len>sec_max && len<max_len){
            sec_max=len;
            sec_long=i;
        }
    }
printf("%s\n longest word",str[sec_long]);
printf("%d index of longest word",sec_max);
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
#define NUM 256
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
    char str1[NUM];
    fgets(str1,sizeof(str1),stdin);
     str1[strcspn(str1,"\n")]='\0';
  
    if(isPangram(str1)){
        printf("string is pangram");
    }
    else{
        printf(" string is not pangram");
    }
}
```
### FREQUENCY OF THE FIRST REPEATING CHARACTER
```c
#include<stdio.h>
#include<string.h>
#define MAX 256
int freqRepeating(char *str){
    char temp[MAX]={0};
    for(int i=0;str[i]!='\0';i++){
        temp[(unsigned char)str[i]]++;
    }
    for(int i=0;str[i]!='\0';i++){
        if(temp[(unsigned char)str[i]]>1){
            printf("%c\n",str[i]);
            return temp[(unsigned char)str[i]];
        }
    }
    return 0;
}
int main(){
    char str[MAX];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    int n=strlen(str);
        int count=freqRepeating(str);
    if(count){
        printf("frequency of first repeating char is %d",count);
    }
    else{
        printf("no repeating");
    }
    
}
```
### age greater than 60 in given string
```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 256
int freqRepeating(char *str){
    char *token;
    token=strtok(str," ");
    int count=0;
    while(token!=NULL){
        int age=atoi(token);
        if(age>60){
            count++;
        }
        token=strtok(NULL," ");
    }
    return count;
}
int main(){
    char str[MAX];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    int n=strlen(str);
        int count=freqRepeating(str);
    if(count){
        printf("age greater than 60 is  %d",count);
    }
    else{
        printf("no one");
    }
    
}
```
### Print the given string without alphabets
```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 256

int main(){
    char str[MAX];char temp[MAX];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    int n=strlen(str);int i=0;int j=0;
        while(str[i]!='\0'){
            if(!isalpha(str[i])){
                temp[j++]=str[i];
            }
            i++;
        }
        temp[j]='\0';
        printf("%s",temp);
}
```
### Replace character with input character
```c
#include<stdio.h>
#include<string.h>
#define MAX 256
int main(){
    char str[MAX]; char letter;char replace;
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);n=n-1;
    scanf(" %c",&letter);
    scanf(" %c",&replace);
    for(int i=0;i<n;i++){
        if(str[i]==letter){
            str[i]=replace;
        }
    }
    printf("%s",str);
    
}
```
### reverse the word
```c
#include<stdio.h>
#include<string.h>
#define MAX 256
int main(){
    char str[MAX]; char reverse[MAX];
    fgets(str,sizeof(str),stdin);
    int n=strlen(str);
    if(str[n-1]=='\n'){
        str[n-1]='\0';
        n--;
    }
    int end=n-1;int j=0;
    for(int i=end;i>=0;i--){
        if(str[i]==' ' && str[i+1]!=' '){
            int start=i+1;
            while(start<=end){
                reverse[j++]=str[start];
                start++;
            }
            reverse[j++]=' ';
            end=i-1;
        }
    }
    for(int i=0;i<=end;i++){
        reverse[j++]=str[i];
    }
    reverse[j]='\0';
    
    printf("%s",reverse);
    
}
```
### unique char
```c
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 256
int main(){
char str[MAX_LENGTH];char reverse[MAX_LENGTH];
fgets(str,sizeof(str),stdin);
int n=strlen(str);
if(str[n-1]=='\n'){
    str[n-1]='\0';
    n--;
}int j=0;
int count[MAX_LENGTH]={0};
for(int i=0;i<n;i++){
    count[(unsigned char)str[i]]++;
    if(count[(unsigned char)str[i]]==1){
        reverse[j++]=str[i];
    }
}
reverse[j]='\0';
printf("%s",reverse);


    return 0;
}
```
### reverse string and print odd index char
```c
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 256
int main(){
char str[MAX_LENGTH];char reverse[MAX_LENGTH];
fgets(str,sizeof(str),stdin);
int n=strlen(str);
if(str[n-1]=='\n'){
    str[n-1]='\0';
    n--;
}int j=0;
for(int i=n-1;i>=0;i--){
    reverse[j++]=str[i];
}
reverse[j]='\0';
for(int i=0;reverse[i]!='\0';i++){
    if(i%2!=0){
        printf("%c",reverse[i]);
    }
}
    
    return 0;
}
```
### remove word and print sentence
```c
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 256
void removeWord(char *sentence, const char *word) {

    char result[MAX_LENGTH]="";
    char *token;
    token=strtok(sentence," ");
    while(token!=NULL){
        if(strcmp(token,word)!=0){
            if(strlen(result)>0){
                strcat(result," ");
            }
            strcat(result,token);
        }
        token=strtok(NULL," ");
    }
    strcpy(sentence,result);
    
}
int main() {
    char sentence[256];
    char word[50];

     fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; 
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0'; 
    removeWord(sentence, word);
    printf("Modified sentence: %s\n", sentence);

    return 0;
}
```
### find the first non repeating character
```c
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 256

int main() {
    char sentence[256];
    char word[50];
     fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; 
    int result[MAX_LENGTH]={0};
    for(int i=0;sentence[i]!='\0';i++){
        result[(unsigned char) sentence[i]]++;
    }
    for(int i=0;sentence[i]!='\0';i++){
        if(result[(unsigned char) sentence[i]]==1){
            printf("%c",sentence[i]);
            break;
        }
    }
    return 0;
}
```
### Count the number of alphabets in the string. Then find the count is prime number or even or odd 
```c
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#define MAX_LENGTH 256
int isprime(int n){
    if(n<=1){
        return 0;
    }
    else{
        for(int i=2;i<n/2;i++){
            if(n%i==0){
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char sentence[256];
    char word[50];
     fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; 
    int result[MAX_LENGTH]={0};
    int count=0;
    for(int i=0;sentence[i]!='\0';i++){
        if(isalpha(sentence[i])){
            count++;
        }
    }
    printf("%d",count);
    if(isprime(count)){
        printf("prime number");
    }
   else if(count%2==0){
       printf("even number");
   }
   else if(count%2!=0){
       printf("odd number");
       
   }
   
    return 0;
}
```
### GET A STRING AS INPUT AND SUM THE NUMBERS PRESENT IN STRING. REVERSE THE SUM.
```c
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#define MAX_LENGTH 256
void reverse(int n){
    int reversed=0;
    while(n!=0){
        int digit=n%10;
        reversed= reversed*10+digit;
        n/=10;
    }
    printf("%d",reversed);
}

int main() {
    char sentence[256];
    char word[50];
     fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; 
    int sum=0;
    for(int i=0;sentence[i]!='\0';i++){
        if(isdigit(sentence[i])){
            sum+=sentence[i] -'0';
        }
    }
    printf("%d\n",sum);
    reverse(sum);
   
    return 0;
}
```
### check time
```c
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#define MAX_LENGTH 256
void checkTime(char * str){
    int mins;int hrs;int sec;
    if(sscanf(str,"%d:%d:%d",&hrs,&mins,&sec)!=3){
       printf("Invalid time format");
    }
    if(hrs>=0 && hrs<=23 && mins>=0 && mins<=59 && sec>=0 && sec<=59){
          printf("%dHours:%dMinutes:%dSeconds",hrs,mins,sec);
    }
    else {
        printf("Invalid time");
    }
}

int main() {
    char sentence[256];
    char word[50];
     fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; 
  
checkTime(sentence);
   
    return 0;
}
```
### int to roman
```c
#include <stdio.h>
#include<string.h>
#include<ctype.h>
void inttoroman(int num,char*roman){
    int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *symbols[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int i=0;
    while(num>0){
        while(num>=values[i]){
            num-=values[i];
            strcat(roman,symbols[i]);
        }
        i++;
    }
}
int main() {
   int num;
   char roman[100];
   scanf("%d",&num);
   inttoroman(num,roman);
   printf("%s",roman);
}
```
### roman to int
```c
#include <stdio.h>
#include <string.h>

int romanToInt(char *roman) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    int i=0,num=0;
    while(*roman){
        int found=0;
        for(int i=0;i<13;i++){
            if(strncmp(roman,symbols[i],strlen(symbols[i]))==0){
            
                num+=values[i];
                roman+=strlen(symbols[i]);
                found=1;
                break;
            }
        }
         if(found==0){
        return -1;
    }
    }
   
    return num;
}

int main() {
    char roman[100];
    scanf("%s", roman);
    int result = romanToInt(roman);
    
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("Invalid Roman numeral\n");
    }
    
    return 0;
}

```


