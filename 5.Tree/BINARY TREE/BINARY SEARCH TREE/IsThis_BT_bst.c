#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createnode(int data)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}
// Time Complexity: O(n);
// Space Complexity: O(h);
int isBTS(struct node *root)
{
	static struct node *prev = NULL;
	if (root != NULL)
	{
		if (!isBTS(root->left))
		{
			return 0;
		}
		if (prev != NULL && root->data <= prev->data)
		{
			return 0;
		}
		prev = root;
		return isBTS(root->right);
	}
	else
	{
		return 1;
	}
}

int main()
{
	struct node *p = createnode(5);
	struct node *p1 = createnode(3);
	struct node *p2 = createnode(6);
	struct node *p3 = createnode(1);
	struct node *p4 = createnode(4);

	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;

	if (isBTS(p))
	{
		printf("This is the binary tree\n");
	}
	else
	{
		printf("This is not the binary tree\n");
	}
}
