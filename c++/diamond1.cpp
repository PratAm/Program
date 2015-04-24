#include<iostream>

using namespace std;

class Base
{
    public:
        void doSomething(){}  
};

class Derived1:public virtual Base
{
    public:
       void doSomething(){}
};

class Derived2:public virtual Base
{
    public:
       void doSomething(){}
};

class Base1
{
  public:
     virtual void doSomething(){}
};

class Derived3:public Derived1,public Derived2,public Base1
{
    public:
       void doSomething(){}
};

int main()
{
    Base obj;
    Derived1 objDerived1;
    Derived2 objDerived2;
    Derived3 objDerived3;

    cout<<"\n Size of Base: "<<sizeof(obj);
    cout<<"\n Size of Derived1: "<<sizeof(objDerived1);
    cout<<"\n Size of Derived2: "<<sizeof(objDerived2);
    cout<<"\n Size of Derived3: "<<sizeof(objDerived3);
		cout <<endl;
    return 0;
}
