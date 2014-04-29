#include<stdio.h>

int main()
{
	int a[] = {1,2,3,4,5};

	printf("%x %x %x\n",a,a+1,&a+1);
	printf("%p %p %p\n",a,a+1,&a+1);

	return 0;
}
