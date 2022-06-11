#include<stdio.h>
#define ITEM int
typedef struct t
{
    ITEM data;
    struct t *left;
    struct t *right;
}tree;

void preorder(tree* root)
{
    if(root == NULL)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(tree* root)
{
    if(root == NULL)
        return;
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(tree* root)
{
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}