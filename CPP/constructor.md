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
