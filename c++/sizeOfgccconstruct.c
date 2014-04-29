#include<stdio.h>

#define SIZEOF(type)\
	({\
		int result;\
	 type *p = 0;\
   result = (char*)(p+1)-(char*)p;\
		result;\
	 })
  
#define SIZE(type) (long int) (((type*)0)+1)

int main()
{
	int x =0,y=0,z=0;

  typedef struct {
		int a;
		char c;
		int d;
	} NODE;

	x = SIZEOF(double);
	z = SIZE(NODE);
	y = SIZEOF(NODE);
	printf("%d\n",x);
	printf("%d\n",y);
	printf("%d\n",z);
	return 0;
}
