### ENCAPSULATION

Binding the data together with its related methods in the concept of encapsulation.

class is the base tp define encapsulation and we achieve it by creating oject of the class.

**Tightly encapsulated class**

If every instance var of class declared by using **private** modifier the that class is called tightly encapsulated class.

It is not required to check whether these properties are having corresponding public setter and getter methods.

If parent class is not tightly encapsulated then no child class is tightly encapsulated.

```java
 class Smartphone{
	private String brand;
	private String model;
	private double stcapacity;
	public void setter(String sbrand,String smodel,double stgcapacity){
		this.brand=sbrand;
		this.model=smodel;
		this.stcapacity=stgcapacity;
	}
	public String getter(){
		return "Brand:"+ brand + ",Model:" + model+ ",StorageCapacity:" + stcapacity;
	}
	public void increaseCapacity(int capacity){
		int c=(int)stcapacity + capacity;
		System.out.println(c);
		
	}	
	}
class Test	
{
	public static void main(String[] args) 
	{
		Smartphone s=new Smartphone();
		s.setter(" electronics brand ","vivo v40",400.34);
		System.out.println(s.getter());
		s.increaseCapacity(23);
	}
}

```
