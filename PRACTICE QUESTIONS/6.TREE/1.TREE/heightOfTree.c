#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node* n=(struct node *)malloc(sizeof(struct  node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int height(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh);
}



int main()
{
     struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    
    int hit=height(p);
    printf("The height of the tree is %d",hit);
}
