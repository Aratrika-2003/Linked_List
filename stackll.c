//implement stack using linked list
#include"stackll.h"

void init(stack *shead)
{
	shead = NULL;
}

ITEM isempty(stack* head)
{
	if(head == NULL)
		return 1;
	else
		return 0;
}

void push(stack** head, int val)
{
	stack* temp =(stack*)malloc(sizeof(stack));

	temp->data = val;
	temp->next = NULL;
	stack* curr = *head;
	if(*head == NULL)
	{
		*head = temp;
		return;
	}
	while(curr->next != NULL)
    {
        curr=curr->next;

    }
    curr->next = temp;
}

ITEM pop(stack** tail)
{
	stack* curr = *tail;
	stack* temp = curr;

	if(isempty(*tail) == 1)
		return 0;
	else
	{
		while(curr->next != NULL)
		{
			temp = curr;
			curr = curr->next;
		}
	}
	temp->next = NULL;
	return curr->data;
	free(curr);
}

ITEM peek(stack* pts)
{
	if(isempty(pts) == 1)
		return;
	else
		return pts->data;
}
int main()
{
	stack* head = NULL;
	init(&head);
	
}