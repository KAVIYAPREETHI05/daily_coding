### Friend Class and function

A friend function can access private and protected members of other classes in which it is declared as friend.

### Friend class

syntax

``friend class class_name; ``

```cpp
#include <iostream>
using namespace std;
class parent{
    protected:
    double a=2.3;
    private:
    double b=3.4;
    friend class child;//friend declaration
   };
class child{
    public:
    void display(parent obj){
        cout<<obj.a<<endl;
        cout<<obj.b<<endl;
    }
};
int main()
{
    parent p1;
    child c1;
    c1.display(p1);
    return 0;
}
```
### Friend Function

syntax

a global function

``friend return_type function_name (arguments);``

member function of another class

``friend return_type class_name::function_name (arguments); ``   

## global function
```cpp
#include <iostream>
using namespace std;
class parent{
    protected:
    double a=2.3;
    private:
    double b=3.4;
    friend void child(parent obj);//friend declaration
   };

    void child(parent obj){
        cout<<obj.a<<endl;
        cout<<obj.b<<endl;
    }

int main()
{
    parent p1;
    child(p1);
    return 0;
}
```
## member function of another class
```cpp
#include <iostream>
using namespace std;
class parent;//forward declaration of parent
class parent2{
    public:
     void child(parent obj);
};
class parent{
    protected:
    double a=2.3;
    private:
    double b=3.4;
    friend void parent2::child(parent obj);//friend declaration
   };
 //definition of friend function after parent class  
void parent2:: child(parent obj)
    {
        cout<<obj.a<<endl;
        cout<<obj.b<<endl;
    }
int main()
{
    parent p1;
    parent2 p2;
    p2.child(p1);
    return 0;
}
```
