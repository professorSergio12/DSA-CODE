#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
// CIRCULAR LINKED LIST (TRAVERSAL)
void intraversal(struct node *head)
{
	struct node *ptr = head;
	do
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	} while (ptr != head);
}

// INSERTION AT FIRST BY CIRCULAR LINKED LIST
struct node *insertion_at_first(struct node *head, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;

	struct node *p = head->next;

	if (head == NULL)
	{
		ptr->next = ptr;
		return ptr;
	}
	else
	{
		while (p->next != head)
		{
			p = p->next;
		}
		p->next = ptr;
		ptr->next = head;
		head = ptr;
		return head;
	}
}

struct node *insertAtEnd(struct node *head, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;

	if (head == NULL)
	{
		ptr->next = ptr;
		return ptr;
	}
	else
	{
		struct node *p = head->next;
		while (p->next != head)
		{
			p = p->next;
		}
		p->next = ptr;
		ptr->next = head;
		return head;
	}
}

struct node *deleteAtfirst(struct node *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		struct node *ptr = head;
		while (ptr->next != head)
		{
			ptr = ptr->next;
		}
		ptr->next = head->next;
		free(head);
		return (ptr->next);
	}
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
	fourth->next = head;

	printf("Before insertion::\n");
	intraversal(head);

	printf("\n");
	printf("Insertion at first::\n");
	head = insertion_at_first(head, 100);
	intraversal(head);

	printf("\n");
	printf("Insertion at last::\n");
	head = insertAtEnd(head, 3);
	intraversal(head);

	printf("\n");
	printf("Delete at first::\n");
	head = deleteAtfirst(head);
	intraversal(head);
}
