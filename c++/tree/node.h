// A Binary Tree Node
struct node
{
	struct node *left, *right;
	int data;
};

typedef struct node node;

node* newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

 node* getTree()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->right = newNode(7);
	root->right->right->right = newNode(8);
	root->right->left->right->left = newNode(9);
	root->right->right->right->right = newNode(10);
	return root;
}
