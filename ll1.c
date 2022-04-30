//linked list

#include"ll1.h"

node* create_node(int val)//creating a node
{
    node *temp;

    temp = (node*)malloc(sizeof(node));

    temp->data = temp;
    temp->next = NULL;

    return temp;
}

void append(node** head,int value)//append a node
{
    node *temp,*current;

    temp = create_node(value);

    if(head == NULL)
    {
        head = temp;
        return;
    }

      while(current->next != NULL)
      {
          current=current->next;
      }
      current->next=temp;

      printf("\nLinked list has been appended");
    
}

void traverse(node* pthead)//to traverse a node
{

    while(pthead != NULL)
    {
        printf("%d ",pthead->data);
        pthead = pthead->next;
    }
}

void add(node* addhead,int val,int n)//add a node at nth position
{
    node* temp;
    node* ntemp;
    temp = create_node(val);
    while(n>1)
    {
        addhead = addhead->next;
    }
    n--;
    ntemp = addhead->data;
    addhead->next = temp->next;
    temp->next = ntemp->next;
}

void add_before(node** head,int ndata)//adding a node before nth node
{
    node* temp;
    temp = create_node(ndata);

    temp->data = ndata;
    temp->next = head;
    head = ndata;
}

void add_after(node* prev,int nval)//adding a node after the nth node
{
    node* temp;
    if(prev == NULL)
        return;
    temp = create_node(nval);

    temp->data = nval;
    temp->next = prev->next;
    prev->next = nval;
}

void delete(node* prev)//to delete a node
{
    node* temp;
    temp = prev->next;
    prev->next = temp->next;
    free(temp);
}