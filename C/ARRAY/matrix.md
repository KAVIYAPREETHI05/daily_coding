### get input and print matrix
```c
#include<stdio.h>
int main(){
    int row=3;
    int col=3;
    int arr[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    

}
}
```
### add two matrics
```c
#include<stdio.h>
int main(){
    int row=3;
    int col=3;
    int arr[][3]={{1,2,3},{1,2,3},1,1,1};
    int brr[][3]={{1,1,1},{1,1,1},1,1,1};
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",arr[i][j]+brr[i][j]);
        }
        printf("\n");
}
}
```
```
2 3 4 
2 3 4 
2 2 2
```
### matrix multiplication
```c
#include<stdio.h>
int main(){
    int row1=3;
    int row2=3;
    int col1=3;
    int col2=4;
    int arr[][3]={{1,2,3},{1,2,3},1,1,1};
    int brr[][4]={{1,1,1,2},{1,1,1,1},{1,1,1,0}};
    int result[3][4]={0};
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
             result[i][j]=0;
            for(int k=0;k<col1;k++){
                result[i][j]+=arr[i][k]*brr[k][j];
            }
            printf("%d ",result[i][j]);
        }
        printf("\n");
}
}
```
```
6 6 6 4 
6 6 6 4 
3 3 3 3
```
### transpose matrix
```c
#include<stdio.h>
int main(){
    int row1=3;
    int col1=3;
    int arr[][3]={{1,2,3},{1,2,3},1,1,1};
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            printf("%d ",arr[j][i]);
        }
        printf("\n");
}
}
```
```
1 1 1 
2 2 1 
3 3 1 
```
### sum diagonal
```c
#include<stdio.h>
int main(){
    int size=3;
    int arr[3][3]={{1,2,3},{1,2,3},1,1,1};
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i][i]; //main diagonal
        sum+=arr[i][size-i-1]; //minor diagonal    
        }
        if(size%2!=0){
            sum-=arr[size/2][size/2];
        }
        printf("%d",sum);
}
```
### interchange diagonals
```c
#include <stdio.h>
int main()
{
int size=3;
int m[][3]={{1,2,3},{4,5,6},{7,8,9}};
for(int i=0;i<size;i++){
    int temp=m[i][i];
    m[i][i]=m[i][size-i-1];
    m[i][size-i-1]=temp;
}
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        printf("%d ",m[i][j]);
    }
    printf("\n");
}

    return 0;
}
```
```
1 2 3      3 2 1
4 5 6      4 5 6
7 8 9      9 8 7
```
### check symmetric 
Symmetric matrix is a square matrix which is equal to its transpose. A symmetric matrix is always a square matrix. Symmetric matrix A is defined as – A = AT
```c
#include<stdio.h>
int main(){
    int size=3;
    int arr[3][3]={{1,2,3},{2,0,6},3,6,1};
    int found=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
        if(arr[i][j]!=arr[j][i]){
            found=1;
            break;
        }
        }
        if(found){
            break;
        }
        }
        if(found){
            printf("not symmetric");
        }
        else{
            printf("symmetric");
        }
        
}
```
```
symmetric
```
###  check identity
Identity matrix is a special square matrix whose main diagonal elements is equal to 1 and other elements are 0. Identity matrix is also known as unit matrix.
```c
#include<stdio.h>
int main(){
    int size=3;
    int arr[3][3]={{1,0,0},{0,1,0},0,0,1};
    int found=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
        if((i==j && arr[i][j]!=1) || (i!=j && arr[i][j]!=0))  {
            found=1;
            break;
        }
        }
        if(found){
            break;
        }
        }
        if(found){
            printf("not identity");
        }
        else{
            printf("identity");
        }
        
}
```
```
identity
```
### check sparse
```
#include <stdio.h>
int main()
{
int r1=3;
int c1=3;
int m[][3]={{1,6,0},{0,0,0},{4,0,5}};
int count=0;
for(int i=0;i<r1;i++){
 for(int j=0;j<c1;j++){
     if(m[i][j]==0){
         count++;
     }
 }  
}
if(count>=((r1*c1)/2)){
    printf("yes sparse matrix");
}
else{
    printf("no, not sparse matrix");
}

    return 0;
}
```
```
yes sparse matrix
```
### sum of rows&cols
```c
#include<stdio.h>
int main(){
    int row=3;
    int col=4;
    int arr[3][4]={{1,0,0,1},{0,1,0,3},0,0,1,2};
    for(int i=0;i<row;i++){
            int rowsum=0;
        for(int j=0;j<col;j++){
            rowsum+=arr[i][j];
        }
        printf("%d ",rowsum);
        }
        printf("\n");
        for(int j=0;j<col;j++){
                    int colsum=0;
            for(int i=0;i<row;i++){
                colsum+=arr[i][j];
            }
            printf("%d ",colsum);
        }
        
}
```
```
2 4 3 
1 1 1 6
```
### max element in row and col
```c
#include<stdio.h>
int main(){
    int row=3;
    int col=4;
    int arr[3][4]={{1,0,0,1},{0,1,0,3},0,0,1,2};
    for(int i=0;i<row;i++){
        int maxrow=arr[i][0];
        for(int j=0;j<col;j++){
            if(arr[i][j]>maxrow){
                maxrow=arr[i][j];
            }
        }
        printf("%d ",maxrow);
        }
        printf("\n");
        for(int j=0;j<col;j++){
                    int maxcol=arr[0][j];
            for(int i=0;i<row;i++){
                if(arr[i][j]>maxcol){
                    maxcol=arr[i][j];
                }
            }
            printf("%d ",maxcol);
        }
        
}
```
```
1 3 2 
1 1 1 3 
```
### upper triangular matrix
Upper triangular matrix is a special square matrix whose all elements below main diagonal is zero.


