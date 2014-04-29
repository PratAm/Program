#include<iostream>
using namespace std;
class base
{
	public:
	virtual void display()=0;
	
};

void base:: display()
{
	cout<<"in base display()"<<endl;
}

class d1:public base
{
	private:
	void display()
	{
		cout <<"in d1 display()"<<endl;
	}
};

class d2:public base
{
	void display()
	{
		cout <<"in d2 display()"<<endl;
	}
};

int main()
{
	base *bptr = NULL;
	
	bptr = new d1();
	bptr->display();

//	bptr = new d2();
//	bptr->base::display();

	return 0;
}
