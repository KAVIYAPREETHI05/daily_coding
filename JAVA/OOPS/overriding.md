### OVERRIDING

Through easier relationship whatever parent has(properties, behaviours) are by default available to the child class.

If the child is not satisfied with parent method behaviour then child can, change that behaviour by using **method overriding**.

In overriding method resolution will be taken care by JVM based on runtime object.

It is called as **dynamic polymorphism** or **runtime polymorphism** or **late binding**.

abstract or interface cannot create objects.


- Method signature must be same.
- For primitives, return type must be same. But for object types co-varient return types are allowed.
- child method return type must be same as parent method return type or its child type.
- overriding concept is not applicable for private methods.
  

```java
class person{
	public void method(){
		System.out.println("person");
	}
}
class child extends person{
	public  void method(){
		System.out.println("child");
	}
	
}

class Sample 
{		
			
	public static void main(String[] args) 
	{
		person p=new person();
		p.method(); //person
		child c=new child();
		c.method(); //child
		person p2=new child();
		p2.method(); //child (depends on object side)

	}
}

```
```java
class parent{
	public void trip(){
		System.out.println("family trip to chennai");
	}
	public void college(){
		System.out.println("PSG");
	}
}
class child extends parent{
	public  void college(){
		System.out.println("BIT");
	}
	
}

class Sample 
{		
			
	public static void main(String[] args) 
	{
		parent p=new parent();
		p.trip();
		p.college(); 
		
		child c=new child();
		c.trip();
		c.college(); 
		parent p2=new child();
		p2.trip(); 
		p2.college();
		
	
	}
}
/*family trip to chennai
PSG
family trip to chennai
BIT
family trip to chennai
BIT*/
```
