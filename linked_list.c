#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;

};

void traverse(struct Node *head)
{
    struct Node *node = head;
    while(node != NULL){
        printf("%d->",node->data);
        node = (node->next);
    }
    printf("NULL\n");
}


int main()
{
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *first = malloc(sizeof(struct Node));
    head->data = 0;
    head->next = first;
    first->data = 1;
    first->next = NULL;

    traverse(head);

    free(head);
    free(first);

}
