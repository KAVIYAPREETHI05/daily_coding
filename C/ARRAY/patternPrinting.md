### Right half pyramid
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    for(int i=0;i<rows;i++){
        for(int j=0;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
}
```
```
* 
* * 
* * * 
* * * * 
* * * * *
```
### Inverted right half pyramid
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    for(int i=0;i<rows;i++){
        for(int j=5;j>i;j--){
            printf("* ");
        }
        printf("\n");
    }
}
```
```
* * * * * 
* * * * 
* * * 
* * 
*
```
### left half pyramid
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    for(int i=0;i<rows;i++){
        for(int k=0;k<2*(rows-i)-1;k++){
            printf(" ");
        }
        for(int j=0;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
}
```
```
         * 
       * * 
     * * * 
   * * * * 
 * * * * *
```
###  Inverted left half pyramid
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    for(int i=rows;i>=0;i--){
        for(int k=0;k<2*(rows-i);k++){
            printf(" ");
        }
        for(int j=0;j<i;j++){
            printf("* ");
        }
        printf("\n");
    }
}
```
```
* * * * * 
  * * * * 
    * * * 
      * * 
        *
```
### full pyramid
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    for(int i=0;i<rows;i++){
        for(int k=0;k<2*(rows-i)-1;k++){
            printf(" ");
        }
        for(int j=0;j<2*i+1;j++){
            printf("* ");
        }
        printf("\n");
    }
}
```
```
         * 
       * * * 
     * * * * * 
   * * * * * * * 
 * * * * * * * * *
```
### inverted full pyramid
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    for(int i=rows;i>=0;i--){
        for(int k=0;k<2*(rows-i);k++){
            printf(" ");
        }
        for(int j=0;j<2*i-1;j++){
            printf("* ");
        }
        printf("\n");
    }
}
```
```
* * * * * * * * * 
  * * * * * * * 
    * * * * * 
      * * * 
        *
```
### rhombus
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    for(int i=0;i<rows;i++){
        for(int k=0;k<(rows-i)-1;k++){
            printf(" ");
        }
        for(int j=0;j<cols;j++){
            printf("* ");
        }
        printf("\n");
    }
}
```
```
    * * * * * 
   * * * * * 
  * * * * * 
 * * * * * 
* * * * *
```

