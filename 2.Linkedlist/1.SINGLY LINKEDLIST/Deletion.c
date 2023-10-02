#include <stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void intraversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
    // DELETE FROM FIRST
struct node *delete_from_first(struct node *head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    
    return head;
    
}
    // DELETE BETWEEN THE TWO ELEMENTS
struct node *delete_inbetween(struct node *head,int index)
{
    struct node *p=head;
    struct node *q=p->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
   // DELETE FROM THE END OF THE LIST
struct node *delete_from_end(struct node *head)
{
    struct node *p=head;
    struct node *q=p->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    q->next=NULL;
    
    return head;
}
    // DELETE THE GIVEN VALUE 
struct node *delete_node(struct node *head,int value)
{
    struct node *p=head;
    struct node *q=p->next;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }    
    return head;

}



int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    struct node *third=(struct node *)malloc(sizeof(struct node));
    struct node *fourth=(struct node *)malloc(sizeof(struct node));
    
    head->data=31;
    head->next=second;
    
    second->data=32;
    second->next=third;
    
    third->data=33;
    third->next=fourth;
    
    fourth->data=34;
    fourth->next=NULL;
    
    printf("Before deletion::\n");
    intraversal(head);
    
    //printf("After deletion::\n");
    // head=delete_from_first(head);
    // intraversal(head);
    
    // printf("After deletion::\n");
    // head=delete_inbetween(head,2);
    // intraversal(head);
    
    // printf("After deletion::\n");
    // head=delete_from_end(head);
    // intraversal(head);
    // return 0;
    
    printf("After deletion::\n");
    head=delete_node(head,34);
    intraversal(head);
    return 0;
}

