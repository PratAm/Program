#include<stdio.h>

#define SIZEOF(type,result)\
	do{\
	 type *p = 0;\
   result = (char*)(p+1)-(char*)p;\
	}while(0)
  

int main()
{
	int x =0;
	SIZEOF(int,x);
	printf("%d",x);
	return 0;
}
