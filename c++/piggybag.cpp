#include <iostream>
#include <queue>
using namespace std;

struct node{
	int val;
	int level;
	node(int val, int level):val(val),level(level){}
};

node * makenode(int val,int level){
	return new node(val,level);
};

int findMinDays(node* root,int num){

	std::queue<node*> que;
	que.push(root);

	while( not que.empty()){
		node* temp = que.front(),*temp1;
		que.pop();
		if (temp->val == num)
			return temp->level;
		else{
			temp1 = makenode((temp->val)*2,(temp->level)+1);
			que.push(temp1);
			temp1 = makenode((temp->val)+1,(temp->level)+1);
			que.push(temp1);
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
	cout << day << " " << sizeof(node)<<endl;
	return 0;
}

