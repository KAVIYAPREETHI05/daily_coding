### CONSTRUCTOR AND METHOD OVERRIDING
```java
class A {
    A() {
        System.out.println("A Constructor");
        show();
    }

    void show() {
        System.out.println("A show()");
    }
}

class B extends A {
    int x = 10;

    B() {
        System.out.println("B Constructor");
    }

    void show() {
        System.out.println("B show() " + x);
    }

    public static void main(String[] args) {
        A obj = new B();
    }
}

```
```
o/p
A Constructor
B show() 0
B Constructor
```

### STATIC METHOD HIDING

```java
class A {
    static void show() {
        System.out.println("A show()");
    }
}

class B extends A {
    static void show() {
        System.out.println("B show()");
    }

    public static void main(String[] args) {
        A obj = new B();
        obj.show();
    }
}
```
```
o/p
A show();
```

### CONSTRUCTOR CHAINING

when object of subclass is created, the constructor of super class is executed first.

```java
class A {
    A() {
        System.out.println("A Constructor");
    }
}

class B extends A {
    B() {
        System.out.println("B Constructor");
    }
}

class C extends B {
    C() {
        System.out.println("C Constructor");
    }

    public static void main(String[] args) {
        C obj = new C();
    }
}

```
```
o/p
A Constructor
B Constructor
C Constructor

```

### FINAL METHOD

```java
class A {
    final void show() {
        System.out.println("A show()");
    }
}

class B extends A {
    // void show() {  // Compilation Error
    //     System.out.println("B show()");
    // }

    public static void main(String[] args) {
        A obj = new B();
        obj.show();
    }
}

```

```
o/p
compilation error

```

### INSTANCE BLOCK

```java
class A {
    {
        System.out.println("A Instance Block");
    }

    A() {
        System.out.println("A Constructor");
    }
}

class B extends A {
    {
        System.out.println("B Instance Block");
    }

    B() {
        System.out.println("B Constructor");
    }

    public static void main(String[] args) {
        B obj = new B();
    }
}

```
```
o/p
A Instance Block
A Constructor
B Instance Block
B Constructor

```

### PARENT -CHILD REFERENCE

```java
class Parent {
    void display() {
        System.out.println("Parent display()");
    }
}

class Child extends Parent {
    void display() {
        System.out.println("Child display()");
    }

    public static void main(String[] args) {
        Parent obj = new Child();
        obj.display();
    }
}

```
```
o/p
child display();
```

### MULTIPLE INHERITENCE USING INTERFACES

```java

interface A {
    default void show() {
        System.out.println("A show()");
    }
}

interface B {
    default void show() {
        System.out.println("B show()");
    }
}

class C implements A, B {
    public void show() {
        A.super.show();
    }

    public static void main(String[] args) {
        C obj = new C();
        obj.show();
    }
}

```
```
o/p
A show()

```

### STATIC BLOCK EXECUTION

 Static blocks execute only once before any instance creation.
 
```java

class A {
    static {
        System.out.println("A Static Block");
    }
}

class B extends A {
    static {
        System.out.println("B Static Block");
    }

    public static void main(String[] args) {
        B obj = new B();
    }
}

```
```o/p
A Static Block
B Static Block
```

### PRIVATE METHOD IN PARENT

```java
class A {
    private void show() {
        System.out.println("A show()");
    }
}

class B extends A {
    void show() {
        System.out.println("B show()");
    }

    public static void main(String[] args) {
        A obj = new B();
        // obj.show();  // Compilation Error
    }
}

```
```
o/p
compilation error
```

### STATIC AND INSTANCE

```java
class A {
    static {
        System.out.println("A Static Block");
    }

    {
        System.out.println("A Instance Block");
    }

    A() {
        System.out.println("A Constructor");
    }
}

class B extends A {
    static {
        System.out.println("B Static Block");
    }

    {
        System.out.println("B Instance Block");
    }

    B() {
        System.out.println("B Constructor");
    }

    public static void main(String[] args) {
        B obj = new B();
    }
}

```
```
o/p

A Static Block
B Static Block
A Instance Block
A Constructor
B Instance Block
B Constructor

```

### ABSTRACT CLASS

```java
abstract class A {
    A() {
        System.out.println("A Constructor");
    }
}

class B extends A {
    B() {
        System.out.println("B Constructor");
    }

    public static void main(String[] args) {
        B obj = new B();
    }
}
```

```o/p
A Constructor
B Constructor
```

### STRING POOL
```java
class Test {
    public static void main(String[] args) {
        String s1 = "Hello";
        String s2 = new String("Hello");
        System.out.println(s1 == s2);
    }
}

```
```o/p
false
```

```java
String s1 = "Hello";
String s2 = new String("Hello").intern();  // Moves "Hello" to the String Pool
System.out.println(s1 == s2);  // true ✅
```
```o/p
true
```

###

```java
class Automobile {
    private String drive() {
        return "Driving vehicle";
    }
}

class Car extends Automobile {
    protected String drive() {
        return "Driving car";
    }
}

public class ElectricCar extends Car {

    @Override
    public final String drive() {
        return "Driving an electric car";
    }

    public static void main(String[] wheels) {
        final Car car = new ElectricCar();
        System.out.print(car.drive());
    }
}
```

```
o/p
Driving an electric car
```
  

### ACCESS MODIFIER

```java
// Shape.java
public class Shape {
    protected void display() {
        System.out.println("Display-base");
    }
}
// Circle.java
public class Circle extends Shape { <
    < access - modifier > void display() {
        System.out.println("Display-derived");
    }
}
```
```
o/p
public- public only need to use
protected- public and protected both can be used.
default- public,protected and default can be used.
private- public,protected, default and private can be used.
```

