#include<stdio.h>
#include<stdlib.h>
#define ITEM int
typedef struct t
{
    ITEM data;
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

int depth(tree* root)
{
    int lh,rh;
    if(root == NULL)
        return 0;
    
    lh = depth(root->left);
    rh = depth(root->right);

    return (lh > rh)? (lh + 1):(rh + 1);
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

void insert(tree** root,ITEM key)
{
    if(*root == NULL)
        *root = getnode(key);
    
    else if(key < (*root)->data)
        insert(&(*root)->left,key);
    
    else
        insert(&(*root)->right,key);
}

void delnode(tree** root,ITEM key)
{
    tree* temp;
    if(*root == NULL)
        return;
    if(key < (*root)->data)
        delnode(&(*root)->left,key);
    
    else if(key > (*root)->data)
        delnode(&(*root)->right,key);
    
    else
    {
        if((*root)->left == NULL && (*root)->right == NULL)
            free(*root);
        
        else if((*root)->left != NULL && (*root)->right == NULL)
        {
            temp = *root;
            *root = (*root)->left;
            free(temp);
        }

        else if((*root)->left == NULL && (*root)->right != NULL)
        {
            temp = *root;
            *root = (*root)->right;
            free(temp);
        }

        else
        {
            temp = (*root)->right;
            while(temp->left != NULL)
            {
                temp = temp->left;
                (*root)->data = temp->data;
                delnode(&(*root)->right, temp->data);
            }
        }
    }
}

tree* Bsearch(tree* root, ITEM key)
{
    if(root == NULL)
        return NULL;
    else if(root->data == key)
        return root;
    else
    {
        if(root->data < key)
            return Bsearch(root->right,key);
        if(root->data > key)
            return Bsearch(root->left,key);
    }
}

int main()
{
    tree *root  = NULL,*skey;
    int ch,key;
    
    do
    {   
        printf("Press 1 for insertion\n");
        printf("Press 2 for deletion\n");
        printf("Press 3 for searching\n");
        printf("Press 4 for preorder traversal\n");
        printf("Press 5 for inorder traversal\n");
        printf("Press 6 for postorder traversal\n");

        printf("\nEnter choice!\n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            printf("\nEnter a number to insert= ");
            scanf("%d",&key);
            insert(&root,key);
            preorder(root);
            printf("\n");
            break;

            case 2:
            printf("\nEnter a number to delete = ");
            scanf("%d",&key);
            delnode(&root,key);
            preorder(root);
            printf("\n");
            break;

            case 3:
            printf("\nEnter a number to search = ");
            scanf("%d",&key);
            skey = Bsearch(root,key);
            preorder(root);
            printf("\n");
            break;

            case 4:
            printf("\nPreorder traversal\n");
            preorder(root);
            printf("\n");
            break;

            case 5:
            printf("\nInorder traversal\n");
            inorder(root);
            printf("\n");
            break;

            case 6:
            printf("\nPostorder traversal\n");
            postorder(root);
            printf("\n");
            break;

            default: 
            printf("\nNo choice available\n");
            break;
        }
    }while(ch != 7);

    return 0;
}