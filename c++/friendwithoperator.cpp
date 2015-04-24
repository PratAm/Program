#include<iostream>

using namespace std;
class A;

class B {
 public:
 int b;
	  B(int x):b(x){}
		B():b(5){cout <<"B called"<<endl;};

		void operator=(B obj){
			cout <<"overloaded\n";
			std::swap(this->b,obj.b);			
		}
    friend B operator+(B obj);
/*		B& operator+(B obj)
		{
			this->b += obj.b;
			return *this;
		}
*/
		void print()
		{
			cout<<"in print "<< this->b <<"\n";
		}

//	  friend class A;
};

B operator+(B obj,B obj2)
{
	return B(obj.b+obj2.b);
}

class A: private B{
	int a;
	public:
	A(){cout<<"A called" <<endl;}

};

class C: public A
{
	public:
	C(){cout <<"C called" <<endl;}
};

int main()
{
	C a;
	B b(10),b1(15),b2(20);
	b1.print();
//	b1 = b = b2; // this will not work if = return void 
	b1 =b;
	b1.print();

	B c = 5+b1;
	c.print();
	
	return 0;
}
