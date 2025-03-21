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
### Spirally traversing a matrix
```java
class Solution {
    // Function to return a list of integers denoting spiral traversal of matrix.
    public ArrayList<Integer> spirallyTraverse(int matrix[][]) {
        ArrayList<Integer>temp=new ArrayList<>();
        int n=matrix.length;
        int m=matrix[0].length;
        int top=1;int bottom=n;int left=1;int right=m;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                temp.add(matrix[top-1][i-1]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                temp.add(matrix[i-1][right-1]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                temp.add(matrix[bottom-1][i-1]);
            }
            bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                temp.add(matrix[i-1][left-1]);
            }
            left++;
            }
            
            
            
        }
        return temp;
    }
}
//Spreadsheet Navigation
```
### Search in a row-column sorted Matrix
```java

class Solution 
{ 
	static boolean search(int matrix[][], int n, int m, int x) 
	{  
	    for(int i=0;i<n;i++){
	        int last_ele=matrix[i][m-1];
	        if(last_ele>x){
	            for(int j=0;j<m;j++){
	                if(matrix[i][j]==x){
	                    return true;
	                }
	            }
	        }
	        
	    }
	    return false;
	} 
}
```
### Maximum no of 1's row

```java

class Sol
{
    public static int maxOnes (int Mat[][], int n, int m)
    {
        int maxCount=0;
        int maxRow=-1;
        int j=m-1;
        for(int i=0;i<n;i++){
            
            while(j>=0 && Mat[i][j]==1){
                j--;
                
            }
            if(m-1-j>maxCount){
                maxCount=m-1-j;
            maxRow=i;
            }
        }
        
     return maxRow;   
        
}

}
```
### Median in a row-wise sorted Matrix
```java
class Solution {
    int median(int matrix[][], int R, int C) {
          int[] temp=new int[R*C];
          int index=0;
          for(int i=0;i<R;i++){
              for(int j=0;j<C;j++){
                  temp[index++]=matrix[i][j];
              }
          }
          
          Arrays.sort(temp);
          int n=temp.length;
          
      if(n%2==0){
          return (temp[n/2-1] + temp[n/2])/2;
      }
      else{
          return temp[n/2];
      }
    }
}
//traffic analysis & academic performance
```

## part II

### sorted matrix
```java
class Solution {
    int[][] sortedMatrix(int N, int mat[][]) {
        int row=mat.length;
        int col=mat[0].length;
        int m=row*col;
        int[] arr=new int[m];
        int k=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                arr[k++]=mat[i][j];
            }
        }
        Arrays.sort(arr);
        for(int i=0;i<k;i++){
            mat[i/col][i%col]=arr[i];
        }
        return mat;
    }
};
```

### Rotate a Rectangular Image by 90 Degree Clockwise
```java
public class RotateMatrix {
    // Function to print the matrix
    public static void printMatrix(int N, int[][] mat) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static void rotate90Matrix(int N, int[][] mat) {
        int[][] arr = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[j][N - 1 - i] = mat[i][j];
            }
        }
        System.out.println("Rotated matrix:");
        printMatrix(N, arr); 
    }

    public static void main(String[] args) {
        int N = 3;
        int[][] mat = {
            {1, 2, 3},
            {5, 6, 7},
            {9, 10, 11}
        };

        System.out.println("Original matrix:");
        printMatrix(N, mat);

        rotate90Matrix(N, mat);
    }
}

```
### multiply of two matrix
```java
import java.util.*;

class HelloWorld {
    static void multiply(int n,int m,int [][] mat,int [][]mat2){
    int[][] matrix=new int[n][m];
   
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

            System.out.print(matrix[i][j] );
        }
        System.out.print(" \n" );
    }
}
    public static void main(String[] args) {
    int n=2;int m=2;
   int mat[][]={{1,1},{2,2}};
   int mat2[][]={{1,1},{2,2}};
   multiply(n,m,mat,mat2);

}
    }
```
### Find maximum element of each row in a matrix
```java
import java.util.*;
class Main{
 static void multiply(int n,int m,int [][]mat){
   
    for(int i=0;i<n;i++){
       int max=mat[i][0];
        for(int j=0;j<m;j++){
            if(mat[i][j]>max){
                max=mat[i][j];
            }
        }
    System.out.println(max);
    }
}
public static void  main(String [] args) {
    int n=2;int m=2;
   int mat[][]={{1,4},{6,2}};

   multiply(n,m,mat);

}
}
```
### Count all sorted rows in a matrix
```java
import java.util.*;
class Main{
 static void multiply(int n,int m,int [][]mat){
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
       System.out.println(count);
}
public static void  main(String [] args) {
   int n=4;int m=5;
   int mat[][]={{1, 2, 3, 4, 5},
                  {  4, 3, 1, 2, 6},
                    {8, 7, 6, 5, 4},
                    {5, 7, 8, 9, 10}};

   multiply(n,m,mat);
}
}
```
### snake pattern
```java
import java.util.*;
class Main{
 static void multiply(int n,int m,int [][]mat){
   for(int i=0;i<n;i=i+2){
        for(int j=0;j<m;j++){
            System.out.print(mat[i][j]+" ");

        }
        for(int l=m-1;l>=0;l--){
            System.out.print(mat[i+1][l]+" ");
         }
    }
}
public static void  main(String [] args) {
   int n=4;int m=5;
   int mat[][]={{1, 2, 3, 4, 5},
                  {  4, 3, 1, 2, 6},
                    {8, 7, 6, 5, 4},
                    {5, 7, 8, 9, 10}};

   multiply(n,m,mat);
}
}
```
### Sort a Matrix in all way increasing order
```java
import java.util.*;
class Main{
 static void multiply(int n,int m,int [][]mat){
     int l=n*m;
  int[]temp=new int[l];
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[k++]=mat[i][j];
        }
        }
        Arrays.sort(temp);
    k=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[i][j]=temp[k++];
             System.out.print(mat[i][j]+" ");
        }
        }
}
public static void  main(String [] args) {
   int n=4;int m=4;
   int mat[][]={ {10, 20, 30, 40},
                            {15, 25, 35, 45},
                           {27, 29, 37, 48},
                           {32, 33, 39, 50}};

   multiply(n,m,mat);
}
}
```
### Find the row with maximum number of 1s
```java
import java.util.*;
class Main{
 static void multiply(int n,int m,int [][]mat){
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
        System.out.print("Row "+row+" has the maximum consecutive 1s, count ="+rowCount);
    } else {
        System.out.print("No row with 1s found\n");
    }
}
public static void  main(String [] args) {
   int n=4;int m=4;
   int mat[][]={  {0,1,1,1},
                            {0,0,1,1},
                           {0,1,1,1},
                           {1,1,1,1}};

   multiply(n,m,mat);
}
}
```
### Efficiently compute sums of diagonals of a matrix
```java
import java.util.*;
class Main{
 static void multiply(int n,int m,int [][]mat){
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
    System.out.println(primarySum);
    System.out.println(secondarySum);
}
public static void  main(String [] args) {
   int n=4;int m=4;
   int mat[][]={ { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 }, 
                      { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 } };

   multiply(n,m,mat);
}
}
```




