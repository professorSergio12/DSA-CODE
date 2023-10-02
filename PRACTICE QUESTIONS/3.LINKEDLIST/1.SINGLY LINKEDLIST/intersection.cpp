// Write a function to get the intersection point of two Linked Lists

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

int count(struct node *head)
{
    struct node *curr = head;
    int cnt = 0;
    while (curr != NULL)
    {
        curr = curr->next;
        cnt++;
    }
    return cnt;
}

int _getIntesectionNode(struct node *head, struct node *head1, int d)
{
    struct node *curr = head;
    struct node *curr1 = head1;

    for (int i = 0; i < d; i++)
    {
        if (curr == NULL)
        {
            return -1;
        }
        curr = curr->next;
    }

    while (curr != NULL && curr1 != NULL)
    {
        if (curr->data == curr1->data)
            return curr->data;

        curr = curr->next;
        curr1 = curr1->next;
    }
    return -1;
}
int getIntesectionNode(struct node *head, struct node *head1)
{
    int c1 = count(head);
    int c2 = count(head1);

    int d = abs(c1 - c2);
    if (c1 > c2)
        return _getIntesectionNode(head, head1, d);
    else if (c1 < c2)
        return _getIntesectionNode(head1, head, d);
    else
    {
        else
        {
            while (curr != NULL && curr1 != NULL)
            {
                if (curr != curr1)
                {
                    curr = curr->next;
                    curr1 = curr1->next;
                }
                else
                {
                    return curr;
                }
            }
            return NULL;
        }
    }
}
int main()

{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *second1 = (struct node *)malloc(sizeof(struct node));
    struct node *third1 = (struct node *)malloc(sizeof(struct node));
    struct node *fourth1 = (struct node *)malloc(sizeof(struct node));
    struct node *fifth1 = (struct node *)malloc(sizeof(struct node));

    head1->data = 4;
    head1->next = second1;

    second1->data = 9;
    second1->next = third1;

    third1->data = 3;
    third1->next = fourth1;

    fourth1->data = 7;
    fourth1->next = fifth1;

    fifth1->data = 6;
    fifth1->next = NULL;

    cout << "The node of intersection is " << getIntesectionNode(head, head1);

    return 0;
}
