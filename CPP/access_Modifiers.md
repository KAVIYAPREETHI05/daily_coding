### Access modifiers

It is also known as access specifiers.
Access Modifiers or Access Specifiers in a class are used to assign the accessibility to the class members

Types of access modifiers
- private
- public
- protected

**private**-only the member function or the friend function are allowed to access the private data member.(default)

**public**-it can be accessed from anywhere in the program using direct member access operator(.)

**protected**-it can be accessed either with the help of *friend function* or by using *derived class*.

### private
```cpp
#include <iostream>
using namespace std;
class circle{
    private:
    double radius;
    public:
    circle(double r): radius(r){}
    double findArea(){
        double area=3.14 *radius*radius;
        return area;
    }
};
int main()
{
    double r=2.3;
    circle c1(r);
    //cout<<c1.radius<<endl;(cannot access private variable)
    cout<<"Area of circle is: "<<c1.findArea();
    return 0;
}
```
### public
```cpp
#include <iostream>
using namespace std;
class circle{
    public:
    double radius;
    circle(double r): radius(r){}
    double findArea(){
        double area=3.14 *radius*radius;
        return area;
    }
};
int main()
{
    double r=2.3;
    circle c1(r);
    cout<<"Radius of circle:"<<c1.radius<<endl;
    cout<<"Area of circle is: "<<c1.findArea();
    return 0;
}
```
### protected
```cpp
#include <iostream>
using namespace std;
class parent{
    protected:
    double radius;
   };
class child: public parent{
    public:
    void setRadius(int r){
        radius=r;
    }
    void findArea(){
        cout<<"Area of circle is: "<<3.14*radius*radius;
    }
};
int main()
{
    double r=2.3;
    child c1;
    c1.setRadius(r);
    c1.findArea();
    return 0;
}
```
  
  
