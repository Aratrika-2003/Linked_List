#include<stdio.h>
#include<stdlib.h>

#define ITEM int
typedef struct st
{
	ITEM data;
	struct st* next;
	struct st* prev;
}Node;