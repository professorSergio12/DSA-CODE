#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void intraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *removeDuplicate(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            struct node *ptr = curr->next;
            curr->next = curr->next->next;
            free(ptr);
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 20;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 20;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 40;
    fifth->next = NULL;

    head = removeDuplicate(head);
    intraversal(head);
}