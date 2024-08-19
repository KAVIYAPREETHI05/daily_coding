### class

logical representation of object  (or)   structure of object

```java
class Student{
int id;
String name;
}
```

### object

instance of class

we can create any no ofinstance for that class based on our requirements.

```java
Student s1=new Student();
Student s2=new Student();
Student s3=new Student();
```

```java
class Student{
	int id;
	String name;
	Student(int sid,String sname){
		id=sid;
		name=sname;
	}
		
}
class Hello 
{
	public static void main(String[] args) 
	{
		Student s1=new Student(101,"kavi");
		Student s2=new Student(102,"sky");
		
		System.out.println(s1.id+"...."+s1.name);
		System.out.println(s2.id+"...."+s2.name);	
		
	}
	
}

//101....kavi
//102....sky
```
