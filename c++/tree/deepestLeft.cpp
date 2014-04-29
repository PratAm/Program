#include<iostream>
#include"node.h"
#include<queue>

using namespace std;

void maxdepthLeft(node* root,bool isLeft,int curl ,int *maxl, node** result)
{
  if(not root)
		return ;
	
	if(isLeft and not root->left and not root->right and curl > *maxl)
	{
	  *result = root;
		*maxl = curl;
		return;
	}
	maxdepthLeft(root->left,true,curl+1,maxl,result);
	maxdepthLeft(root->right,false,curl+1,maxl,result);
}

void maxdepthLeftIter(node* root)
{
 int result = -1;
 queue<node*> Q;
 Q.push(root);

  node * temp = NULL;

 while(not Q.empty())
 {
   temp = Q.front();
	 Q.pop();
	 if(temp->left)
	 {
	   Q.push(temp->left);
		 result = temp->left->data;
		 cout <<"value updated:"<<result<<endl;
	 }
	 if(temp->right)
	 {
		 Q.push(temp->right);
	 }
 }
 cout <<"result :" << result << endl;
}
int main()
{
	node* root = getTree();
	maxdepthLeftIter(root);
	
	node * result = NULL;
  int maxl = 0;
	maxdepthLeft(root,false,0,&maxl,&result);

	return 0;

}
