//to implement init,push,pop,peek,ismepty and isfull for stack
#include<stdio.h>
#define ITEM int
#define S 10
typedef struct
{
    ITEM arr[S];
    int tos;
}stack;

void init(stack *pts)
{
    pts->tos=-1;
}

int isfull(stack* s)
{
    if(s->tos==S-1)
        return 1;
    else 
        return 0;
}

int isempty(stack s)
{
    if(s.tos == -1)
        return 1;
    else
        return 0;
}

void push(stack *pts,int data)
{
    if(isfull(pts)==1)
        return;
    else
    {
        pts->tos++;
        pts->arr[pts->tos]=data;
    }
}
ITEM pop(stack *pts)
{
    ITEM tmp;
    if(isempty(*pts)==1)
        return ;
    else
    {
        tmp=pts->arr[pts->tos];
        pts->tos--;
        return tmp;
    }
}
ITEM peek(stack *pts)
{
    if(isempty(*pts)==1)
        return;
    else
        return pts->arr[pts->tos];
}

/*int main()
{
    stack *pts;
    int ch;
    printf("\nEnter choice ");
    scanf("%d",&ch);
    return 0;
}*/