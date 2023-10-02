#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int empty(struct node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int full(struct node *ptr)
{
    struct node *n = malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

void push(struct node **head, int element)
{
    if (full(*head))
    {
        printf("The stack is overflow\n");
    }
    else
    {
        struct node *n = malloc(sizeof(struct node));
        n->data = element;
        n->next = *head;
        *head = n;
    }
}

int pop(struct node **head)
{
    if (empty(*head))
    {
        printf("The stack is underflow\n");
    }
    else
    {
        struct node *n = *head;
        int x = n->data;
        *head = (*head)->next;
        free(n);
        return x;
    }
}

int top(struct node *s)
{
    return (s->data);
}

void sortedInsert(struct node **s, int x)
{
    // Base case: Either stack is empty or newly inserted
    // item is greater than top (more than all existing)
    if (empty(*s) || x > top(*s))
    {
        push(s, x);
        return;
    }

    // If top is greater, remove the top item and recur
    int temp = pop(s);
    sortedInsert(s, x);

    // Put back the top item removed earlier
    push(s, temp);
}

// Function to sort stack
void sortStack(struct node **s)
{
    // If stack is not empty
    if (!empty(*s))
    {
        // Remove the top item
        int x = pop(s);

        // Sort remaining stack
        sortStack(s);

        // Push the top item back in sorted stack
        sortedInsert(s, x);
    }
}

int main()
{
    struct node *top = NULL;

    push(&top, 34);
    push(&top, 4);
    push(&top, 3);
    push(&top, 23);
    push(&top, 12);

    printf("Stack elements before sorting:\n");
    display(top);

    sortStack(&top);
    printf("\n\n");

    printf("Stack elements after sorting:\n");
    display(top);

    return 0;
}
