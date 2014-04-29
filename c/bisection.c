#include<stdio.h>

int main()
{
	// variable initilization
  float f,x,a,b;

	// input data for program
	a = 5.23;
	b = -8.39;

	do
	{
		x = (a+b)/2.00;
		f = (x*x*x)-(2*x)-2; 

		if (f>0)
		{
			b=x;
		}
		else
		{
			a=x;
		}
		printf("\n\n\ta = %f   b = %f   f = %f",a,b,f);
	}while(b-a>0.0001);
  
	printf("\n The Root of the equation is %f\n",x);
  
 return 0;
}
