#include"stackll.h"

typedef struct t
{
    ITEM data;
    struct t *left;
    struct t *right;
}tree;

void preorder(tree* root)
{
    stack s;
    init(&s);

    while(!isempty(&s))
    {
        printf("%d ",root->data);

        if(root->right != NULL)
            push(&s,root->right);

        if(root->left != NULL)
            push(&s,root->left);

        else
            root = pop(&s);
    }
}

void inorder(tree* root)
{
    stack s;
    while(1)
    {
        while(root != NULL)
        {
            push(&s,root);
            root = root->left;
        }
        if(isempty(&s) == 1)
            break;
        else
        {
            root = pop(&s);
            printf("%d ",root->data);
            root = root->right;
        }
    }
}

void postorder(tree* root)
{
    stack s;
    tree* temp;
    do
    {
        while(root != NULL)
        {
            if(root->right != NULL)
                push(&s,root);
            push(&s,root);
            root = root->left;
        }

        if(!isempty(&s))
        {
            root = pop(&s);
            if(root->right == peek(&s))
            {
                temp = pop(&s);
                push(&s,root);
                root = temp;
            }
            else
            {
                printf("%d ",root->data);
                root = NULL;
            }
        }
    } while (!isempty(&s));
}