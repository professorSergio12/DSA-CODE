#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

// NAIVE APPROACH
void middleElement(struct node *head)
{
    if (head == NULL)
    {
        return;
    }

    struct node *curr;
    int count = 0;
    for (curr = head; curr != NULL; curr = curr->next)
    {
        count++;
    }

    curr = head;

    for (int i = 0; i < count / 2; i++)
        curr = curr->next;

    cout << "The middle middle element is: " << curr->data;
}

// EFFICIENT APPROACH

void MiddleElement(struct node *head)
{
    if (head == NULL)
    {
        return;
    }

    struct node *fast = head;
    struct node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    cout << "The middle element is: " << slow->data;
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

    middleElement(head);
}