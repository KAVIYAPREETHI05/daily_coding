### GET INPUT WITHOUT SIZE OF ARRAY

```c
#include <stdio.h>
#include<string.h>
#define max 100

int main() {
    char temp[max];
    
    fgets(temp,sizeof(temp),stdin);
    temp[strcspn(temp,"\n")]='\0';
    int n=strlen(temp);
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=temp[i]-'0';
    }
    
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
   
    

    return 0;
}
```
### REVERSE STRING

```c
#include <stdio.h>
#include<string.h>
#define max 100

int main() {
   char str[max];
   fgets(str,sizeof(str),stdin);
   str[strcspn(str,"\n")]='\0';
   
   int n=strlen(str);
   char arr[n];
   for(int i=0;i<n;i++){
       arr[i]=str[i];
       
   }
   
   for(int i=0;i<n/2;i++){
       char temp=arr[i];
       arr[i]=arr[n-1-i];
       arr[n-1-i]=temp;
   }
   
   for(int i=0;i<n;i++){
       printf("%c ",arr[i]);
   }
  
    

    return 0;
}
```

### REVERSE VOWELS OF STRING

```c
#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#define max 100

bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' ||c=='o' ||c=='u' || c=='A' || c=='E' || c=='I' ||c=='O' ||c=='U' ){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    char str[max];
    
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    
    int n=strlen(str);
    
    int start=0;int end=n-1;
    
    while(start<end){
        if(isVowel(str[start]) && isVowel(str[end])){
            char temp=str[start];
            str[start]=str[end];
            str[end]=temp;
            start++;
            end--;
        }
        else if(!isVowel(str[start])){
            start++;
        }
        else if(!isVowel(str[end])){
            end--;
        }
    }
    
    printf("%s",str);

    return 0;
}
```

### VALID PALINDROME

```c
#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#include<ctype.h>
#define max 100

bool isletter(char c){
    if((c>='a' && c<='z') ||(c>='A' &&c<='Z') ){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    char str[max];
    
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    char temp[max];
    
    int n=strlen(str);
    int j=0;
    for(int i=0;i<n;i++){
        if(isletter(str[i])){
            temp[j++]=tolower(str[i]);
        }
    }
    temp[j]='\0';
    
    printf("%s",temp);
    
    bool palin=true;
    for(int i=0;i<strlen(temp)/2;i++){
        if(temp[i]!=temp[strlen(temp)-1-i]){
            palin=false;
            break;
            
        }
    }
    if(palin){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}
```
