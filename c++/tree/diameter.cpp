#include<iostream>
#include<queue>
#include"node.h"

using namespace std;

int getDiameter(node* root)
{
	queue<node*> Q;
	Q.push(root);
	Q.(NULL);

	node * cur = root;
	cout << cur->data;

	while(1)
	{
		cur = Q.top();
		Q.pop();
		if(cur != NULL)
		{
			if(cur->left!=NULL)
				q.push(cur->left);

			if(cur->right!=NULL)
				q.push(cur->right);
		}
		else if (cur == NULL and Q.empty())
    {
      break;
    }
		else
		{
			Q.push(NULL);
			node* temp = Q.top();
			cout << temp->data;
		}

	}
}

int main()
{
	node* root = getTree();
	getDiameter(root);
	return 0;

}
