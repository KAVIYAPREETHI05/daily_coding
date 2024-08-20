### DATA HIDING

The process of hiding data from direct access is called data hiding.

By using **private** modifier we can achieve data hiding.

advantage-**security**

```java
class Account{
	private double balance;
	public double getbalance(){
		return balance;
	}
		
}
class Hello 
{
	public static void main(String[] args) 
	{
		Account a= new Account();
		System.out.println(a.getbalance());
		System.out.println(a.balance);   // balance has private access in Account
	}
	
}
```
```java
class Address {
    String houseno;
    String street;
    String city;
    String state;
    int pincode;

    @Override
    public String toString() {
        return "Address{" +
                "houseno='" + houseno + '\'' +
                ", street='" + street + '\'' +
                ", city='" + city + '\'' +
                ", state='" + state + '\'' +
                ", pincode=" + pincode +
                '}';
    }
}

class Student {
    int id;
    String name;
    private int age;
    Address addr;

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age=" + age +
                ", addr=" + addr +
                '}';
    }
}

public class Hello {
    public static void main(String[] args) {
        Address a = new Address();
        a.city = "kovai";

        Student s1 = new Student();
        s1.id = 1;
        s1.name = "kavi";
        s1.setAge(20);
        s1.addr = a;

        System.out.println(s1);
    }
}
//Student{id=1, name='kavi', age=20, addr=Address{houseno='null', street='null', city='kovai', state='null', pincode=0}}
```
