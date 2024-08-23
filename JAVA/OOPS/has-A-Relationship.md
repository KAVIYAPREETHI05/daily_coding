### HAS-A RELATIONSHIP

It is also known as **composition** or **agreegation**

There is no specific keyword to define this relationship but we use **new** keyword to create the dependent object.

advantage - code reusability

```java
class Car
{
	Engine e;
	Car(Engine e){
		this.e=e;
	}
	public void move(){
		e.start();
		System.out.println("car is moving");
}
}
class Engine
{
	public void start(){
		System.out.println("engine started");
	}
}
class Test	
{
	public static void main(String[] args) 
	{
		Engine e=new Engine();
		Car c=new Car(e);
		c.move();		
		
	}
}
```
### METHOD SIGNATURE

In java method signature, method name followed by argument type.(but not argument type)

**Modifier** and **return type** are not part of method signature.
