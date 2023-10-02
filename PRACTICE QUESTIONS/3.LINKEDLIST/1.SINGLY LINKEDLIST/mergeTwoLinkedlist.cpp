
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct node *merge(struct node *a, struct node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    struct node *head = NULL;
    struct node *tail = NULL;
    if (a->data <= b->data)
    {
        head = tail = a;
        a = a->next;
    }

    else
    {
        head = tail = b;
        b = b->next;
    }

    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }

        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if (a == NULL)
        tail->next = b;
    else
        tail->next = a;

    return head;
}

int main()
{
    struct node *a = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));
    struct node *sixth = (struct node *)malloc(sizeof(struct node));

    a->data = 1;
    a->next = second;

    second->data = 6;
    second->next = third;

    third->data = 7;
    third->next = fourth;

    fourth->data = 9;
    fourth->next = fifth;

    fifth->data = 13;
    fifth->next = sixth;

    sixth->data = 23;
    sixth->next = NULL;

    struct node *b = (struct node *)malloc(sizeof(struct node));
    struct node *second1 = (struct node *)malloc(sizeof(struct node));
    struct node *third1 = (struct node *)malloc(sizeof(struct node));
    struct node *fourth1 = (struct node *)malloc(sizeof(struct node));
    struct node *fifth1 = (struct node *)malloc(sizeof(struct node));
    struct node *sixth1 = (struct node *)malloc(sizeof(struct node));

    b->data = 2;
    b->next = second1;

    second1->data = 8;
    second1->next = third1;

    third1->data = 10;
    third1->next = fourth1;

    fourth1->data = 11;
    fourth1->next = fifth1;

    fifth1->data = 12;
    fifth1->next = sixth1;

    sixth1->data = 20;
    sixth1->next = NULL;

    struct node *head = merge(a, b);
    traversal(head);
}