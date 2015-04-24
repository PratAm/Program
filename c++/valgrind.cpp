
#include<stdio.h>
#include<stdlib.h>
// valgrind --track-origins=yes --tool=memcheck --leak-check=yes --log-file=valgrind.log ./valgrind
int main()
{
  int i;
	int *a = new int[5];
	a[0]=0;
	a[2]=2;
	a[3]=3;
	a[4]=4;

	printf("%x %x %x\n",a,a+1,&a+1);
	printf("%p %p %p\n",a,a+1,&a+1);
  printf("[i]=%d",i);
	delete a;

	a[1] =1;
	printf("a[1]:%d",a[1]);
	return 0;
}
