#include <iostream>
#include <queue>
using namespace std;

struct node{
	int val;
	int level;
	node * left, *right;
	node(int val, int level):val(val),level(level),left(NULL),right(NULL){}
};

node * makenode(int val,int level){
	return new node(val,level);
};

int findMinDays(node* root,int num){

	std::queue<node*> que;
	que.push(root);

	while( not que.empty()){
		node* temp = que.front();
		que.pop();
		if (temp->val == num)
			return temp->level;
		else{
			root->left = makenode((temp->val)*2,(temp->level)+1);
			que.push(root->left);
			root->right = makenode((temp->val)+1,(temp->level)+1);
			que.push(root->right);
		}

	}
	return -1;
}

int main()
{
	int amount;
	cin>>amount;

	node * root = makenode(1,0); 

	int day = findMinDays(root,amount);


	//Output the minimum numbers of days required to make amount
	cout << day <<endl;
	return 0;
}

