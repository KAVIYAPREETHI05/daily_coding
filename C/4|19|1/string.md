### Reverse words
```c
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

  void reverseWords(char* str) {
        int len=strlen(str);
        int end=len-1;
        for(int i=len-1;i>=0;i--){
            if(str[i]=='.'){
                int start=i+1; 
                while(start<=end){
                    printf("%c",str[start]);
                    start++;
                    
                }
                printf(".");
                end=i-1;
                
            }
        }
        
        for(int i=0;i<=end;i++){
            printf("%c",str[i]);
        }
    }

int main() {
    
    char str[256];
    fgets(str,sizeof(str),stdin);
    int len=strlen(str);

    if(str[len-1]=='\n'){
        str[len-1]='\0';
    }
    
    reverseWords(str);
  

    return 0;
}
//Validation in Data Entry and encryption
```
