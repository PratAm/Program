#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

struct node{
	int data;
	struct node* next;
};
 
int getCount(struct node * head)
{
	int count = 0;
	for(; head != NULL; head=head->next)
	{
		count++;
	}
	return count;
}

int _getIntersectionNode(struct node* first,struct node* second, int diff)
{
	for(int c = 0;c<diff;++c)
	{
		first = first->next;
	}

	while(first!= NULL and second!= NULL)
	{
		if(first == second)
			return first->data;
		else
		{
			first = first->next;
			second = second->next;
		}
	}
	return -1;
}

int getIntesectionNode(struct node * first,struct node * second)
{
	int c1 = getCount(first);
	int c2 = getCount(second);
	int diff = abs(c1-c2);

	if(c1 > c2)
	{
	  return _getIntersectionNode(first,second,diff);
	}
	else
	{
		return _getIntersectionNode(second,first,diff);
	}
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
 
  cout <<"\n The node of intersection is: " <<getIntesectionNode(head1, head2) << endl;
  return 1; 
}
