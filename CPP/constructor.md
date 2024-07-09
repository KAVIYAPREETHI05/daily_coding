### Constructor

- Constructor is a member function of a class, whose name is the same as the class name.

- It is a special type of member function that is used to initialize the data members for an object of a class automatically when an object of the same class is created.

- Constructor is invoked at the time of object creation. It constructs the values i.e. provides data for the object that is why it is known as a constructor.

- They do not return value, hence they do not have a return type.


## constructor within the class
``class-name(parameters){
//definition
}
``
```cpp
#include <iostream>
#include<cmath>
using namespace std;
class square{
    private:
    double number;
    public:
    square(int n){
//constructor definition
        number=n;
    }
    void display(){
        int square=pow(2,number);
        cout<<square;
    }
};
int main()
{
    square s1(2);
    s1.display();
    return 0;
}
```
## constructor outside the class
``class-name :: class-name(parameters){
//definition
}
``
```cpp
#include <iostream>
#include<cmath>
using namespace std;
class square{
    private:
    double number;
    public:
    square(int n);
    void display();
};
square::square(int n){
    number=n;
}
void square::display(){
        int square=pow(number,2);
        cout<<square;
    }
int main()
{
    square s1(2);
    s1.display();
    return 0;
}
```
Assignment in constructor body
```cpp
class constructor{
    private:
    double number;
    int age;
    public:
    constructor(int n,int a){
        number=n;
        age=a;
    }
```
Constructor initialization list
```cpp
class constructor{
    private:
    double number;
    int age;
    public:
    constructor(int n,int a):number(n),age(a){}
```
### Types of Constructors
- Default Constructors
-  parameterized Constructors
-  copy Constructors
-  move Constructors

 ## 1.Default constructor
 It does not take any argument. It has no parameter. (zero-argument constructor).
 ```cpp
#include <iostream>
using namespace std;
class constructor{
    public:
    int a;
    double b;
    constructor(){
        a=10;
        b=2.3;
    }
};
int main()
{
    constructor c1;
    cout<<c1.a<<" "<<c1.b;
    return 0;
}
```
```cpp
#include <iostream>
using namespace std;
class constructor{
    public:
    int a=10;
    double b=2.3;
    //implicit default constructor
   
};
int main()
{
    constructor c1;
    cout<<c1.a<<" "<<c1.b;
    return 0;
}
```
## 2.Parameterized Constructor
It uses parameters to initialize the object.
```cpp
#include <iostream>
using namespace std;
class constructor{
    private:
    int Id;
    double Salary;
    public:
    constructor(int a,double s ){
        Id=a;
        Salary=s;
    }
    int getId(){
        return Id;
    }
    double getsalary(){
        return Salary;
    }
};
int main()
{
    constructor c1(10,10000.2);
    cout<<c1.getId()<<" "<<c1.getsalary();
    return 0;
}
```
```cpp
#include <iostream>
using namespace std;
class constructor{
    private:
    int Id;
    double Salary;
    public:
    constructor(int a,double s);
    int getId();
    double getsalary();
};
//constructor outside class
constructor :: constructor(int a,double s=1000.2 ){
        Id=a;
        Salary=s;
    }
 int constructor :: getId(){
        return Id;
    }
  double constructor ::  getsalary(){
        return Salary;
    }
int main()
{
    constructor c1(10);
    cout<<c1.getId()<<" "<<c1.getsalary();
    return 0;
}
```
## 3.Copy constructor
It is a member function that initializes an object using another object of the same class.
```cpp
#include <iostream>
using namespace std;
class constructor{
    private:
    int Id;
    double Salary;
    public:
    constructor(int a,double s);
    int getId();
    double getsalary();
};
constructor :: constructor(int a,double s=1000.2 ){
        Id=a;
        Salary=s;
    }
 int constructor :: getId(){
        return Id;
    }
  double constructor ::  getsalary(){
        return Salary;
    }
int main()
{
    constructor c1(10);
    cout<<c1.getId()<<" "<<c1.getsalary()<<endl;
    constructor c2(c1); //c2=c1
    cout<<c2.getId()<<" "<<c2.getsalary();
    
    return 0;
}
```
```cpp
#include <iostream>
using namespace std;
class constructor{
    private:
    int Id;
    double Salary;
    public:
    constructor(int a,double s);
    constructor(constructor&obj1);
    int getId();
    double getsalary();
};
constructor :: constructor(int a,double s=1000.2 ){
        Id=a;
        Salary=s;
    }
//copy constructor
constructor :: constructor(constructor&obj1){
    Id=obj1.Id;
    Salary=obj1.Salary;
}
 int constructor :: getId(){
        return Id;
    }
  double constructor ::  getsalary(){
        return Salary;
    }
int main()
{
    constructor c1(10);
    cout<<c1.getId()<<" "<<c1.getsalary()<<endl;
    constructor c2(c1);//copy constructor called (passing obj of constructor)
    cout<<c2.getId()<<" "<<c2.getsalary();
    
    return 0;
}
```
## 4.Move constructor
 It is like a copy constructor that constructs the object from the already existing objects., but instead of copying the object in the new memory, it makes use of move semantics to transfer the ownership of the already created object to the new object without creating extra copies.
 ```cpp
#include <iostream>
using namespace std;
class constructor{
    public:
    int *a;
    constructor(int value){
        a=new int;
        *a=value;
    }
    //move constructor
    constructor(constructor&& obj) noexcept
    {
        a=obj.a;
        obj.a=nullptr;
    }
    ~constructor(){delete a;}
};
int main()
{
    constructor c1(10);
    constructor c2(move(c1));//move constructor called
    cout<<*c2.a;
    return 0;
}
```
```cpp
#include <iostream>
using namespace std;
class constructor{
    public:
    int *Id;
    double *salary;
    constructor(int a,double s){
        Id=new int;
        salary=new double;
        *Id=a;
        *salary=s;
    }
    //move constructor
    constructor(constructor&& obj) noexcept
    {
        Id=obj.Id;
        obj.Id=nullptr;
        salary=obj.salary;
        obj.salary=nullptr;
    }
    ~constructor(){
        delete Id;
        delete salary;
        
    }
};
int main()
{
    constructor c1(10,1000.2);
    constructor c2(move(c1));//move constructor called
    cout<<*c2.Id<<" "<<*c2.salary;
    return 0;
}
```
 
