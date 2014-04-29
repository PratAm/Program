#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<algorithm>

using namespace std;
struct node
{
    int data;
    struct node* next;
};

struct node* MergeList(struct node* h1, struct node* h2)
{
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;

    if(h2->data < h1->data) swap(h1, h2);

    while(h1->next != NULL && h2 != NULL){
        if(h1->next->data <= h2->data){
            h1 = h1->next;
        }
        else{
            struct node* t1 = h1->next;
            struct node* t2 = h2->next;

            h1->next = h2;
            h2->next = t1;
            h2 = t2;
        }
    }

    return h1;
}


void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
	printf("\n");
} 

struct node* push(int new_data)
{
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data  = new_data;
  new_node->next = NULL;     
	return new_node;
}


int main()
{
  /* Start with the empty list */
  struct node* res = NULL;
  struct node* a = NULL;
  struct node* b = NULL;  
 
  a = push( 3);
  a->next = push( 5);
  a->next->next = push( 7);
   
  a->next->next->next = push( 1);
  a->next->next->next->next = push( 2);
  a->next->next->next->next->next = push( 4);  

  struct node *temp =a;

  printList(a);            
  while(temp->next != NULL and temp->data < temp->next->data){
    temp = temp->next;
  }
  b = temp->next;
  temp->next = NULL;

  printList(a);            
  printList(b);            
	printf("split %d\n",b->data) ;

 
  res = MergeList(a, b); 
 
  printf("\n Merged Linked List is: \n");
  printList(res);            
 
  return 0;
}
