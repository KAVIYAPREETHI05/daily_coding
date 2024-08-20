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

