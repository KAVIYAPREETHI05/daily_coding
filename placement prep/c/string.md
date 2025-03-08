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
