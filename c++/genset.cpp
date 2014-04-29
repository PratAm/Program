#include<iostream>
#include<set>

using namespace std;

string result;

void permutate()
{
	Permutate(0);
}

void Permutate(int no)
{
	if(result.size()==3)
		return;

	for(int i = no ;i <3;i++)
	{
result.push_back(input[i]);
    //print
		Perutate(i+1);

