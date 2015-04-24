#include<iostream>

using namespace std;

int main()
{
	char a[] = "amar pratap";
  char *b = "amar pratap";

	char *c = a;
	
  c[5] = 'z';

	cout << &a << " " << static_cast<void*>(b) << " " << static_cast<void*>(c) <<endl;
	cout << a <<endl;
	cout << b <<endl;
	cout << c <<endl;

	return 0;
}
