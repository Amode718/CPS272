// Andrei Modiga
// CPS-272
// 07/16/2022
// Machine Problem 3
// Linked List

#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
    struct node* head = NULL;

    for(int i = 0; i < 20; i++)
    {
        int randNum = rand()%(101);
        struct node *new_node = createNode(randNum);
        sortedInsert(&head, new_node);

    }

    struct node* head2 = NULL;

    for(int i = 0; i < 15; i++)
    {
        int randNum = rand()%(101);
        struct node *new_node = createNode(randNum);
        sortedInsert(&head2, new_node);
    }

    printf("\nIf the first list has: ");
    printList(head);


    printf("\nAnd the second list has: ");
    printList(head2);

    struct node* res = NULL;
    sortLists(head, head2, &res);

    printf("\nResult: ");

    printList(res);

    printf("\nThe sum of the final list is: %d", sum(res));
    printf("\nThe average of the final list is: %f\n", average(res));

    return 0;
}