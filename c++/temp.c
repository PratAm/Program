#include<stdio.h>
/*
test(){ // default return is int
return 3; 
} 
void main(){ 
int i=2; 
for(test();test();test()) 
{ 
printf("2"); 
} 
}
*/
#include<stdio.h> 
void fun(void *p); 
int i; 
int main() 
{ 
	void *vptr; 
	vptr = &i; 
	fun(vptr); 
	return 0; 
} 
void fun(void *p) 
{ 
	int **q; 
	q = (int**)&p; 
	printf("%d ", **q); 
}
