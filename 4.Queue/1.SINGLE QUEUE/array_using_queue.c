#include <stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int b;
    int f;
    int *arr;
};

int empty(struct queue* ptr)
{
    if(ptr->f==ptr->b)
    {
        return 1;
    }
    return 0;
}

int full(struct queue* ptr)
{
    if(ptr->b==ptr->size-1)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue* ptr,int value)
{
    if(full(ptr))
    {
        printf("the queue is overflow\n");
    }
    else
    {
        ptr->b=ptr->b+1;
        ptr->arr[ptr->b]=value;
    }
}

int dequeue(struct queue* ptr)
{
    int a=-1;
    if(empty(ptr))
    {
        printf("the queue is underflow\n");
    }
    else
    {
        ptr->f++;
        a=ptr->arr[ptr->f];
    }
    return a;
}

int main()
{
    struct queue sp;
    sp.size=100;
    sp.f=-1;
    sp.b=-1;
    sp.arr=(int *)malloc(sp.size *sizeof(int));
    
    enqueue(&sp,34);
    enqueue(&sp,44);
    enqueue(&sp,99);
    printf("The dequeue value is %d\n",dequeue(&sp));
    // printf("The dequeue value is %d\n",dequeue(&sp));
    // printf("The dequeue value is %d\n",dequeue(&sp));
    if(empty(&sp))	
    {
        printf("The queue is empty\n");

    }
    if(full(&sp))
    {
        printf("The queue is full\n");
    }
    
    return 0;
}

