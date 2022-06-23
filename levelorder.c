#include<stdio.h>
#include<stdlib.h>
#define ITEM int
typedef struct st
{
    ITEM data;
    struct st *left;
    struct st *right;
}tree;

void display_level(tree* root,int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ",root->data);
    else if(level > 1)
    {
        return display_level(root->left,level - 1);
        return display_level(root->right,level - 1);
    }
}

int height(tree* root)
{
    int lh,rh;
    if(root == NULL)
        return 0;
    else
    {
        lh = height(root->left);
        rh = height(root->right);

        return (lh > rh)? (lh + 1):(rh + 1);
    }
}

void level_order(tree* root)
{
    if(root == NULL)
        return;
    int h,i;
    h = height(root);
    for(i = 1; i <= h; i++)
        display_level(root,i);
}

tree* getnode(int val)
{
    tree* temp = (tree*)malloc(sizeof(tree));

    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    tree* root = NULL;
    root = getnode(1);
    root->left = getnode(2);
    root->right = getnode(3);
    root->left->left = getnode(4);
    root->left->right = getnode(5);

    printf("\nThe level order traversal of the tree is ");
    level_order(root);

    return 0;
}