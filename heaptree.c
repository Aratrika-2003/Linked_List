#include<stdio.h>
#include<stdlib.h>
#define ITEM int
#define M 100
#define N 50

typedef struct 
{
    /* data */
    int a[N];
    int front,rear;
}queue;

typedef struct st
{
    ITEM arr[M];
    ITEM rear;
}Heap;

int isfull(queue* q)
{
    if((q->front == 0 && q->rear == N-1)||(q->front == q->rear+1))
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
void swap(int* a,int *b)
{
    int* t;
    t = a;
    a = b;
    b = t;
}

void enqueue(Heap *ptr, ITEM val)
{
    int child,parent;
    if(isfull(ptr))
        return;
    else
    {
        ++ptr->rear;
        ptr->arr[ptr->rear] = val;
    
        child = ptr->rear;
        while(child != 0)
        {
            parent = (child-1)/2;
            if(ptr->arr[parent] < ptr->arr[child])
            {
                swap(&ptr->arr[parent],&ptr->arr[child]);
                child = parent;
            }
            else
                break;
        }
    }
}

int dequeue(Heap* p)
{
    int child,parent;
    if(isempty(p))
        return 0;
    else
    {
        int temp = p->arr[0];
        p->arr[0] = p->arr[p->rear--];
        parent = 0;
        do
        {
            child = (2 * parent) + 1;
            if(child > p->rear)//left child range
                break;

            if(child < p->rear && p->arr[child] < p->arr[child + 1])
                ++child;//path or child selection

            if(p->arr[parent] < p->arr[child])
            {
                swap(&p->arr[parent], &p->arr[child]);
                parent = child;
            }

            else
                break;
        } while (child <= p->rear);
        
        return temp;
    }
}

void heapify(int a[],int n)
{
    int i,p,c;
    for(i = n-1; i >= 0; --i)
    {
        p = i;
        do
        {
            c = (2 * p) + 1;
            if(c >= n)
                break;
            
            if(c < n-1 && a[c] < a[c + 1])
                ++c;
            if(a[p] < a[c])
            {
                swap(&a[p],&a[c]);
                p = c;
            }
            else
                break;
        } while (c < n);
    }
}

void heapsort(int a[],int n)
{
    int i;
    heapify(a , n);
    for(i = n-1; i > 0; --i)
    {
        swap(&a[0], &a[i]);
        heapify(a , i);
    }
}

void selection_sort(int a[],int n)
{
    int p,i,j;
    for(i = 0; i < n-1; i++)
    {
        p = i;
        for(j = 0; j < n; j++)
        {
            if(a[j] < a[p])
                p = j;
        }

        if(p != i)
            swap(&a[p], &a[i]);
    }
}