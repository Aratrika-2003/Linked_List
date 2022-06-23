#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
    int data;
    struct st *right;
    struct st *left;
}tree;

tree* getnode(int val)
{
    tree* temp = (tree*)malloc(sizeof(tree));

    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

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

int main()
{
    tree* root = NULL;
    root = getnode(1);
    root->left = getnode(2);
    root->right = getnode(3);
    root->left->left = getnode(4);
    root->left->right = getnode(5);

    printf("\nThe preorder traversal ");
    preorder(root);

    printf("\nThe inorder traversal ");
    inorder(root);

    printf("\nThe postorder traversal ");
    postorder(root);

    return 0;
}