#include <stdio.h>
#include<stdlib.h>

struct node
{
    int size;
    int r;
    int f;
    int * arr;  
};

int empty(struct node* ptr)
{
    if(ptr->r==ptr->f)
    {
        return 1;
    }
    return 0;
}

int full(struct node* ptr)
{
    if(ptr->r==ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct node* ptr,int data)
{
    if(full(ptr))
    {
        printf("The queue is overflow\n");
    }
    else
    {
        ptr->r=ptr->r+1;
        ptr->arr[ptr->r]=data;
    }
}

int dequeue(struct node* ptr)
{
    int value =-1;
    if(empty(ptr))
    {
        printf("The queue is underflow\n");
    }
    else
    {
        ptr->f++;
        value=ptr->arr[ptr->f];
    }
        return value;
}


int main()
{
    struct node* sp=malloc(sizeof(struct node));
    sp->size=100;
    sp->r=-1;
    sp->f=-1;
    sp->arr=(int *)malloc(sp->size * sizeof(int));
    
    int node;
    int i=0;
    int visited[7]={0,0,0,0,0,0,0};
    int A[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d ",i);
    visited[i]=1;
    enqueue(sp,i);
    while(!empty(sp))
    {
        int node=dequeue(sp);
        for (int j = 0; j < 7; j++) {
            if(A[node][j]==1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j]=1;
                enqueue(sp,j);
            }
        }
        
    }
    return 0;
}
