#include "list.h"

void reverselist(struct node ** head, struct node * cur, struct node * prev){
 
	if(NULL == cur->next){
		*head = cur;
		cur->next = prev;
		return;
	}

	reverselist(head,cur->next, cur);
	cur->next = prev;

}

int main(){

	struct node * head = getlist();
	reverselist(&head, head ,NULL);
	printList(head);
	return 0;
}
