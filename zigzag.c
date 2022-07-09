//zigzag traversal
#include<stdio.h>
#include<stdlib.h>
typedef struct t
{
    int data;
    struct t *left;
    struct t *right;
}tree;

tree* getnode(int val)
{
    tree* temp = (tree*)malloc(sizeof(tree));

    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void zigzag(tree* root)
{
    tree* temp = NULL;
    if(root == NULL)
    {
        printf("\nTree can't be traversed\n");
        return;
    }
    else
    {
        temp = root;
        printf("%d ",root->data);
        if(root->right != NULL || root->left == NULL)
        {
            printf("%d ",root->right->data);
            printf("%d ",root->left->data);

            while(root->left != NULL)
                root = root->left;
        }
        else if(root->right == NULL || root->left != NULL)
        {
            printf("%d ",root->right->data);
            printf("%d ",root->left->data);

            while(root->right != NULL)
               root = root->right;
        }
    }
}
/*void preorder(tree* root)
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
}*/

int main()
{
    tree* root = NULL;
    root = getnode(1);
    root->left = getnode(2);
    root->right = getnode(3);
    root->left->left = getnode(4);
    root->left->right = getnode(5);

    zigzag(root);
    /*preorder(root);
    inorder(root);
    postorder(root);*/

    return 0;
}