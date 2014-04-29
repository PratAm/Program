#include <stdio.h>
#include <iostream>
using namespace std;
const int SIZE = 40;
 
// generic sum function
template<class summable>
inline summable sum(summable data[], int size)
{
	summable sum = 0;
	for(summable i = 0; i < size; ++i)
		sum = sum + data[i];
	return sum;
}
int main()
{
	int data[SIZE];
 
	// initialize array
	for(int i = 0; i < SIZE; ++i)
		data[i] = i;
 
	// calculate the sum of values in array
	int accum = sum(data, SIZE);
 
	// print result
	cout<<"sum is "<<accum<<endl;
	return 0;
}
