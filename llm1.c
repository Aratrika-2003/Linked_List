#include"ll1.h"

int main()
{
    node* head = NULL;

    append(&head, 1);

    add_before(&head,2);

    add_before(&head,4);

    append(&head, 3);
    
    add_after(head->next,5);

    traverse(head);

    return 0;
}