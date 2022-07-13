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
item delete(minheap* min,item val)//dequeue
{
    item child,parent,t;

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
    int size,ch,key;
    printf("\nEnter the size of the array ");
    scanf("%d",&size);

    init(&q,size);

    do
    {
        printf("\nPress 1 for insertion and 2 for deletion.\n");
        printf("\nEnter choice! ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter a number to insert - ");
            scanf("%d",&key);
            insert(&q,key);
            printf("\nThe key is inserted ");
            display(&q);
            break;

            case 2:
            printf("\nEnter a number to delete - ");
            scanf("%d",&key);
            delete(&q,key);
            printf("\nThe key is deleted ");
            display(&q);
            break;

            default:
                break;
        }
    } while (ch != 3);
    
    return 0;
}