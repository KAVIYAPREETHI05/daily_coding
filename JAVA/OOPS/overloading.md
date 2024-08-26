### OVER LOADING

Declaring two or more methods with same name but with different signature is called **method overloading**.

advantage - flexibility in coding and usage

In overloading method resolution will be taken care by java compiler based on **reference** type.

It is called as **static polymorphism** or **compile time polymorphism** or **early binding**.

```java
class Sample 
{
	public static void method(int a){
		System.out.println("int-arg");
		
	}
	public static void method(float a){
		System.out.println("float-arg");
	}
	public static void method(double a){
		System.out.println("double-arg");
	}
	public static void main(String[] args) 
	{
		Sample s=new Sample();
		s.method(3); //int-arg
		s.method(3.4f); //float-arg
		s.method(3.4456); //double-arg
		s.method('a'); //int-arg
		s.method(true); // no suitable method found for method(boolean)
		s.method(34l); //float-arg
	}
}

```
```java
class Sample 
{
	public static void method(int a,float b){
		System.out.println("int-arg");
		
	}
	public static void method(float a,int b){
		System.out.println("float-arg");
	}
	
	public static void method(double a,int b){
		System.out.println("double-arg");
	}
	public static void method(char a,int b){
		System.out.println("char-arg");
	}
	public static void method(long a,int b){
		System.out.println("long-arg");
	}
	public static void main(String[] args) 
	{
		Sample s=new Sample();
	//	s.method(23,4.5);//double does not fit under float
		s.method(3.4,34); //double-arg
	//	s.method(35,667); // reference to method is ambiguous(suitable for both (int,float),(long,float))
		s.method(3.4f,34); //(fit in(float,int),(double,int)) //float-arg
		s.method('a',34); //char-arg
		s.method(23,'a'); //reference to method is ambiguous(suitable for both (int,float),(long,int))
	}
}
```
```java
class Sample 
{
	public static void method(String s){
		System.out.println("String-arg");
		
	}
	public static void method(Object o){
		System.out.println("Object-arg");
	}
	
	public static void method(Thread t){
		System.out.println("thread-arg");
	}
	
	public static void main(String[] args) 
	{
		Sample s=new Sample();
		s.method(new String()); //string-arg
		s.method(new Object()); //object-arg
		s.method(new Thread()); //thread-arg
		//s.method(null); // reference to method is ambiguous(string),(thread)
	
	}
}

```
```java
class Sample 
{
	
	public static void method(Object o){
		System.out.println("Object-arg");
	}
	
		
	public static void main(String[] args) 
	{
		Sample s=new Sample();
		s.method(new String()); //object-arg
		s.method(new Object()); //object-arg
		s.method(new Thread()); //object-arg
		s.method(null); //oject-arg
	
	}
}

```
```java
class person{}
class child extends person{
	
}

class Sample 
{
	public static void method(person p){
		System.out.println("person");
	}
	public static void method(child c){
		System.out.println("child");
	}
			
	public static void main(String[] args) 
	{
		person p=new person();
		method(p); //person
		child c=new child();
		method(c); //child
		person p2=new child();
		method(p2); //person
		
		
	
	}
}

```
