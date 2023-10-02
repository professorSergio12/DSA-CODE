#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
// TRAVERSAL
void intraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
// INSERT AT FIRST POSITION
struct node *sortInsert(struct node *head, int x)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;

    if (head == NULL)
    {
        return ptr;
    }

    if (x < head->data)
    {
        ptr->next = head;
        return ptr;
    }

    struct node *p = head;
    while (p->next != NULL && p->next->data < x)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 6;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 73;
    third->next = fourth;

    fourth->data = 98;
    fourth->next = NULL;

    printf("Before insertion::\n");
    intraversal(head);

    head = sortInsert(head, 67);
    printf("After insertion::\n");
    intraversal(head);
}
