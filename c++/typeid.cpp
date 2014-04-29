#include <iostream>
#include <typeinfo>
using namespace std;

#define SIZE(a)\
	do{\
		size_t size = 0;\
		size = sizeof(typeid(a));\ 
    size;\
	}while(0)

int main() {
  int myArray[10];
	int a = 0;
  cout << typeid(myArray).name() << endl;
	a = SIZE(a);
  cout <<"size:" << a << endl;
}
