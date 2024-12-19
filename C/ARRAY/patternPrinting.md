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
### hollow square
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i==0 || j==0 || i==rows-1 || j==cols-1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}
```
```
* * * * * 
*       * 
*       * 
*       * 
* * * * *
```
### hollow full pyramid
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
            if(j==0||j==2*i||i==rows-1)
               printf("* ");
             else
             printf("  ");
        }
        printf("\n");
    }
}
```
```
         * 
       *   * 
     *       * 
   *           * 
 * * * * * * * * *
```
### hollow inverted full pyramid
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    for(int i=rows;i>0;i--){
        for(int k=0;k<2*(rows-i);k++){
            printf(" ");
        }
        for(int j=0;j<2*i-1;j++){
            if(i==rows || j==0 || j==2*i-2 )
            printf("* ");
            else
            printf("  ");
        }
        printf("\n");
    }
}
```
```
* * * * * * * * * 
  *           * 
    *       * 
      *   * 
        *
```
### Floyd's triangle
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    int n=1;
    for(int i=0;i<rows;i++){
            for(int j=0;j<=i;j++){
            printf("%d ",n++);
        }
        printf("\n");
    }
}
```
```
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15
```
### pascal'c triangle
``time complexity-O(rows*rows)``
``space complexity-O(1)``
```c
#include<stdio.h>
int main(){
    int rows=5;
    int cols=5;
    for(int i=1;i<=rows;i++){
        for(int k=0;k<rows-i;k++){
            printf(" ");
        }
        int c=1;
            for(int j=1;j<=i;j++){
            printf("%d ",c);
            c=c*(i-j)/j;
        }
        printf("\n");
    }
}
```
```
    1 
   1 1 
  1 2 1 
 1 3 3 1 
1 4 6 4 1
```


```c
#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        if(i%2!=0){
            for(int j=1;j<=num;j++){
                printf("%d ",i);
            }
            printf("%d\n",i+1);
        }
        else{
             printf("%d ",i+1);
            for(int j=1;j<=num;j++){
                printf("%d ",i);
            }
            printf("\n");
        }
    }
    
    
}
```
```

1 1 1 1 1 1 2
3 2 2 2 2 2 2
3 3 3 3 3 3 4
5 4 4 4 4 4 4
5 5 5 5 5 5 6
6 6 6 6 6 6 7

```




