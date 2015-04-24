#include<bits/stdc++.h>

using namespace std;
class A;

class B {
	int b;
	B(){cout <<"B called"<<endl;};

	friend class A;
};


class A: private B{
	int a;
	public:
	A(){cout<<"A called" <<endl;}

};

class C: private A
{
	public:
	C(){cout <<"C called" <<endl;}
};

int main()
{
	C c;
	return 0;
}
