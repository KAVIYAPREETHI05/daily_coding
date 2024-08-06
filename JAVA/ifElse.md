
**if** -It is used to decide whether a certain statement or block of statements will be executed or not
**if-else**-if statement alone tells us that if a condition is true it will execute a block of statements and if the condition is false it won’t.
**nested if**-Nested if statements mean an if statement inside an if statement.
**if-else-if**-There can be as many as ‘else if’ blocks associated with one ‘if’ block but only one ‘else’ block is allowed with one ‘if’ block.
**switch**-The switch statement is a multiway branch statement. It provides an easy way to dispatch execution to different parts of code based on the value of the expression. 
**jump**
- break- to exit switch,loop,goto.
- continue-it stop processing the remainder of the code in its body for this particular iteration.
- return-The return statement is used to explicitly return from a method.

if-else-
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


