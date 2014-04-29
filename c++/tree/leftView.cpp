#include<iostream>
#include"node.h"

using namespace std;

void printleftview(node* root, int curl, int* maxl)
{
	if(not root)
		return;
	if(curl > *maxl)
	{
		cout << root->data <<"--";
		*maxl = curl;
	}
	printleftview(root->left,curl+1,maxl);
	printleftview(root->right,curl+1,maxl);
}

int main()
{
	node* root = getTree();
	int maxl = 0;
	printleftview(root,1,&maxl);
	return 0;
}
