#ifndef LINKED_LIST_H
#define LINKED_LIST_H


/* Link list node */
struct node
{
    int data;
    struct node* next;
};

struct node *createNode(int new_data);
void sortedInsert(struct node** head_ref, struct node* new_node);
void printList(struct node *head);
void removeDuplicate(struct node **c);
void sortLists(struct node* a, struct node *b, struct node **c);
int sum(struct node *head);
double average(struct node *head);
#endif