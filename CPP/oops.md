### circle's area and circumference
```cpp
#include <iostream>
#include<cmath>
using namespace std;
class circle{
    private:
    double radius;
    public:
    circle( double r){
        radius=r;
    }
    void areaofCircle(){
        cout<<"Area is: "<<M_PI*pow(radius,2)<<endl;
        
    }
    void circumofCircle(){
        cout<<"Circum is: "<<2*M_PI*radius;
    }
};
int main()
{
    double r=3.00;
    circle c1(r);
    c1.areaofCircle();
    c1.circumofCircle();
    return 0;
}
```
### rectangle's area and perimeter
```cpp
#include <iostream>
#include<cmath>
using namespace std;
class rectangle{
    private:
    int length;
    int width;
    public:
    rectangle( int l,int b){
        length=l;
        width=b;
    }
    void areaOfReactangle(){
        cout<<"Area is: "<<length*width<<endl;
        
    }
    void perimeterOfRectangle(){
        cout<<"Circum is: "<<2*(length+width);
    }
};
int main()
{
    rectangle r1(3,4);
    r1.areaOfReactangle();
    r1.perimeterOfRectangle();
    return 0;
}
```
### set and get values
```cpp
#include <iostream>
using namespace std;
class person{
    private:
    string name;
    int age;
    string country;
    public:
    void setNameAgeCountry( string n,int a,string c){
        name=n;
        age=a;
        country=c;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getCountry(){
        return country;
    }
};
int main()
{
    person p1;
    p1.setNameAgeCountry("kaviya",19,"India");
    cout<<p1.getName()<<endl;
    cout<<p1.getAge()<<endl;
    cout<<p1.getCountry();
    return 0;
}
```
### deposit and withdraw money from the account
```cpp
#include <iostream>
using namespace std;
class BankAccount{
    private:
    int accountNo;
    double balance;
    
    public:
    BankAccount( int No,double bal){
        accountNo=No;
        balance=bal;
    }
    void deposit(double amount){
        cout<<"Initial balance: "<<balance<<endl;
        balance+=amount;
        cout<<"Deposit:"<<balance<<endl;
    }
    void withdraw(double amount){
        if(amount>balance){
            cout<<"Insufficient balance..";
        }
        else{
            cout<<"Withdraw amount: "<<amount<<endl;
            balance-=amount;
            cout<<"After withdraw: "<<balance;
        }
    }
};
int main()
{
    BankAccount b1(101,2000);
    b1.deposit(500);
    b1.withdraw(200);
    return 0;
}
```

