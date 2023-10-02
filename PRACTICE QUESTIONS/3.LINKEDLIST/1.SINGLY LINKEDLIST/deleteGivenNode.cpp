// Given only a pointer/reference to a node to be deleted in a singly linked list, how do you delete it?

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

void deleteNode(struct node *ptr)
{
    struct node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    free(temp);
}

// JAVA CODE

// void DeleteNode(Struct node* ptr)
// {
//     ptr.data = ptr.next.data;
//     ptr.next = ptr.next.next;
// }

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

    deleteNode(head);

    cout << "\nAfter deleting \n";
    traversal(head);

    return 0;
}
