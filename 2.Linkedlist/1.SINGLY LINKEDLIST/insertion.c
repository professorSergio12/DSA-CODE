#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
//TRAVERSAL
void intraversal(struct node *ptr)
{
	while (ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}
//INSERT AT FIRST POSITION
	struct node *insertfirst(struct node *head, int data)
	{
		struct node *ptr = (struct node *)malloc(sizeof(struct node));
		ptr->data = data;
		ptr->next = head;
		return ptr;
	}

// INSERT INBETWEEN THE ELEMENTS
struct node *inbetween(struct node *head, int data, int index)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	int i = 0;
	struct node *p = head;
	while (i != index - 1)
	{
		p = p->next;
		i++;
	}
	ptr->next = p->next;
	p->next = ptr;
	return head;
}

//INSERT AT LAST BEFORE NULL POINTER
struct node *ina_t_last(struct node *head, int data)
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

//INSERT THE ELEMENT IF WE KNOW THE INDEX
struct node *insert_after_node(struct node *head, struct node *pre, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;

	ptr->next = pre->next;
	pre->next = ptr;

	return head;
}
int main()
{
	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *second = (struct node *)malloc(sizeof(struct node));
	struct node *third = (struct node *)malloc(sizeof(struct node));
	struct node *fourth = (struct node *)malloc(sizeof(struct node));

	head->data = 8;
	head->next = second;

	second->data = 45;
	second->next = third;

	third->data = 73;
	third->next = fourth;

	fourth->data = 98;
	fourth->next = NULL;

	printf("Before insertion::\n");
	intraversal(head);

	head = insertfirst(head, 34);
	printf("After insertion::\n");

	head = inbetween(head, 44, 3);
	printf("After insertion::\n");
	intraversal(head);

	head = in_at_last(head, 44);
	printf("After insertion::\n");
	intraversal(head);

	head = insert_after_node(head, third, 100);
	printf("After insertion::\n");
	intraversal(head);
}
