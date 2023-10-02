/*                        Pairwise swap elements of a linked list
This problem is part of GFG SDE Sheet. Click here to view more.  Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.
Note: You need to swap the nodes, not only the data. If only data is swapped then driver will print -1.
*/
#include <iostream>
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

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

struct node *pairSwap(struct node *head)
{
    struct node *curr = head;
    struct node *prevFirst = NULL;

    bool isPrev = true;
    while (curr != NULL)
    {
        struct node *first = curr;
        struct node *prev = NULL;
        int count = 0;
        while (curr != NULL && count < 2)
        {
            struct node *temp = NULL;
            temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
            count++;
        }
        if (isPrev)
        {
            head = prev;
            isPrev = false;
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
    struct node *sixth = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = NULL;

    head = pairSwap(head);
    traversal(head);

    return 0;
}