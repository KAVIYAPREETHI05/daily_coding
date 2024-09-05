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
```py
n=int(input())
i=0
for i in range(n,i-1,-1):
  for k in range(0,2*(n-i)):
    print(' ',end='')
  for j in range(i):
    print(i,end=' ')
  print()
```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        for(int i=n;i>=0;i--){
            for(int k=0;k<2*(n-i);k++){
                System.out.print(" ");
            }
            for(int j=0;j<i;j++){
                System.out.print(i+" ");
            }
            System.out.println("");
        }
    }
}
```
### full pyramid
```py
n=int(input())

for i in range(1,n+1):
  for k in range(0,2*(n-i)+1):
    print(' ',end='')
  for j in range(0,2*i-1):
    print(i,end=' ')
  print()

```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        for(int i=1;i<=n;i++){
            for(int k=0;k<2*(n-i)+1;k++){
                System.out.print(" ");
            }
            for(int j=0;j<i*2-1;j++){
                System.out.print(i+" ");
            }
            System.out.println("");
        }
    }
}
```
### inverted full pyramid
```py
n=int(input())
i=0
for i in range(n,i-1,-1):
  for k in range(0,2*(n-i)):
    print(' ',end='')
  for j in range(0,2*i-1):
    print(i,end=' ')
  print()
```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        for(int i=n;i>=0;i--){
            for(int k=0;k<2*(n-i);k++){
                System.out.print(" ");
            }
            for(int j=0;j<i*2-1;j++){
                System.out.print(i+" ");
            }
            System.out.println("");
        }
    }
}
```
### rhombus
```py
n=int(input())

for i in range(1,n+1):
  for k in range(n-i):
    print(end=' ')
  for j in range(1,n+1):
    print(i,end=' ')
    
  print()

```

```java
import java.util.*;

class Hello {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        for(int i=1;i<=n;i++){
            for(int k=0;k<(n-i)+1;k++){
                System.out.print(" ");
            }
            for(int j=1;j<=n;j++){
                System.out.print(i+" ");
            }
            System.out.println("");
        }
    }
}
```
### hollow square
```py
n=int(input())

for i in range(1,n+1):
  for j in range(1,n+1):
    if i==1 or j==1 or i==n or j==n:
      print(i,end=' ')
    else:
      print(end='  ')
  print()

```
``java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=n;j++){
                if(i==1 || j==1 || i==n || j==n)
                System.out.print(i+" ");
                else{
                    System.out.print("  ");
                }
            }
            System.out.println("");
        }
    }
}
```

