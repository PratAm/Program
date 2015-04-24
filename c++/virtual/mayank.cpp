#include<iostream>

using namespace std;

struct A
{
 void fun(){
	 cout << "in A"<<endl;
 }
};

struct B
{
 virtual ~B(){}

 virtual void fun1(){
	 cout << "in B"<<endl;
 }
};

struct C:public A,public B
{
	int a;
	C()
	{
		cout << "object C created" <<endl;
		a=5;
	}
	~C()
	{
		cout << "object C deleted" <<endl;
	}
 void fun1()
 {
	 cout << "in C"<<endl;
 }
};

int main()
{
	C *obj = new C();

	A *a = obj;
	B *b = obj;

	delete a;
	b->fun1();

	return 0;
}
