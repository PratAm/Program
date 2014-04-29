#include<iostream>
#include<cstdlib>

using namespace std;

int getNoOfPaths(int m,int n)
{
	char (*p)[n] = (char(*)[n])malloc(m*n*sizeof(char));
	if(not p)
		return -1;
	for(int i =0;i <m ;++i)
		p[i][0]=1;

	for(int i =0;i <n ;++i)
		p[0][i]=1;

	 for(int i =1;i<m;++i)
	 {
		 for(int j =1;j<n;++j)
		 {
			 p[i][j] = p[i][j-1] + p[i-1][j];
		 }
	 }
	 return p[m-1][n-1];
}

int main()
{
	cout <<"no of paths: " << getNoOfPaths(3,3) <<endl;
	cout <<"no of paths: " << getNoOfPaths(4,4) <<endl;
	
	return 0;
}
