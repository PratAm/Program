#include<iostream>
using namespace std;
int main(){
	int a = 10;

	int &b = a;
  int *p = &b;

	cout << static_cast<void*>(&a) <<endl;
	cout << (void*)&b <<endl;
	cout << p <<endl;
	cout << *p <<endl;
	return 1;

}
