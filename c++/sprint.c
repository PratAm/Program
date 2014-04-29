#include<stdio.h>
#include<string.h>
int main()
{
	int a = 121;

	char t[20];
	sprintf(t,"%d",a);

	printf("size : %d\n", strlen(t));
  printf("%s",t);

	return 0;
}
