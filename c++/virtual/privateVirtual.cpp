#include<iostream>

using namespace std;

class A
{
  int a;
	public:
	A():a(5),d(6){
	 cout <<"called base a"<<endl;
	}
	A(int a):a(a){
	 cout <<"called base a+"<<endl;
	}
	~A(){
	 cout <<"called a"<<endl;
	}
	int d;
};

class B:private A
{
	int b;
	public:
	B(){
	  cout << b <<" " <<d<< endl;
	}
	~B(){
	//	~A();
	 cout <<"called B"<<endl;
	}
};

class C:public B
{
	C()
	{
//		cout << d << endl;
	}
};

int main()
{
	B obj++++;
	return 0;

}
