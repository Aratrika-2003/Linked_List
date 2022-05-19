#include"doubll.h"

int main()
{
	
	Node *head = NULL;
	Node *tail = NULL;
	
	addend(&head,&tail,20);
	addend(&head,&tail,30);
	addbegin(&head,&tail,10);
	addend(&head,&tail,40);
	addend(&head,&tail,50);
	addend(&head,&tail,60);
	
	traverse_next(head);
	traverse_prev(tail);
	
	return 0;
	
}