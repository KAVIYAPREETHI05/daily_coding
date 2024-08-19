### Variables

Based on type values

- primitive variables(refer primitive data types)
- Reference variables(refer object)

Based on purpose and position of declaration

- Instance Variables(non-static,attributes,object level)
- Static Variables(Fields,class level)
- Local Variables(temporary var,stack var)

```java
class Hello 
{
	static int x=10;
	public static void main(String[] args) 
	{
		System.out.println(x);
	}
}

//10
```
```java
class Hello 
{
	static int x;
	public static void main(String[] args) 
	{
		System.out.println(x);
	}
}
//0   default value of static
```
```java
class Hello 
{
	 int x=10;
	public static void main(String[] args) 
	{
		System.out.println(x);
	}
}

//Hello.java:6: error: non-static variable x cannot be referenced from a static context
```
```java
class Hello 
{
	 int x=10;
	public static void main(String[] args) 
	{
		Hello h=new Hello();
		System.out.println(h.x);
	}
}
//10
```
```java
class Hello 
{
	 int x;
	public static void main(String[] args) 
	{
		Hello h=new Hello();
		System.out.println(h.x);
		t.m1();
	}
	public void m1(){
		System.out.println(x);
	}
}

//0    default value of non-static
```
```java
class Hello 
{
	 static int x=10;
	public static void main(String[] args) 
	{
		System.out.println(x); //10
		Hello h=new Hello();
		System.out.println(h.x);  //10
		System.out.println(Hello.x);  //10
		
	}
	
}
//static variable can be executed directly,using class name(recommended) or its objects but instance var can be called only using objects because instance var provide default value at the time of object creation.
```
```java
class Hello 
{
	public static void main(String[] args) 
	{
		int x;
		System.out.println(x); 	
		
	}
	
}
// local var does not have default value.
//Hello.java:6: error: variable x might not have been initialized
```
```java
class Hello 
{
	public static void main(String[] args) 
	{
		for(int i=0;i<=args.length;i++){
			
		System.out.println(args[i]); 	
		}
		
	}
	
}

// RE : Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 0 out of bounds for length 0
```

