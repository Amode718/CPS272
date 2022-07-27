#include <iostream>
#include <stdlib.h>
#include "linked_list.h"

using namespace std;


void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

struct node *createNode(int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    new_node->data  = new_data;
    new_node->next =  NULL;

    return new_node;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void MoveNode(struct node** destRef, struct node** sourceRef)
{
    struct node* newNode = *sourceRef;
    assert(newNode != NULL);

    *sourceRef = newNode->next;
    newNode->next = *destRef;

    *destRef = newNode;
}

void removeDuplicate(struct node **c)
{
    struct node *temp = *c;
    while(temp != NULL && temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            if (temp->next->next != NULL)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp->next = NULL;
            }
        }
        else
        {
            temp = temp->next;
        }
    }
}

void sortLists(struct node* a, struct node *b, struct node **c)
{
    struct node temp;
    struct node* tail = &temp;

    temp.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
          
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);

        tail = tail->next;
    }

    *c = temp.next;
    removeDuplicate(c);


}

int sum(struct node *head)
{
    int total = 0;
    struct node *temp = head;
    while(temp != NULL)
    {
        total += temp->data;
        temp = temp->next;
    }
    return total;
}

double average(struct node *head)
{
    double total = 0.0;
    int count = 0;
    struct node *temp = head;
    while(temp != NULL)
    {
        total += temp->data;
        count++;
        temp = temp->next;
    }

    return (total/count);
}