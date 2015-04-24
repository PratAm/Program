#include<iostream>

using namespace std;

class A{
	public:
 virtual ~A()
 {
  cout << "distructor of A"<<endl;
 }
};

class B : public A{
	public:
 virtual ~B()
 {
  cout << "distructor of B"<<endl;
 }

};

int main()
{
	A a;
	B b;
	A *ap = dynamic_cast<A*>(&b);
	
	B *bp = dynamic_cast<B*>(ap);
  if(bp)
		cout << "cast 1 successful"<<endl;

	bp = dynamic_cast<B*>(&a);
  if(bp)
		cout << "cast 2 successful"<<endl;
	
	B &br = dynamic_cast<B&>(a);
}