```c
#include <stdio.h>
int main()
{
int r1=3;
int c1=3;
int m[][3]={{1,2,3},{4,5,6},{7,8,9}};
for(int i=0;i<r1;i++){
 for(int j=0;j<c1;j++){
     if(j<i){
         m[i][j]=0;
     }
 }  
}
for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
        printf("%d ",m[i][j]);
    }
    printf("\n");
}

    return 0;
}
```
```
1 2 3 
0 5 6 
0 0 9
```
### lower triangular matrix
Lower triangular matrix is a special square matrix whose all elements above main diagonal is zero.


```c
#include <stdio.h>
int main()
{
int r1=3;
int c1=3;
int m[][3]={{1,2,3},{4,5,6},{7,8,9}};
for(int i=0;i<r1;i++){
 for(int j=0;j<c1;j++){
     if(j>i){
         m[i][j]=0;
     }
 }  
}
for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
        printf("%d ",m[i][j]);
    }
    printf("\n");
}

    return 0;
}
```
```
1 0 0 
4 5 0 
7 8 9 
```
### sum of lower triangular matrix
```c
#include <stdio.h>
int main()
{
int r1=3;
int c1=3;
int m[][3]={{1,2,3},{4,5,6},{7,8,9}};
int sum=0;
for(int i=0;i<r1;i++){
 for(int j=0;j<c1;j++){
     if(j<i){
         sum+=m[i][j];
     }
 }  
}


printf("%d",sum);

    return 0;
}
//19
```
### sum of upper triangular matrix
```c
#include <stdio.h>
int main()
{
int r1=3;
int c1=3;
int m[][3]={{1,2,3},{4,5,6},{7,8,9}};
int sum=0;
for(int i=0;i<r1;i++){
 for(int j=0;j<c1;j++){
     if(j>i){
         sum+=m[i][j];
     }
 }  
}


printf("%d",sum);

    return 0;
}
// 11
```
### determinant of matrix
```c
#include <stdio.h>
int main()
{
int r1=3;
int c1=3;
int m[][3]={{6,1,1},{4,-2,5},{2,8,7}};

int a,b,c,d,e,f,g,h,i;
a=m[0][0];
b=m[0][1];
c=m[0][2];
d=m[1][0];
e=m[1][1];
f=m[1][2];
g=m[2][0];
h=m[2][1];
i=m[2][2];
long determinant=((a*(e*i - f*h)) - (b*(d*i - g*f)) + (c*(d*h - e*g)));
printf("%ld",determinant);

    return 0;
}
```

