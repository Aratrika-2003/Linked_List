#include<stdio.h>
#include<stdlib.h>

#define ITEM int
typedef struct st
{
	ITEM data;
	struct st* next;
	struct st* prev;
}Node;

Node* create_node(ITEM val)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	
	new_node->data = val;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	return new_node;
}

void addbegin(Node** head,Node** tail,ITEM d)
{
	Node* new_node = create_node(d);
	
	
	if(*head == NULL)
	{
		*head = new_node;
		*tail = new_node;
		return;
	}
	new_node->next = *head;
	(*head)->prev = new_node;
	 *head = new_node;
	 
}

void addend(Node** head,Node** tail,ITEM val)
{
	Node* new_node = create_node(val);
	
	if(*head == NULL)
	{
		*head = new_node;
		*tail = new_node;
		return;
	}
	new_node->prev = *tail;
	(*tail)->next = new_node;
	*tail = new_node;
	
}

void traverse_next(Node* pthead)
{
	while(pthead != NULL)
	{
		printf("%d ",pthead->data);
		pthead = pthead->next;
	}
	printf("\n");
}

void traverse_prev(Node* pttail)
{
	while(pttail)
	{
		printf("%d ",pttail->data);
		pttail = pttail->prev;
	}
}

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