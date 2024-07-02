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
### check valid Triangle
```cpp
#include <iostream>
using namespace std;
class Triangle{
    private:
    int side1;
    int side2;
    int side3;
    public:
    /*assignment in constructor body-less efficient
    Triangle(int s1,int s2,int s3){
        side1=s1;
        side2=s2;
        side3=s3;
    }
    instead of this use constructor initialization list for more efficient*/
    Triangle(int s1,int s2,int s3) : side1(s1),side2(s2),side3(s3){}
    void checkTriangle(){
        if(isvalidTriangle()){
             if(side1==side2 && side2==side3){
            cout<<"All sides are equal thus it is equilateral triangle";
        }
        else if(side1==side2 || side2==side3 ||side1==side3){
            cout<<"two sides of triangle are equal thus it is isosceles triangle";
        }
        else{
            cout<<"no sides are equal thus it is scalene triangle";
        }
        }
        else{
            cout<<"it does not form a valid triangle";
        }
    }
    private:
    bool isvalidTriangle(){
       return side1+side2>side3 && side1+side3>side2 && side2+side3>side1;
    }
};
int main()
{
    Triangle t1(9,9,12);
    t1.checkTriangle();
    return 0;
}
```
### check valid Date
```cpp
    #include <iostream>
    using namespace std;
    class Date{
        private:
        int date;
        int month;
        int year;
        public:
        Date(int d,int m,int y):date(d),month(m),year(y){}
        bool validateDate(){
            if(date<1 || date>31){
                return false;
            }
            else if(month<1 || month>12){
                return false;
            }
            else if((month==4 || month==6 || month==9 || month==11) && date>30){
                return false;
            }
            else if(month==2){
                if((year%4==0 && year%100!=0) || (year%400==0)){
                    if(date>29){
                        return false;
                    }
                }
                else{
                   if(date>28){
                    return false;
                }
            }
            }
            return true;
        }
    };
    int main()
    {
        int date;
        int month;
        int year;
        cout<<"Enter date: ";
        cin>>date;
        cout<<"Enter month: ";
        cin>>month;
        cout<<"Enter Year: ";
        cin>>year;
        Date d1(date,month,year);
        if(d1.validateDate()){
            cout<<"It is a valid date!";
        }
        else{
            cout<<"No it is not a valid date...";
        }
        return 0;
    }
```
### allocate Grade to marks
```cpp
    #include <iostream>
    using namespace std;
    class student{
        private:
        string name;
        string standard;
        int rollno;
        double marks;
        public:
        student(string n,string s,int r,double m): name(n),standard(s),rollno(r),marks(m){}
        
        string calculateGrade(){
            if(marks>=90 && marks<=100){
                return "O";
            }
            else if(marks>=80 && marks<90){
                return "A";
            }
            else if(marks>=70 && marks<80){
                return "B";
            }
            else if(marks>=60 && marks<70){
                return "C";
            }
            else if(marks<60 && marks>=35){
                return "D";
            }
            else if(marks<35 && marks>=0){
                return "FAIL";
            }
            else{
                return "NOT APPLICABLE";
            }
            
            
        }
        void displayDetails(){
            cout<<"Name: "<<name<<endl;
            cout<<"Class: "<<standard<<endl;
            cout<<"Rollno: "<<rollno<<endl;
            cout<<"Marks: "<<marks<<endl;
            cout<<"Grade: "<<calculateGrade();
        }
    };
    int main()
    {
        string name;
        string standard;
        int rollno;
        double marks;
        
        cout<<"Enter name: ";
        getline(cin,name);
        cout<<"Enter class: ";
        getline(cin,standard);
        cout<<"Enter rollno: ";
        cin>>rollno;
        cout<<"Enter marks: ";
        cin>>marks;
        
        student s1(name,standard,rollno,marks);
        s1.displayDetails();
       
        return 0;
    }
```

