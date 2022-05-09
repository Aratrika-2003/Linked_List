//implement circular linked list

#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
    /* data */
    int value;
    struct st* next;
}circular;

circular* create_node(int data)
{
    circular* temp;
    temp = (circular*)malloc(sizeof(circular));
    temp->value = temp;
    temp->next = NULL;

    return temp;
}

void add_before()
{
    int value;
    circular* last = NULL;
    circular** pthead;
    *pthead = create_node(value);

    printf("\nEnter the data to be inserted ");
    scanf("%d",&value);

    if(last == NULL)
    {
        (*pthead)->value = value;
        (*pthead)->next = pthead;
        last = pthead;
    }
    else
    {
        (*pthead)->value = value;
        last->next = *pthead;
    }
    
}

void traverse()
{
    circular* head;

    while(head != NULL)
    {
        printf("%d ",head->value);
        head = head->next;    
    }
}

void add_after()//insert after nth position
{
    circular *temp,*var,**pthead;
    int data,num;
    
    temp = (*pthead)->next;

    printf("\nEnter the nth position ");
    scanf("%d",&num);

    while(temp != (*pthead)->next)
    {
        var = create_node(data);

        printf("\nEnter the number to be inserted ");
        scanf("%d",&data);

        var->value = data;
        var->next = temp->next;
        temp->next = var;

        if(temp == NULL)
            *pthead = var;
        else
            temp = temp->next;
    }
}

void delete(int data)//delete at nth position
{
    int n, count = 1;
    circular *temp,*pos,**head = NULL;
    

    temp = (*head)->next;

    if(*head == NULL)
        return;
    else
    {
        printf("\nEnter the nth position ");
        scanf("%d",&n);

        while(count < n)
        {
            temp = temp->next;
            count++;
        }
        pos = temp->next;
        temp->next = pos->next;

        free(pos);
    }
}
