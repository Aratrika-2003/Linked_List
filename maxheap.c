#include<stdio.h>
#include<stdlib.h>
#define item int

typedef struct q
{
    item *arr;
    int rear,size;
}maxheap;

void init(maxheap* max,item n)
{
    max->arr = (item*)malloc(sizeof(item)*n);
    max->rear = -1;
    max->size = n;
}
item isfull(maxheap* max)
{
    if(max->rear == max->size - 1)
        return 1;
    else
        return 0;
}
item isempty(maxheap* max)
{
    if(max->rear == -1)
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
void insert(maxheap* max,item val)//enqueue
{
    int child,parent;
    if(isfull(max))
        return;
    else
    {
        max->rear++;
        max->arr[max->rear] = val;
        child = max->rear;
        while(child != 0)
        {
            parent = (child - 1)/2;
            if(max->arr[parent] < max->arr[child])
            {
                swap(&max->arr[parent],&max->arr[child]);
                child = parent;
            }
            else
                break;
        }
    }
}
item delete(maxheap* max)//dequeue
{
    item child,parent,t,val;

    if(isempty(max))
        return 0;
    
    t = max->arr[0];//root
    max->arr[0] = max->arr[max->rear];
    max->rear--;
    parent = 0;
    do
    {
        child = (2 * parent) + 1;
        if(child > max->rear)
            break;

        if(child < max->rear && max->arr[child] < max->arr[child + 1])
            child++;
        if(max->arr[parent] < max->arr[child])
        {
            swap(&max->arr[parent],&max->arr[child]);
            parent = child;
        }
        else
            break;
    } while (child <= max->rear);
    
    return t;
}
void display(maxheap* max)
{
    int i;
    for(i = 0; i < max->size; i++)
        printf("%d ",max->arr[i]);
}
int main()
{
    maxheap q;
   
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
  
    
  
    /*do
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
    } while (ch != 3);*/
    
    return 0;
}
