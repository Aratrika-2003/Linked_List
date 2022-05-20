#include"doubll.h"

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
	while(pttail != NULL)
	{
		printf("%d ",pttail->data);
		pttail = pttail->prev;
	}
}

void del_end(Node **tail)
{
	Node* temp;
	
	if(*tail == NULL)
		return;
	
	temp = *tail;
	(*tail)->prev->next = NULL;
	*tail = (*tail)->prev;
	
	free(temp);
}

void del_beg(Node **head)
{
	Node* temp;
	
	if(*head == NULL)
		return;
	
	temp = *head;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	
	free(temp);
}

void add_in_btw_after(Node* position,int val)
{
	Node* temp;
	
	temp = create_node(val);
	
	temp->prev = position;
	temp->next = position->next;
	position->next->prev = temp;
	position->next = temp;
}

void add_in_btw_bef(Node* pos,int value)
{
	Node* temp;
	
	temp = create_node(value);
	
	temp->next = pos;
	temp->prev = pos->prev;
	pos->prev->next = temp;
	pos->prev = temp;
}

Node* search_by_pos(Node* pthead, int pos)
{
	int i = 1,c = 1;
	
	if(pthead == NULL)
	{
		printf("\nInvalid");
		return NULL;
	}
	
	if(pos <= 0)
	{
		printf("\nInvalid");
		return NULL;
	}
	
	if(pthead != NULL)
	{
		pthead = pthead->next;
		c++;
	}
	
	if(pos > c)
	{
		printf("\nInvalid");
		return NULL;
	}
	
	for(i = 0;i < pos; i++)
	{
		pthead = pthead->next;
	}
	
	return pthead;
}

void del_in_btw_aft(Node* head,int pos)
{
	Node* pth = search_by_pos(head,pos);
	
	Node* temp = pth->next;
	temp->next->prev = pth;
	pth->next = temp->next;
}

void del_in_btw_bef(Node* tail,int pos)
{
	Node* pttail = search_by_pos(tail,pos);
	Node* temp = pttail->prev;
	temp->prev->next = pttail;
	pttail->prev = temp->prev;
}
