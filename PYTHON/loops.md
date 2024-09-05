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
```py
num=int(input())
fib=[0,1]
for i in range(2,num+1):
  fib.append(fib[-1]+fib[-2])
print(fib)

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
### reverse num
```py
lst=[1,2,3,4,5]
reverse_list=[]
for i in range(len(lst)-1,-1,-1):
  reverse_list.append(lst[i])
print(reverse_list)
```
```java

import java.util.*;
class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
 n=Math.abs(n);
        int reversed=0;
        while(n>0){
            int digit=n%10;
            reversed=reversed*10+digit;
            n/=10;
        }
        System.out.println(reversed);
    }
}
```
```py
num=int(input())
num=abs(num)
reversed=0
while(num>0):
  digit=num%10
  reversed=reversed*10+digit
  num//=10
print(reversed)

```
### check prime
```py
num=int(input())
found=0
if(num<2):
  found=1
for i in range(2,int(num ** 0.5)+1):
  if num%i==0:
    found=1
    break
if found==0:
  print("prime")
else:
  print("not prime")
```
```java

import java.util.*;
class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int found=0;
        if(n<2){
           found=1;
        }
       for(int i=2;i<=n/2;i++){
           if(n%i==0){
               found=1;
           }
       }
       if(found==0){
           System.out.println("prime");
       }
       else{
           System.out.println("not prime");
       }
    }
}
```
### even num
```py
n=int(input())
for i in range(2,n+1):
  if(i%2==0):
    print(i,end=' ')
```
### check num is even or odd if even print even num else print odd numbers
```py
n=int(input())
if n%2==0:
  for i in range(0,n+1):
    if i%2==0:
      print(i,end=' ')
else:
  for i in range(0,n+1):
    if i%2!=0:
      print(i,end=' ')
  

```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        if(n%2==0){
            for(int i=0;i<=n;i++){
                if(i%2==0){
                    System.out.print(i+" ");
                }
            }
        }
        else{
            for(int i=0;i<=n;i++){
                if(i%2!=0){
                    System.out.print(i+" ");
                }
            }
        }
        }
    }
```
### sum of digits until single digit
```py

def find_sum(n):
  sum=0
  while n>0:
    digit=n%10
    sum+=digit
    n//=10
  return sum
n=int(input())
while n>=10:
  n=find_sum(n)
  
print(n)

```
```java
import java.util.*;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
          while(n>=10){
               n=find(n);
          }
     System.out.println(n);
        }
        public static int find(int n){
            int sum=0;
             while(n>0){
                   int digit=n%10;
                   sum+=digit;
                   n/=10;
           }
           return sum;
        }
    }

```
### lcm and gcd
```py
def gcd(a,b):
  while b!=0:
    temp=b
    b=a%b
    a=temp
  return a
a=int(input())
b=int(input())
lcm=abs(a*b)//gcd(a,b)
gcdd=gcd(a,b)
print(lcm)
print(gcdd)
```
```java
  import java.util.*;

class HelloWorld {
    public static int gcd(int a ,int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int a=scan.nextInt();
        int b=scan.nextInt();
        int lcm=Math.abs(a*b)/gcd(a,b);
        int gcdd=gcd(a,b);
        System.out.println(lcm+" "+gcdd);
        }
    }

```
### armstrong number
```py
n=int(input())
temp=n
numdigit=len(str(n))
sum=0
while(n>0):
  digit=n%10
  sum=sum+pow(digit,numdigit)
  n//=10
if temp==sum:
  print("yess")
else:
  print(no)
```
```java
import java.util.*;

class HelloWorld {
   
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int a=scan.nextInt();
        int temp=a;
        int sum=0;
        int numdigit=Integer.toString(a).length();
        while(a>0){
            int digit=a%10;
            sum+=Math.pow(digit,numdigit);
            a/=10;
        }
        if(sum==temp){
            System.out.println("yes NarcissisticNumber");
        }
        else{
            System.out.println("not NarcissisticNumber");
        }
       
    }
}

```
### ugly number
```java
import java.util.*;

class HelloWorld {
    public static boolean uglyno(int n){
        if(n<=0) return false;
        while(n%2==0){
            n/=2;
        }
        while(n%3==0){
            n/=3;
        }
        while(n%5==0){
            n/=5;
        }
        if(n==1){
            return true;
        }
        return false;
    }
   
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int a=scan.nextInt();
       if(uglyno(a)){
           System.out.println("yes");
       }
       else{
           System.out.print("no");
       }
    }
}

```
### interchange first and last digit
```java
import java.util.*;

class HelloWorld {
    public static int lastFirst(int n){
        String s=Integer.toString(n);
        int length=s.length();
        if(length<=1){
            return n;
        }
        char digits[]=s.toCharArray();
        char first=digits[0];
        char last=digits[length-1];
        digits[0]=last;
        digits[length-1]=first;
        return Integer.parseInt(new String(digits));
        
    }
   
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int a=scan.nextInt();
       System.out.println(a);
        System.out.println(lastFirst(a));
    }
}

```




