#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
    int data;
    struct st* next;
}node;

node* create_node(int value);
void append(node** head, int value);
void traverse(node* head);
void add(node* addhead,int val,int n);
void add_before(node** head,int ndata);
void add_after(node* prev,int nval);
void delete(node* prev);