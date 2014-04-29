#include<iostream>
using namespace std;
/*
class a{
 virtual ~a()
 { }
};

class b:protected a{};

int sum( int a){return 1+a;}

sum(int a) fun()
{
 cout << a;
 return sum(5);
}
*/

static int b = 0;

void display(int *x, int *y = &b)
{
 cout << *x << " " << *y;
}

int temp(int x,int y=5 ,int z=5){
// return (++x * ++y +(int)++z);
 return (++x *++y* --z);
}

int main()
{
//	int a = sum()fun();
//	cout << temp(5,0,0);
	int a = 10,b =20;
	display(&a,&b);
 return 0;
}
