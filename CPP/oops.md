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
