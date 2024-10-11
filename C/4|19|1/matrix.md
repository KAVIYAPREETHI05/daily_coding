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
