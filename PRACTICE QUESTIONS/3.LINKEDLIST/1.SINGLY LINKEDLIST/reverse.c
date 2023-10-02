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

struct node *insert(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node *insert_at_last(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
void reverse(struct node **head)
{
    struct node *current = *head;
    struct node *prev = NULL;
    struct node *temp = NULL;

    while (current != NULL)
    {
        temp = current->next;
        current->next = prev;

        prev = current;
        current = temp;
    }
    *head = prev;
}

struct node *createNode(struct node *head)
{
    int n, data;
    printf("Enter the number of node u want to ::");
    scanf("%d", &n);
    head = NULL;
    if (n == 0)
    {
        return head;
    }
    printf("Enter the value to be inserted:: ");
    scanf("%d", &data);
    head = insert(head, data);

    for (int i = 2; i <= n; i++)
    {
        printf("Enter the value to be inserted:: ");
        scanf("%d", &data);
        head = insert_at_last(head, data);
    }
    return head;
}

int main()

{
    struct node *head = NULL;
    head = createNode(head);

    printf("Before reverse:: \n");
    traversal(head);

    reverse(&head);
    printf("\nAfter reverse::\n ");
    traversal(head);
}