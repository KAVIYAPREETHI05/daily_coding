### Destructor

It is the last function that is going to be called before the object is created.
- Destructor destroys the class objects created by the constructor.
- Destructor has the same name as their class name preceded by a tilde (~) symbol.
- It is not possible to define more than one destructor.
- The destructor is only one way to destroy the object created by the constructor. Hence destructor can-not be overloaded.
- Destructor neither requires any argument nor returns any value(not even void).
- It should be declared in public section of class. It i not possible to access the address of the destructor.

## Destructor within class
`` ~class-name(){//definition}``
```cpp
#include <iostream>
using namespace std;
class check{
    public:
       ~check(){
        cout<<"destructor called"<<endl;
        
    }
};

int main()
{
    check c1;
    return 0;
}
```

## Destructor outside the class
`` class-name :: ~class-name(){//definition}``
```cpp
#include <iostream>
using namespace std;
class check{
    public:
       ~check();
};
check :: ~check(){

        cout<<"destructor called"<<endl;
        
}

int main()
{
    check c1;
    return 0;
}
```
**Objects are destroyed in the reverse order of their creation.**

```cpp
#include <iostream>
using namespace std;
static int count=0;
class check{
    public:
    check(){
        count++;
        cout<<"constructor"<<count<<endl;
    }
    ~check(){
        cout<<"destructor"<<count<<endl;
        count--;
    }
};

int main()
{
    check c1,c2,c3;
    return 0;
}
```

