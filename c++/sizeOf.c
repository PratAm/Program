#include<stdio.h>

#define SIZEOF(type)\
do{\
		int result;\
	 type *p = 0;\
   result = (char*)(p+1)-(char*)p;\
		result;\
	 }while(0)
  

int main()
{
	int x =0;


	x = SIZEOF(double);
	printf("%d",x);
	return 0;
}
