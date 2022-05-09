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
node* rec_rev(node* head)//recursively reversing the value in a linked list
{
    if(head != NULL)
        return rec_rev(head->next);

    printf("%d ",head->data);
}

void print_reverse(node** pthead)//printing the linked list in reverse order
{
    node* temp;
    node* next;
    node* prev;
    if(*pthead == NULL || (*pthead)->next == NULL)
    {
        traverse(*pthead);
        return;
    }
    prev = NULL;
    temp = *pthead;
    next = NULL;
    while(temp != NULL)
    {
        temp = next;
        prev = temp;
        next = temp->next;
        temp->next = prev;
    }
    *pthead = prev;

    traverse(*pthead);
}

void reverse(node** head)//reverse the linked list
{
    node* current;
    node* previous;
    node* next;
    previous = NULL;
    current = *head;
    while(current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}
