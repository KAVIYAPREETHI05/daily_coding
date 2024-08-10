
**if** -It is used to decide whether a certain statement or block of statements will be executed or not

**if-else**-if statement alone tells us that if a condition is true it will execute a block of statements and if the condition is false it won’t.

**nested if**-Nested if statements mean an if statement inside an if statement.

**if-else-if**-There can be as many as ‘else if’ blocks associated with one ‘if’ block but only one ‘else’ block is allowed with one ‘if’ block.

**switch**-The switch statement is a multiway branch statement. It provides an easy way to dispatch execution to different parts of code based on the value of the expression. 

**jump**
- break- to exit switch,loop,goto.
- continue-it stop processing the remainder of the code in its body for this particular iteration.
- return-The return statement is used to explicitly return from a method.


### get input and print output
```java
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner num1=new Scanner(System.in);
       
        int i=num1.nextInt();
        double d=num1.nextDouble();
        float f=num1.nextFloat();
        num1.nextLine();//to clear newline char left by nextFloat
        char c=num1.next().charAt(2);
        num1.nextLine();//to clear newline char left by charAt
        String s=num1.nextLine();
        boolean b=num1.nextBoolean();
        long l=num1.nextLong();
        short st=num1.nextShort();
        
        System.out.println("Integer"+" "+i);
        System.out.println("double:"+d);
        System.out.println("float"+f);
        System.out.println("char"+c);
        System.out.println("string"+s);
        System.out.println("boolean"+b);
        System.out.println("long"+l);
        System.out.println("short"+st);
        
    }
}
```
### positive or negative
```java
import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int input=in.nextInt();
        if(input<0){
            System.out.println("Number is negative");
        }
        else if(input>0){
            System.out.println("Number is positive");
        }
        else if(input==0){
            System.out.println("Number is zero");
        }
        
        
    }
}
```
### find roots 
```java
import java.util.Scanner;
import static java.lang.Math.sqrt;
public class Main{
    public static void main(String[] args){
        Scanner num1=new Scanner(System.in);
       
        double val1=num1.nextDouble();
        double val2=num1.nextDouble();
        double val3=num1.nextDouble();
        double discriminant=(val2*val2)-(4*val1*val3);
        if(discriminant<0){
            System.out.println("equation has no real roots");
        }
        else{
            double root1=(-val2+sqrt(discriminant))/2*val1;
            double root2=(-val2-sqrt(discriminant))/2*val1;
            System.out.println(root1);
            System.out.println(root2);
            
            
        }
        
    }
}
```
### greatest number
```java
import java.util.Scanner;
import static java.lang.Math.sqrt;
public class Main{
    public static void main(String[] args){
        Scanner num1=new Scanner(System.in);
       
        double val1=num1.nextDouble();
        double val2=num1.nextDouble();
        double val3=num1.nextDouble();
        if(val1>val2 && val1>val3){
            System.out.println(val1);
        }
        else if(val2>val1 && val2>val3){
            System.out.println(val2);
        }
        else if(val3>val1 && val3>val2){
            System.out.println(val3);
        }
        
    }
}
```
### 
```java
import java.util.Scanner;
import static java.lang.Math.sqrt;
public class Main{
    public static void main(String[] args){
        Scanner num1=new Scanner(System.in);
       
        double value=num1.nextDouble();
        if(value<0){
            if(Math.abs(value)<1){
                    System.out.println("negative and small");
                }
                else if(Math.abs(value)>1000000){
                    System.out.println("negative and greater");
                }
                else
            System.out.println("negative");
            
        }
        else if(value>0){
                if(value<1){
                    System.out.println("positive and small");
                }
                else if(value>1000000){
                    System.out.println("positive and greater");
                }
                else
            System.out.println("positive");
            }
        else{
            System.out.println("zero");
        }
        }
}
```
### weeks
```java
import java.util.Scanner;
import static java.lang.Math.sqrt;
public class Main{
    public static void main(String[] args){
        Scanner num1=new Scanner(System.in);
       
        int value=num1.nextInt();
        switch(value){
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesay");
                break;
            case 3:
                System.out.println("Wednesday");
                break;
            case 4:
                System.out.println("Thursday");
                break;
            case 5:
                System.out.println("Friday");
                break;
            case 6:
                System.out.println("Saturday");
                break;
            case 7:
                System.out.println("Sunday");
                break;
            default:
            System.out.println("not valid");
                
        }
        }
}
```
### same up to three decimal places.
```java
import java.util.Scanner;
import static java.lang.Math.sqrt;
public class Main{
    public static void main(String[] args){
        Scanner num1=new Scanner(System.in);
       
        float value=num1.nextFloat();
        float value2=num1.nextFloat();
        value=Math.round(value*1000);
        value=value/1000;
        value2=Math.round(value2*1000);
        value2=value2/1000;
        if(value==value2){
            System.out.println("Ther are same");
        }
        else{
            System.out.println("They are not same");
        }
        
        }
}
```
### 
```java
import java.util.Scanner;
import static java.lang.Math.sqrt;
public class Main{
    public static void main(String[] args){
        Scanner num1=new Scanner(System.in);
       
        int m=num1.nextInt();
        int y=num1.nextInt();
       if(m>0 && m<=12){
           if(m==1 || m==3 || m==5 ||m==7 ||m==8 ||m==10 ||m==12){
               System.out.println(m + "has 31 days");
           }
           else if(m==4 || m==6 ||m==9 ||m==11){
               System.out.println(m + "has 30 days");
           }
           else if(m==2){
               if((( y%4==0) && (y%100!=0)) || y%400==0){
                   System.out.println(m+"has 29 days");
                   
               }
               else{
                   System.out.println(m+"has 28 days");
               }
           }
       }
       else{
           System.out.println("invalid");
       }
        num1.close();
        
        }
}
        

```
### check vowel
```java

import java.util.Scanner;
class HelloWorld {
    public static void main(String[] args) {
        Scanner hello=new Scanner(System.in);
        char a=hello.next().charAt(0);
        if(Character.isLetter(a)){
            if(a=='a' || a=='e' ||a=='i' ||a=='o' ||a=='u' ||a=='A' || a=='E' ||a=='I' ||a=='O' ||a=='U'){
                System.out.println("vowels");
            }
            else{
                System.out.println("consonants");
            }
        }
        else{
            System.out.println("not alpha");
        }
        
    }
}
```
### check leap year
```java
import java.util.Scanner;

class HelloWorld {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int year=input.nextInt();
        if((year%4==0 && year%100!=0) || year%400==0){
            System.out.println("leap year");
        }
        else{
            System.out.println("non-leap year");
        }
    }
}
```
### print natural num + their sum + average
```java
import java.util.Scanner;

class HelloWorld {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int num=input.nextInt();
        int sum=0;
        for(int i=1;i<=num;i++){
            System.out.println(i);
            sum+=i;
        }
        float avg=sum/num;
        System.out.println(sum);
        System.out.println(avg);
    }
}
```
### cube of number
```java
import java.util.Scanner;
public class Main{
    public static void main(String[] arg){
        Scanner input=new Scanner(System.in);
        int num=input.nextInt();
        for(int i=1;i<=num;i++){
            int value=i*i*i;
            System.out.println(value);
        }
    }
}
```
### multiplication table
```java
import java.util.Scanner;
public class Main{
    public static void main(String[] arg){
        Scanner input=new Scanner(System.in);
        int num=input.nextInt();
        for(int i=1;i<=10;i++){
            int value=num*i;
            System.out.println(num + "*" +i +"=" + value);
        }
    }
}
```
### odd numbers til num
```java
import java.util.Scanner;
public class Main{
    public static void main(String[] arg){
        Scanner input=new Scanner(System.in);
        int num=input.nextInt();
      int i=1;int count=0;
      while(num!=0){
          if(i%2!=0){
              System.out.println(i);
              num--;
          }
          i++;
          
      }
    }
}
```
###


