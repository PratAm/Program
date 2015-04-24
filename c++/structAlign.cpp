#include<iostream>

using namespace std;

struct{
	double a;   //-malign-double option during compilation for 8 byte aligned
	int b;
}a;

int main()
{
	cout << sizeof(a) <<endl;
	return 0;
}
