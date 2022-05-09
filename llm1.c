#include"ll1.h"

int main()
{   
    node* head = NULL;
    int i,data,n,m,p;
    char ch = 'y';

    printf("\nMenu : \n");
    printf("\n---------\n");
    printf("1.Append\n2.Traverse\n3.Add before\n4.Add after\n5.Delete\n6.Print in reverse order\n7.reverse the linked list\n");
    
    while(ch == 'y')
    {
        printf("\nEnter your choice : ");
        scanf("%d",&i);

        switch(i)
        {
            case 1: 
                printf("\nenter a number to be appended ");
                scanf("%d",&data);
                
                append(&head,data);
                traverse();
            break;

            case 2:
                printf("\nThe list of elements \n");
                
                traverse();

            break;

            case 3:
                printf("\nEnter the number to be added before ");
                scanf("%d",&n);

                add_before(&head,n);

                traverse();

            break;

            case 4:
                printf("\nEnter the number to be added after ");
                scanf("%d",&m);

                add_after(head->next,m);

                traverse();

            break;

            case 5:
                delete(head);

                traverse();
            break;

            case 6:
                print_reverse(&head);

            break;

            case 7:
                rec_rev(head);

            break;
        }
    }
    /*append(&head, 1);

    add_before(&head,2);

    add_before(&head,4);

    append(&head, 3);
    
    add_after(head->next,5);

    traverse(head);*/

    return 0;
}
