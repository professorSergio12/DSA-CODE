#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *random;
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

struct node *cloneLinkedList(struct node *head)
{
    struct node *temp;
    struct node *curr;
    for (curr = head; curr != NULL;)
    {
        temp = curr->next;
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = curr->data;

        curr->next = ptr;
        ptr->next = temp;
        curr = temp;
    }

    for (curr = head; curr != NULL; curr = curr->next->next)
    {
        curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;
    }

    struct node *orig = head;
    struct node *copy = head->next;

    temp = copy;

    while (orig != NULL && copy != NULL)
    {
        orig->next = orig->next->next;
        copy->next = copy->next->next;

        orig = orig->next;
        copy = copy->next;
    }
    return temp;
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
    head->random = third;

    second->data = 2;
    second->next = third;
    second->random = head;

    third->data = 3;
    third->next = fourth;
    third->random = fifth;

    fourth->data = 4;
    fourth->next = fifth;
    fourth->random = fifth;

    fifth->data = 5;
    fifth->next = sixth;
    fifth->random = second;

    sixth->data = 6;
    sixth->next = NULL;

    cout << "Original list : \n";
    traversal(head);

    cout << "\nCloned list : \n";
    struct node *cloned_list = cloneLinkedList(head);
    traversal(cloned_list);
}

// Correct Answer
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *curr = head;
        if (head == NULL)
            return NULL;
        while (curr != NULL)
        {
            Node *temp = curr->next;
            Node *ptr = new Node(curr->val);
            curr->next = ptr;
            ptr->next = temp;

            curr = temp;
        }

        for (Node *temp = head; temp != NULL; temp = temp->next->next)
        {
            temp->next->random = (temp->random != NULL) ? temp->random->next : NULL;
        }

        Node *orig = head;

        Node *dummy = new Node(-1);

        dummy->next = head->next;

        Node *copy = dummy->next;

        while (orig != NULL)
        {
            orig->next = copy->next;
            orig = orig->next;

            if (orig)
            {
                copy->next = orig->next;
                copy = copy->next;
            }
        }
        return dummy->next;
    }
};