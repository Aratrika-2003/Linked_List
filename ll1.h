#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
    int data;
    struct st* next;
}node;

node* create_node(int value);
void append(node** head, int value);
void traverse();
//void add(node* addhead,int val,int n);
void add_before(node** head,int ndata);
void add_after(node* prev,int nval);
void delete(node* prev);
void print_reverse(node** pthead);
void reverse(node** head);
node* rec_rev(node* head);
