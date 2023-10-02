#include <stdio.h>
#include<stdlib.h>

struct node* r=NULL;
struct node* f=NULL;
struct node
{
    int data;
    struct node* next;
};

void traversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void enqueue(int value)
{
    struct node* n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL)
    {
        printf("The queue is overflow\n");
    }
    else
    {
        n->data=value;
        n->next=NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else
        {
            r->next=n;
            r=n;
        }
   }
}

int dequeue()
{
    int value=-1;
    struct node* n=f;
    if(f==NULL)
    {
        printf(" The queue is underflow\n ");
    }
    else
    {
        f=f->next;
        value=n->data;
        free(n);
    }
    return value;
    
}


int main()
{
    printf(" Dequeuing element %d\n ", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("AFTER INSERTING THE element:::::\n");
    printf("Dequeuing element %d\n", dequeue());
    // printf("Dequeuing element %d\n", dequeue());
    // printf("Dequeuing element %d\n", dequeue());
    // printf("Dequeuing element %d\n", dequeue());
    traversal(f);
}

