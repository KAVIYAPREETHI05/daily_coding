### Encapsulation
 wrapping up of data and information in a single unit is called Encapsulation.
 
 It is defined as binding together the data and the functions that manipulate them.
 
 The function which we are making inside the class must use only member variables, only then it is called encapsulation.
 - data protection-Creating a class to encapsulate all the data and methods into a single unit.

 - information hiding-Hiding relevant data using access specifiers.

```cpp
#include<iostream>
class encap{
    private:
    int a;
    int b;
    public:
    int multiply(int a,int b){
        int c=a*b;
        return c;
    }
};
using namespace std;
int main(){
    int n;
    cin>>n;
    encap e1;
    cout<<e1.multiply(n,n);
    
}
```


```cpp
#include<iostream>
#include<string>
using namespace std;
class encap{
    private:
    string name;
    int id;
    public:
   encap(string name,int id){
       this->name=name;
       this->id=id;
   }
   
   string getname(){
       return name;
   }
   int getid(){
       return id;
   }
};
using namespace std;
int main(){
    string name;
    cin>>name;
    int id;
    cin>>id;
    encap e1(name,id);
    cout<<e1.getname()<<endl;
    cout<<e1.getid();
    
    
}
```
the variable name, id and the functions get() and set() are bound together which is nothing but encapsulation.
