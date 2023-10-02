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

/*                                  DELETION IN DOUBLEY LINKEDLIST                         */

struct node *deleteAtFirst(struct node **head)
{
    if ((*head) == NULL)
    {
        return NULL;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        return NULL;
    }
    else
    {
        struct node *ptr = *head;
        (*head) = (*head)->next;
        (*head)->previous = NULL;
        free(ptr);
    }
}

void deleteBetweenLast(struct node **head, int position)
{
    struct node *ptr = *head;
    int count = 0;

    if (position == 1)
    {
        deleteAtFirst(head);
    }

    while (ptr != NULL && count != position)
    {
        ptr = ptr->next;
        count++;
    }

    ptr->previous->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->previous = ptr->previous;
    }

    free(ptr);
}

void deleteAtLast(struct node **head)
{
    if ((*head) == NULL)
    {
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        return;
    }

    else
    {
        struct node *ptr = (*head);
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->previous->next = NULL;
        free(ptr);
    }
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
    printf("Insertion at last::\n");
    traversal(head);
    printf("\n");
    printf("Insertion at first::\n");
    insertAtHead(&head, 8);
    traversal(head);

    printf("\n\n");

    //   DELETION FUNCTION
    deleteBetweenLast(&head, 5);
    printf("Deletion at last::\n");
    traversal(head);
    printf("\n");
    deleteAtFirst(&head);
    printf("Deletion at first::\n");
    traversal(head);
}
