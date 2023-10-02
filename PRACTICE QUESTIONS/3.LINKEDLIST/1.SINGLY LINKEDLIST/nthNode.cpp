#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

// NAIVE APPROACH
void nthNode(struct node *head, int k)
{
    struct node *curr;
    int len = 0;

    for (curr = head; curr != NULL; curr = curr->next)
    {
        len++;
    }

    if (len < k)
    {
        return;
    }

    curr = head;
    for (int i = 1; i < len - k + 1; i++)
        curr = curr->next;

    cout << "The node is : " << curr->data;
}

// EFFICIENT APPROACH

void NthNode(struct node *head, int k)
{
    if (head == NULL)
    {
        return;
    }

    struct node *fast = head;
    for (int i = 0; i < k; i++)
    {
        if (fast == NULL)
            return;
        fast = fast->next;
    }

    struct node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    cout << "The node is : " << slow->data;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    nthNode(head, 3);
    printf("\n");
    NthNode(head, 3);
}