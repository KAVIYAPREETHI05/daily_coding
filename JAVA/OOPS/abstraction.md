### ABSTRACTION

The process of highlighting the required services by hiding their internal implementation is abstration.

By using **abstract classes** and **interfaces** we can achieve abstration.

**Enhancement**(bug correction is easy) will be increased.

**Modularity** and **Maintainability** of the application.

### abstract class
```java
abstract class Shape{
	public abstract void calculateArea();
	public abstract void calculatePerimeter();
}
class Circle extends Shape{
	double r;
	public void calculateArea(){
		System.out.println(3.14*r*r);}
	public void calculatePerimeter(){
		System.out.println(2*3.14*r);
	}
}
class Triangle extends Shape
{
	double b;
	double h;
	long a;long c;
	public void calculateArea(){
		System.out.println(0.5 *b*h);
		
	}
	public void calculatePerimeter(){
		System.out.println(a+b+c);
	}
}

class Test	
{
	public static void main(String[] args) 
	{
		Circle c=new Circle();
		c.r=2;
		c.calculateArea();
		c.calculatePerimeter();
		
		Triangle t=new Triangle();
		t.b=2.3;t.h=3.4;
		t.a=231;t.c=23;
		t.calculateArea();
		t.calculatePerimeter();
	}
}

```
### interface 

```java
interface  Shape{
	public  void calculateArea();
	public  void calculatePerimeter();
}
class Circle implements Shape{
	double r;
	public void calculateArea(){
		System.out.println(3.14*r*r);}
	public void calculatePerimeter(){
		System.out.println(2*3.14*r);
	}
}
class Triangle implements Shape
{
	double b;
	double h;
	long a;long c;
	public void calculateArea(){
		System.out.println(0.5 *b*h);
		
	}
	public void calculatePerimeter(){
		System.out.println(a+b+c);
	}
}

class Test	
{
	public static void main(String[] args) 
	{
		Circle c=new Circle();
		c.r=2;
		c.calculateArea();
		c.calculatePerimeter();
		
		Triangle t=new Triangle();
		t.b=2.3;t.h=3.4;
		t.a=231;t.c=23;
		t.calculateArea();
		t.calculatePerimeter();
	}
}

```

