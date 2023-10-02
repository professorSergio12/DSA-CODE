#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int occurrences(struct node *head, int key)
{
    int count = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == key)
            count++;
        ptr = ptr->next;
    }
    return count;
}

int search(struct node *head, int key)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->data == key)
        {
            return TRUE;
        }
        ptr = ptr->next;
    }
    return FALSE;
}

struct node *insert(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node *insert_at_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *createnode(struct node *head)
{
    int n, data;
    printf("Enter the number of node u want::");
    scanf("%d", &n);
    head = NULL;
    if (n == 0)
    {
        return head;
    }
    printf("Enter the value of node::");
    scanf("%d", &data);
    head = insert(head, data);

    for (int i = 2; i <= n; i++)
    {
        printf("Enter the value of node::");
        scanf("%d", &data);
        head = insert_at_end(head, data);
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    int n;
    head = createnode(head);

    printf("\nEnter element to count occurrences : ");
    scanf("%d", &n);
    printf("\nThe element %d occurs %d times\n", n, occurrences(head, n));

    int flag = search(head, 23);
    if (flag == FALSE)
    {
        printf("Element  is not found in this list\n");
    }
    else
    {
        printf("Element  is  found in this list\n");
    }

    return 0;
}
