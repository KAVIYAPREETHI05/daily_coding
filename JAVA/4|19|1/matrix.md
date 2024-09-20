### Rotate matrix elements clockwise
```java

class Solution {
    int[][] rotateMatrix(int M, int N, int mat[][]) {
        int top = 0, bottom = M - 1, left = 0, right = N - 1;

        while (top < bottom && left < right) {
            int prev=mat[top+1][left];
            
            for(int i=left;i<=right;i++){
                int temp=mat[top][i];
                mat[top][i]=prev;
                prev=temp;
            }
            top++;
             for(int i=top;i<=bottom;i++){
                int temp=mat[i][right];
                mat[i][right]=prev;
                prev=temp;
            }
            right--;
             if(top<=bottom){
                 for(int i=right;i>=left;i--){
                int temp=mat[bottom][i];
                mat[bottom][i]=prev;
                prev=temp;
            }
            bottom--;
             }
            if(left<=right){
                 for(int i=bottom;i>=top;i--){
                int temp=mat[i][left];
                mat[i][left]=prev;
                prev=temp;
            }
            left++;
            
        }
            }
        
        return mat; 
}
}
// robot navigation and image rotation
```
