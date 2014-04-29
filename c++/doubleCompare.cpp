#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
double a,b,c;
a = 795.53;
b = 795.54;

cout<< "binary representation"<<endl;
//cout << a << "\t" << b << "\t" << c <<endl;

c = fabs(b - a);
printf("%.16f,%.16f,%.16f\n",a,b,c);
printf("%lf\n", c);

if (c >= 0.01)
printf(">=0.01\n");
else
printf("<0.01\n"); // after run, we're here

return 0;
}
