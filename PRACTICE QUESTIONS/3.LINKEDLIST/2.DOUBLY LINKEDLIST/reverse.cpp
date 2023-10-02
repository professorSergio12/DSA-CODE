#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

/*                                   TRAVERSAL OF DOUBLEY LINKEDLIST                                */
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

/*                                   INSERTION IN DOUBLEY LINKEDLIST                             */

void insertAtHead(struct node **head, int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    n->data = data;
    n->next = *head;
    if (*head != NULL)
    {
        (*head)->previous = n;
    }

    *head = n;
}

void insertAtLast(struct node **head, int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = (*head);

    n->data = data;
    if (*head == NULL)
    {
        insertAtHead(head, data);
        return;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->previous = ptr;
}

struct node *reverse(struct node **head)
{
    struct node *current = (*head);
    struct node *prev = NULL;

    if ((*head) == NULL || (*head)->next == NULL)
    {
        return (*head);
    }

    while (current != NULL)
    {
        prev = current->previous;
        current->previous = current->next;
        current->next = prev;
        current = current->previous;
    }
    *head = prev->previous;
    return (*head);
}

/*   MAIN FUNCTION   */
int main()
{
    struct node *head = NULL;

    //   INSERTION FUNCTION
    insertAtLast(&head, 1);
    insertAtLast(&head, 2);
    insertAtLast(&head, 3);
    insertAtLast(&head, 4);
    insertAtLast(&head, 5);

    printf("Before reverse::\n");
    traversal(head);
    printf("\n");

    printf("Reverse of doubly linkedlist::\n");
    reverse(&head);
    traversal(head);
}
