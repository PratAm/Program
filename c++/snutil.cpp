#include<iostream>

#include <stddef.h>

using namespace std;

typedef struct test
{
	int a;
	char b;
}test;

int main()
{
	test obj;
	cout << "address of offset :" <<hex << offsetof(test ,b) <<endl;
	return 0;
}
