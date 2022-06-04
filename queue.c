//to implement queue

#include<stdio.h>
#define ITEM int
#define n 50

typedef struct 
{
    /* data */
    ITEM a[n];
    int front,rear;
}queue;

void init(queue *ptq)
{
    ptq->front = -1;
    ptq->rear = -1;
}

int isfull(queue* q)
{
    if((q->front == 0 && q->rear == n-1)||(q->front == q->rear+1))
        return 1;
    else
        return 0;
}

int isempty(queue* ptq)
{
    if(ptq->front == -1 && ptq->rear == -1)
        return 1;
    else
        return 0;
}
void enqueue(queue* q,ITEM val)
{
    if(isfull(q)==1)
        return;
    else
    {
        if(q->front == -1)//if the previous space is empty
            q->front = 0;//updating front end to 0
        
        if(q->rear == n-1)
            q->rear = 0;
        else
            ++q->rear;

        q->a[q->rear] = val;

        printf("\nElements have been succesfully inserted ");
    }
}

int dequeue(queue* q)
{
	queue* temp;
	if(isempty(q)==1)
		return 0;
	else
	{
		temp = q->a[q->front];
		
		if(q->front == q->rear)
		{
			q->front = -1;
			q->rear = -1;
		}
		else if(q->front == n-1)
			q->front = 0;
		else
			q->front++;
	}
	
	return temp;
}

int main()
{
    queue q;

    init(&q);
    enqueue(&q,1);
    enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	enqueue(&q,5);
	printf("\nThe elements have been deleted ",dequeue(&q));
    return 0;
}