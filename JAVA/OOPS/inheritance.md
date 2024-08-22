### IS-A-RELATIONSHIP

This is also know as **inheritance**

By using **extends** we will derive inheriance.

Advantage- Code Reusability

We can use parent reference to represent child object but by using this reference we can invoke only parent method and cannot invoke child specific methods.

```java
 class BankAccount{
	 private String accNumber;
	 private double balance;
	 BankAccount(String accNumber,double bal){
		 this.accNumber=accNumber;
		 this.balance=bal;
		 }
	public void deposit(double amount){
		balance+=amount;
	}
			
	public void withdrawal(double amt){
		if(balance>=amt){
			balance-=amt;
			
		}
		else{
			System.out.println("insufficient amount");
		}
		
	}
	public double getBalance(){
		return balance;
	}
 }
class SavingsAccount extends BankAccount	
{
	public SavingsAccount(String accNumber,double bal){
		super(accNumber,bal);
	}
	public void withdrawal(double amt){
		if(getBalance() - amt<100){
			System.out.println("minimum bal 100 req");
		}
		else{
			super.withdrawal(amt);
		}
	}
	
}
class Test	
{
	public static void main(String[] args) 
	{
		BankAccount b=new BankAccount("A21",1000);
		b.deposit(500);
		b.getBalance();
		b.withdrawal(600);
		b.getBalance();
		System.out.println(b.getBalance());
		
		
		SavingsAccount s=new SavingsAccount("B21",400);
		s.withdrawal(350);
		System.out.println(s.getBalance());
		
		
	}
}

//900.0
//minimum bal 100 req
//400.0

```
