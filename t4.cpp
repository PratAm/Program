#include<iostream>
using namespace std;

static double gd;
static float gf;
static double gc;
static double gs =0;

class base
{
	public:
		void display(double x = 0.0,float y =0.0,char z = 'A')
		{
			gd = x;
			gf =y;
			gc = int (z);
			gs = gd+gf+gc;
			cout << gs;
		}
};


class basetwo
{
	public:
		void display(int x = 1,float y =0.0,char z = 'A')
		{
			gd = x;
			gf =y;
			gc = int (z);
			gs = gd+gf+gc;
			cout << gs;
		}
};

class derived:public base,basetwo
{
	void show()
	{
	 cout << gs;
	}
};

int main()
{
 derived obj;
 obj.basetwo::display(10.20,'Z');
 return 0;
}
