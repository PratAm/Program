#include<iostream>
#include<cstdio>

using namespace std;

bool isInterleaved(string &a, string &b,string &c)
{
	int i=0,j=0,k=0;

  while(k < c.length())
	{
		if(i <= a.length() and c[k] == a[i])
			i++;
		else if( j <= b.length() and c[k] == b[j] )
			j++;
		else
			return false;

		++k;
	}
	if(i <=a.length() or j <= b.length())
		return false;

	return true;
}


 

int main()
{
    string A = "AB";
    string B = "CD";
    string C = "ACBG";

    if (isInterleaved(A, B, C) == true)
        printf("%s is interleaved of %s and %s\n", C.c_str(), A.c_str(), B.c_str());
    else
        printf("%s is not interleaved of %s and %s\n", C.c_str(), A.c_str(), B.c_str());
 
    return 0;
}
