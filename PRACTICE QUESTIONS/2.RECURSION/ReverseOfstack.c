#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
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

void push(struct node **top, int data)
{
    if (full(*top))
    {
        printf("The stack is overflow\n");
    }
    else
    {
        struct node *n = malloc(sizeof(struct node));
        n->data = data;
        n->next = *top;
        (*top) = n;
    }
}

int pop(struct node **top)
{
    if (empty(*top))
    {
        printf("The stack is underflow\n");
    }
    else
    {
        struct node *n = *top;
        int x = n->data;
        *top = (*top)->next;
        free(n);
        return x;
    }
}

void insertAtbottom(struct node **s, int x)
{
    if (empty(*s))
    {
        push(s, x);
    }
    else
    {
        int temp = pop(s);
        insertAtbottom(s, x);

        push(s, temp);
    }
}

void reverse(struct node **top)
{
    if (!empty(*top))
    {
        int x = pop(top);

        reverse(top);

        insertAtbottom(top, x);
    }
}

int main()
{
    struct node *top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    push(&top, 5);

    printf("Stack elements before reverse:\n");
    display(top);

    reverse(&top);
    printf("\n\n");

    printf("Stack elements after reverse:\n");
    display(top);
    return 0;
}
