#include<stdio.h>
#include<stdlib.h>
int main()
{
	int * arr = (int* )malloc(sizeof(int)*4);
	printf("address of array: %p",arr);

	for(int i=0;i<4;i++)
	{
		arr[i] = 4;
	}
	free(arr);
	return 0;
}
