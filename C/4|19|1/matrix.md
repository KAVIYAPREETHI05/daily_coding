##  part II
### Rotate matrix elements clockwise
```c
#include <stdio.h>

void rotateMatrix(int M, int N, int mat[M][N]) {
    int top = 0, bottom = M - 1, left = 0, right = N - 1;

    while (top < bottom && left < right) {
        int temp = 0, num = mat[top + 1][left];

        // Rotate top row
        for (int i = left; i <= right; i++) {
            temp = mat[top][i];
            mat[top][i] = num;
            num = temp;
        }
        top++;

        // Rotate right column
        for (int i = top; i <= bottom; i++) {
            temp = mat[i][right];
            mat[i][right] = num;
            num = temp;
        }
        right--;

        // Rotate bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                temp = mat[bottom][i];
                mat[bottom][i] = num;
                num = temp;
            }
            bottom--;
        }

        // Rotate left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                temp = mat[i][left];
                mat[i][left] = num;
                num = temp;
            }
            left++;
        }
    }
}

void printMatrix(int M, int N, int mat[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
```
### sorted matrix
```c
int compare(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
    int** sortedMatrix(int N, int mat[N][N]) {
        
        int m=N*N;
        int * arr=(int*)malloc(m*sizeof(int));
        int k=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                arr[k++]=mat[i][j];
            }
        }
        qsort(arr,k,sizeof(int),compare);
        for(int i=0;i<k;i++){
            mat[i/col][i%col]=arr[i];
        }
        free(arr);
        return mat;
    }
```
### Rotate a Rectangular Image by 90 Degree Clockwise

```c
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int N, int** mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void rotate90Matrix(int N, int mat[N][N]) {
    int m = N * N;
    int** arr = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(N * sizeof(int));
    }
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[j][N-1-i] = mat[i][j];
        }
    }
    printf("rotated matrix:\n");
    printMatrix(N, arr);
    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr); // Free allocated memory for arr
}
int main() {
    int N = 3;
    int mat[3][3] = {
        {1,2,3},
        {5,6,7},
        {9,10,11}
    };
    rotate90Matrix(N, mat);
    return 0;
}
```
### multiply two matrices
```c
#include <stdio.h>
#include<stdlib.h>
void multiply(int n,int m,int mat[n][m],int mat2[n][m]){
    int** matrix=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
            matrix[i]=(int *)malloc(m*sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
        matrix[i][k]=0;
        for(int j=0;j<m;j++){
            matrix[i][k]+=mat[i][j]*mat2[j][i];
        }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n=2;int m=2;
   int mat[2][2]={{1,1},{2,2}};
   int mat2[2][2]={{1,1},{2,2}};
   multiply(n,m,mat,mat2);

    return 0;
}
```
### Find maximum element of each row in a matrix

```c
#include <stdio.h>
#include<stdlib.h>
void multiply(int n,int m,int mat[n][m]){
   
    for(int i=0;i<n;i++){
       int max=mat[i][0];
        for(int j=0;j<m;j++){
            if(mat[i][j]>max){
                max=mat[i][j];
            }
        }
        printf("%d\n",max);
    }
}
int main() {
    int n=2;int m=2;
   int mat[2][2]={{1,4},{6,2}};

   multiply(n,m,mat);

    return 0;
}
```
### Count all sorted rows in a matrix
```c
#include <stdio.h>
#include<stdlib.h>
void multiply(int n,int m,int mat[n][m]){
  int count=0;
    for(int i=0;i<n;i++){
         int isAscending=1;
        for(int j=0;j<m-1;j++){
            if(mat[i][j]>mat[i][j+1]){
                isAscending=0;
                break;
            }
        }
        if(isAscending==1){
            count++;
        }
     
    }
    for(int i=0;i<n;i++){
        int isDescending=1;
        for(int j=0;j<m-1;j++){
            if(mat[i][j]<mat[i][j+1]){
                 isDescending=0;
                break;
            }
        }
        if( isDescending==1){
            count++;
        }
    }
       printf("%d\n",count);
}
int main() {
    int n=4;int m=5;
   int mat[4][5]={{1, 2, 3, 4, 5},
                  {  4, 3, 1, 2, 6},
                    {8, 7, 6, 5, 4},
                    {5, 7, 8, 9, 10}};

   multiply(n,m,mat);

    return 0;
}

```
### snake pattern
```c
#include <stdio.h>
#include<stdlib.h>
void multiply(int n,int m,int mat[n][m]){

    for(int i=0;i<n;i=i+2){
        for(int j=0;j<m;j++){
            printf("%d ",mat[i][j]);

        }
        for(int l=m-1;l>=0;l--){
            printf("%d ",mat[i+1][l]);
         }
    }
}
int main() {
    int n=4;int m=4;
   int mat[4][4]={ {10, 20, 30, 40},
                            {15, 25, 35, 45},
                           {27, 29, 37, 48},
                           {32, 33, 39, 50}};
   multiply(n,m,mat);
    return 0;
}

```
### Sort a Matrix in all way increasing order
```c
#include <stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b){
    return *(int*)a- *(int*)b;
}
void multiply(int n,int m,int mat[n][m]){
    int l=n*m;
    int *temp=(int*)malloc(l*sizeof(int));
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[k++]=mat[i][j];
        }
        }
        qsort(temp,k,sizeof(int),compare);
        k=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[i][j]=temp[k++];
             printf("%d ",mat[i][j]);
        }
        }
        
}
int main() {
    int n=4;int m=4;
   int mat[4][4]={ {10, 20, 30, 40},
                            {15, 25, 35, 45},
                           {27, 29, 37, 48},
                           {32, 33, 39, 50}};
   multiply(n,m,mat);
    return 0;
}
```
### Find the row with maximum number of 1s
```c
#include <stdio.h>
#include<stdlib.h>

void multiply(int n,int m,int mat[n][m]){
 int rowCount=0;int row=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=m-1;j>=0;j--){
            if(mat[i][j]==0){
                break;
            }
            else{
                count++;
            }
        }
        if(count>rowCount){
            rowCount=count;
            row=i;
        }
        }
       if (row != -1) {
        printf("Row %d has the maximum consecutive 1s, count = %d\n", row, rowCount);
    } else {
        printf("No row with 1s found\n");
    }
}
int main() {
    int n=4;int m=4;
   int mat[4][4]={ {0,1,1,1},
                            {0,0,1,1},
                           {0,1,1,1},
                           {1,1,1,1}};
   multiply(n,m,mat);
    return 0;
}
```
### Efficiently compute sums of diagonals of a matrix
```c
#include <stdio.h>
#include<stdlib.h>

void multiply(int n,int m,int mat[n][m]){
 int primarySum=0;int secondarySum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                primarySum+=mat[i][j];
            }
            if((i+j)==(n-1)){
                secondarySum+=mat[i][j];
            }
      }
    }
    printf("%d ",primarySum);
    printf("%d ",secondarySum);
}
int main() {
    int n=4;int m=4;
   int mat[4][4]= { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 }, 
                      { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 } };
   multiply(n,m,mat);
    return 0;
}
```



