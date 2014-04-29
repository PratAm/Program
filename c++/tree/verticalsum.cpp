#include<iostream>
#include<map>
#include"node.h"

using namespace std;

std::map<int,int> sum;

void verticalsum(node* root,int level )
{
	if(not root)
		 return ;
	/*
	if(sum.find(level) == sum.end())
	{
	  sum[level] = root->data;
	}else
	{
	  sum[level] += root->data;
	}
	*/
	int prev = sum.count(level) ? sum[level] : 0 ;
	sum[level]= prev + root->data;

	verticalsum(root->left,level-1);
	verticalsum(root->right,level+1);
}

int main()
{
	node * root = getTree();

	verticalsum(root,0); 

	std::map<int,int> ::const_iterator it;
	for(it = sum.begin();it != sum.end();++it)
	{
		cout << "level" << it->first <<":" << it->second <<endl;
	}
	return 0;
}
