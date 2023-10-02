#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

int getHeight(struct node* n)
{
    if (n==NULL)
    {
        return 0;
    }
    return n->height;
}

struct node* createNode(int data)
{
    struct node* n=malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}

int getBalanceFactor(struct node* n)
{
    if(n==NULL)
    {
        return 0;
    }
    return getHeight(n->left)-getHeight(n->right);
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
struct node* rightRotate(struct node* y)
{
    struct node* x=y->left;
    struct node* T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;

    return x;
}

struct node* leftRotate(struct node* x)
{
    struct node* y=x->right;
    struct node* T2=y->left;

    y->left=x;
    x->right=T2;

    y->height=max(getHeight(y->right),getHeight(y->left))+1;
    x->height=max(getHeight(x->right),getHeight(x->left))+1;

    return y;
}

struct node* insert(struct node* root,int key)
{
    if(root==NULL)
    {
        return createNode(key);
    }
    if(key<root->data)
    {
        root->left=insert(root->left,key);
    }
    else
    {
        root->right=insert(root->right,key);
    }
    
    root->height=1+max(getHeight(root->right),getHeight(root->left));
    int bf=getBalanceFactor(root);

//Left Left rotation
    if (bf>1 && key<root->left->data)
    {
        return rightRotate(root);
    }
//Right Right rotation  
     if (bf<-1 && key>root->right->data)
    {
        return leftRotate(root);
    }

//Right Left rotation
    if (bf<-1 && key<root->left->data)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

//Left Right rotation
    if (bf>1 && key>root->left->data)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    
    return root;
}
struct node* preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    struct node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);

    preorder(root);
    
}