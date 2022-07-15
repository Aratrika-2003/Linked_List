#include<stdio.h>
#include<stdlib.h>
#define item int

typedef struct q
{
    item *arr;
    int rear,size;
}minheap;

void init(minheap* min,item n)
{
    min->arr = (item*)malloc(sizeof(item)*n);
    min->rear = -1;
    min->size = n;
}
item isfull(minheap* min)
{
    if(min->rear == min->size - 1)
        return 1;
    else
        return 0;
}
item isempty(minheap* min)
{
    if(min->rear == -1)
        return 1;
    else
        return 0;
}
void swap(item *a, item *b)
{
    item t;
    t = *a;
    *a = *b;
    *b = t;
}
void insert(minheap* min,item val)//enqueue
{
    int child,parent;
    if(isfull(min))
        return;
    else
    {
        min->rear++;
        min->arr[min->rear] = val;
        child = min->rear;
        while(child != 0)
        {
            parent = (child - 1)/2;
            if(min->arr[parent] > min->arr[child])
            {
                swap(&min->arr[parent],&min->arr[child]);
                child = parent;
            }
            else
                break;
        }
    }
}
item delete(minheap* min)//dequeue
{
    item child,parent,t,val;

    if(isempty(min))
        return 0;
    
    t = min->arr[0];//root
    min->arr[0] = min->arr[min->rear];
    min->rear--;
    parent = 0;
    do
    {
        child = (2 * parent) + 1;
        if(child > min->rear)
            break;

        if(child < min->rear && min->arr[child] > min->arr[child + 1])
            child++;
        if(min->arr[parent] < min->arr[child])
        {
            swap(&min->arr[parent],&min->arr[child]);
            parent = child;
        }
        else
            break;
    } while (child <= min->rear);
    
    return t;
}
void display(minheap* min)
{
    int i;
    for(i = 0; i < min->size; i++)
        printf("%d ",min->arr[i]);
}
int main()
{
    minheap q;
    
    init(&q,7);
    
    insert(&q,98);
    insert(&q,9);
    insert(&q,48);
    insert(&q,10);
    insert(&q,2);
    insert(&q,64);
    insert(&q,50);
    
    display(&q);
    
    printf("\n");
    
    printf("\nThe deleted items - %d ",delete(&q));
    printf("\nThe deleted items - %d ",delete(&q));
    printf("\nThe deleted items - %d ",delete(&q));
    printf("\nThe deleted items - %d ",delete(&q));
    printf("\nThe deleted items - %d ",delete(&q));
    printf("\nThe deleted items - %d ",delete(&q));
    printf("\nThe deleted items - %d ",delete(&q));
  
    
    return 0;
}
