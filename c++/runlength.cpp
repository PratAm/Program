#include<bits/stdc++.h>
using namespace std;

string Encode(string A)
{
	int length;
	if( (length = A.length()) == 0)
		return "";
	string B = "";

	for(int i=0;i<length;i++)
	{
		B +=A[i];

		int count = 1;
		while((i+i < length) && (A[i]==A[i+1])){
		  	count++;
			  i++;
		}
		char arry[50];
		sprintf(arry,"%d",count);

		for(int i = 0;i < *(arry+i);++i){
			B += arry[i];
		}

	}
	return B;
}

int main(void)
{
	string S = "wwwwaaadexxxxxx";
	string A = Encode(S);
	cout<<A;
	return 0;
}
