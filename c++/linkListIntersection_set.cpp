#include<iostream>
#include<cstdlib>
#include<set>

using namespace std;

struct node{
	int data;
	struct node* next;
};


int getIntersectionNode(struct node* first, struct node* second)
{
  std::set<struct node*> hash;
  while(first != NULL)
	{
		hash.insert(first);
		first = first->next;
	}
	while(second != NULL)
	{
		if(hash.end() != hash.find(second))
		  return second->data;
		second = second->next;
	}
	return -1;
}

int main()
{
 
  struct node* newNode;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;
 
  struct node* head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  cout <<"\n The node of intersection is: " <<getIntersectionNode(head1, head2) << endl;
  return 1; 
}
