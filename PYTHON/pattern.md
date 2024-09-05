### right half
```py
n=int(input())
for i in range(1,n+1):
  print(' '.join(str(i)*i))

```
```py
n=int(input())
for i in range(1,n+1):
  for j in range(i):
    print(i,end=' ')
  print()
```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan =new Scanner(System.in);
        int n=scan.nextInt();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                System.out.print(i);
            }
            System.out.println("");
        }
    }
}
```
### left half
```py
n=int(input())
for i in range(1,n+1):
  for k in range(2*(n-i)-1):
    print(end=' ')
  for j in range(i):
    print(i,end=' ')
  print()
```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan =new Scanner(System.in);
        int n=scan.nextInt();
        for(int i=1;i<=n;i++){
            for(int k=0;k<2*(n-i)-1;k++){
                System.out.print(" ");
            }
            for(int j=1;j<=i;j++){
                System.out.print(i+" ");
            }
            System.out.println("");
        }
    }
}
```
### inverted right
```py
n=int(input())
for i in range(1,n+1):
  for j in range(n,i-1,-1):
    print(i,end=' ')
  print()
```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan =new Scanner(System.in);
        int n=scan.nextInt();
        for(int i=1;i<=n;i++){
            for(int j=n;j>=i;j--){
                System.out.print(i+"");
            }
            System.out.println("");
        }
    }
}
```
### inverted left

