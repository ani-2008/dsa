#include <stdio.h>
#include <stdlib.h>

// for simplicity the data of Node of linked list will be a int

struct Node{
    int data;
    struct Node *next;

};
size_t sizeof_Node = sizeof(struct Node);

void traverse(struct Node *head)
{
    struct Node *node = head;
    while(node != NULL){
        printf("%d->",node->data);
        node = (node->next);
    }
    printf("NULL\n");
}

void free_ll(struct Node *head)
{
    struct Node *node = head;
    while(node != NULL){
        struct Node *temp = node;
        node = node->next;
        free(temp);
    }
}

void insert(struct Node *node, int data)
{
    
    if (node != NULL){
        struct Node *new = malloc(sizeof_Node);
        if (new == NULL){
            printf("Can't insert\n");
        }else{
            new->data = data;
            new->next = node->next;
        
            node->next = new;
        }
        
    }else{printf("Can't insert after a NULL node\n");}
    
}

struct Node *ll_init(int data)
{
    struct Node *head = malloc(sizeof_Node);
    if (head != NULL){

        head->data = data;
        head->next = NULL;
        return head;
    }else{printf("Can't insert\n");}
}

void append(struct Node *head, int data)
{
    struct Node *node = head;
    while(node->next != NULL){
        node = node->next;
    }

    insert(node,data);

}

int main()
{
    
    
    struct Node *head = ll_init(0);
    
    traverse(head); // 0->NULL

    append(head,1);

    traverse(head); // 0->1->NULL
    
    append(head,2); 
    
    traverse(head); // 0->1->2->NULL
    
    insert((head->next),1);

    traverse(head); // 0->1->1->2->NULL

    free_ll(head); 

    /* TODO
     * Search value
     * delete a node
     * length
     * reverse
     * insert at some index
     * sort
     * insert at beginning
    */

}
