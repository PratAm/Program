#include<iostream>

using namespace std;

struct temp
{
  int arr[5];
	void t1(void);
	void d1(void);

};

void temp::d1(void)
{
 for(int i =0;i<5;i++)
	 cout <<arr[i] <<" ";
}

void temp::t1(void)
{
 static int i=0,j=4;
 int tmp = arr[i];
 arr[i]= arr[j];
 arr[j]= tmp;
 i++;
 j--;
 if(j!=i) t1();
}

int main()
{
 temp obj = {{5,6,3,9,0}};
 obj.t1();
 obj.d1();
 return 0;
}
