#include <stdio.h>
#include <stdlib.h>

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

// Time complexity: - O(n)
// Auxilary space:- O(n/k)  n = length of the linkedlist
struct node *reverse(struct node *head, int k)
{
    struct node *current = head;
    struct node *prev = NULL;
    struct node *temp = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        temp = current->next;
        current->next = prev;

        prev = current;
        current = temp;
        count++;
    }
    if (temp != NULL)
    {
        struct node *newHead = reverse(temp, k);
        head->next = newHead;
    }

    return prev;
}

// Time complexity: - O(n)
// Auxilary space:- O(n)
struct node *Reverse(struct node *head, int k)
{
    struct node *curr = head;

    struct node *prevFirst = NULL;
    bool isFirstPass = true;

    while (curr != NULL)
    {
        struct node *first = curr;
        struct node *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            struct node *temp = NULL;
            temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
            count++;
        }
        if (isFirstPass)
        {
            head = prev;
            isFirstPass = false;
        }

        else
        {
            prevFirst->next = prev;
        }

        prevFirst = first;
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

    head = Reverse(head, 3);
    traversal(head);
}