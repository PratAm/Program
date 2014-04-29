#include<iostream>
using namespace std;

int freq(int arr[],int size)
{
	if(size == 1)
		return arr[0];

  int gc =-1;
	int gv = -1;
	int v = arr[0];
	int c =1;

	for(int i =1;i<size;i++)
	{
		if(arr[i] == v)
			c++;
		else
		{
			if(gc < c)
			{
				gc = c;
				gv = v;
			}
			v = arr[i];
			c = 1;
		}
	}
	
			if(gc < c)
			{
				gc = c;
				gv = v;
			}

	return gv;
}

int main()
{
	int arr[] ={0,0,1,1,2,2,2,2,0,0,0,0,0};
	int size = sizeof(arr)/sizeof(arr[0]);

	cout << freq(arr,size) << endl;
}
