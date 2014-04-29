#include<iostream>

using namespace std;

long fact(long = 5);

int main()
{
int a = 0,b = 1,c = 2;

int &x = ++a;
int y = --b;
int z = c+b - -c;
cout << x <<" " <<y <<" " <<z << endl;
 cout << fact() << endl;
 return 0;
}

long fact(long x)
{
	return x;
}
