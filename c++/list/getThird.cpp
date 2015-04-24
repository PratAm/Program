
#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node* next;
};
 
struct node *newNode(int data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = newNode(new_data);
 
    new_node->next = (*head_ref);
 
    (*head_ref)    = new_node;
}

void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
int main(void)
{
    struct node* res = NULL;
    struct node* first = NULL;
 
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);
 
 
    res = getThird(first, 3);
    printf("Resultant node is %d",res->data );
    printList(res);
 
   return 0;
}
