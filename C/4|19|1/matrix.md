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
