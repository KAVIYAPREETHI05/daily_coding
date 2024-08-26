### OVERRIDING

Both parent and child methods are **not static** with same signature.

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

static method or variables are not associated with objects, it is always associated with object
```java
class person{
	public static void method(){
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
		p.method(); 
		child c=new child();
		c.method(); 
		person p2=new child();
		p2.method(); 

	}
}
// overridden method is static(parent)
```
```java
class person{
	public  void method(){
		System.out.println("person");
	}
}
class child extends person{
	public static void method(){
		System.out.println("child");
	}
	
}

class Sample 
{		
			
	public static void main(String[] args) 
	{
		person p=new person();
		p.method(); 
		child c=new child();
		c.method(); 
		person p2=new child();
		p2.method(); 

	}
}
//  overriding method is static(child)
```

### OVERHIDING

Both parent and child methods are **static** with same signature.

In overriding method resolution will be taken care by Java compiler based on reference type.

It is called as **static polymorphism** or **compile polymorphism** or **early binding**.

```java
class person{
	public static void method(){
		System.out.println("person");
	}
}
class child extends person{
	public static void method(){
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
		p2.method(); //person (depends on reference type)

	}
}

```

### var-arg method

Variable arguments (varargs) in Java allow a method to accept a variable number of arguments. This feature is useful when you want to pass a varying number of arguments to a method without having to overload the method.

```java


class Sample 
{		public static void sum(int... a){
		int sum=0;
		for(int i=0;i<a.length;i++){
			sum+=a[i];
			
		}
		System.out.println(sum);
	}
			
	public static void main(String[] args) 
	{
		person p=new person();
		p.sum(10,20); //30
		child c=new child();
		c.sum(10,20,30,40);//100
		person p2=new child();
		p2.sum(1,2,3,4,5); //15

	}
}

```
We cannot override a var-arg method with normal method.

A var-arg method must be overridden with  var-arg method only.




