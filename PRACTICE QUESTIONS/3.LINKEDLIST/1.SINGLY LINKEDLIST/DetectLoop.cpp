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

// change the point again and again
bool detectLoop(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *curr = head;

    while (curr != NULL)
    {
        if (curr->next == NULL)
            return false;
        if (curr->next == ptr)
            return true;

        struct node *curr_next = curr->next;
        curr->next = ptr;
        curr = curr_next;
    }
    return false;
}

// Time complexity: - O(n)
// Auxilary space:- O(n)

bool DetectLoop(struct node *head)
{
    unordered_set<struct node *> s;
    struct node *curr;
    for (curr = head; curr != NULL; curr = curr->next)
    {
        if (s.find(curr) != s.end())
        {
            return true;
        }
        s.insert(curr)
    }
    return false;
}

bool DetecTloop(struct node *head)
{
    struct node *fast = head;
    struct node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
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

    if (DetectLoop(head))
        cout << "Loop Found";
    else
        cout << "No Loop";

    return 0;
}
