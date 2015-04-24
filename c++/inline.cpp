#include<stdio.h>

static const int ptr =5;

inline int callfun(int a)
{
	printf("testing call\n");
  a = a+a;
	return a;
}

int main()
{
//	int x = callfun(6);
	printf("value %d %d\n",callfun(6),ptr);
	return 0;
}
