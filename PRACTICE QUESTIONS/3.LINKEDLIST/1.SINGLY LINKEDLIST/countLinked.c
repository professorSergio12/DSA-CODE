#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    printf("\nList is :\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int countOccurrences(struct node *head, int value)
{
    int count = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == value)
            count++;
        ptr = ptr->next;
    }
    return count;
}

struct node *insert(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node *insertEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct node *createList(struct node *head)
{
    int i, n, data;
    printf("Enter the number of nodes u want: ");
    scanf("%d", &n);
    head = NULL;
    if (n == 0)
        return head;

    printf("\nEnter the element to be inserted : ");
    scanf("%d", &data);
    head = insert(head, data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &data);
        head = insertEnd(head, data);
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    int n;
    int value;
    head = createList(head);
    display(head);

    printf("\nEnter element to count occurrences : ");
    scanf("%d", &n);
    printf("\nThe element %d occurs %d times\n", n, countOccurrences(head, n));
}
