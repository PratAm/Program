#include<iostream>

using namespace std;

int temp = 10;

void fun(int & a= temp)
{
	cout<< "value of parameter:"<< a << endl;
}

int main()
{
	fun();
	return 0;
}
