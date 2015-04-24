#include<iostream>
using namespace std;

class A
{
    public:
    int a;
    A(int x):a(x){
        cout<<"A called"<<endl;
    }
};

class B
{
    public:
    int b;

		B():b(0){}
    B(int y):b(y){
        cout<<"B called"<<endl;
    }
    friend void swap(B& first, B& second) 
    {
        using std::swap; 
        swap(first.b, second.b); 
    }

    B& operator=( B obj)
   {
        cout<<"B assgn called"<<endl;
/*				if(this == &obj) 
					return *this;
        b = obj.b;
				return *this;
*/   
    swap(*this,obj);
		return *this;
 	     
   }

};

class C:public A
{
    public:
    int a;
    B obj;
    
    C(int x,int y,int z):A(x),a(y) {
    cout<<"C called"<<endl;
    obj = z;
    }
};

int main()
{
 C obj(1,2,3);   
   
   return 0;
}

