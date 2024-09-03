### sum of numbers
```py
n=int(input())
total=0;
for i in range(1,n+1):
  total+=i
print(total)
```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int total=0;
        for(int i=0;i<=n;i++){
            total+=i;
        }
        System.out.println(total);
    }
}
```
### factorial
```py
n=int(input())
fact=1;
for i in range(1,n+1):
  fact*=i
print(fact)
```
```java
import java.util.*;
class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int fact=1;
        for(int i=1;i<=n;i++){
            fact*=i;
        }
        System.out.println(fact);
    }
}
```
 ### fibonacci
 ```py
n=int(input())
prev,curr=0,1
for i in range(1,n+1):
  print(prev)
  next=prev+curr
  prev=curr
  curr=next
```
 ```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int prev=0;int curr=1;int next=0;
        
        for(int i=1;i<=n;i++){
            System.out.println(prev);
            next=prev+curr;
            prev=curr;
            curr=next;
        }
        
    }
}
```
### even and odd count
```py
n=int(input())
evenCount,oddCount=0,0
for i in range(1,n+1):
  if i%2==0:
    evenCount+=1
  else:
    oddCount+=1
print(f"{evenCount} even numbers {oddCount} odd numbers")
```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int evenC=0;int oddC=0;
        for(int i=1;i<=n;i++){
          if(i%2==0){
              evenC++;
          }
          else{
              oddC++;
          }
        }
        System.out.print(evenC+" even numbers "+oddC+" odd numbers");
        
    }
}
```
### multiplication table
```py
n=int(input())
for i in range(1,11):
  print(f"{i  } x {n} = {i*n}")
```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        
        for(int i=1;i<=10;i++){
            System.out.println(i +" x "+n+" = "+i*n);
          
        }
        
    }
}
```
### squares of num
```py
n=int(input())
squares=[i*i for i in range(1,n+1)]
print(squares)
```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        
        for(int i=1;i<=n;i++){
            System.out.println(i*i);
          
        }
        
    }
}
```


