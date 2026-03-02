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
    }else{printf("Can't Allocate\n");return NULL;}

}

size_t len(struct Node *head)
{
    struct Node *node = head;
    size_t length = 0;
    while(node != NULL){
        length++;
        node = (node->next);
    }
    return length;

}

void append(struct Node *head, int data)
{
    struct Node *node = head;
    while(node->next != NULL){
        node = node->next;
    }

    insert(node,data);

}

size_t find(struct Node *head, int data)
{
    struct Node *node = head;
    size_t index = 0;
    if(node != NULL){
        while(node != NULL && node->data != data){
            node = node->next;
            index++;
        }
    }else{
        printf("head cannot be NULL\n");
        return -1;
    }
    if(node->data == data){
        return index;
    }else{return -1;}

}

struct Node *delNode(struct Node **head, struct Node *node)
{
    if(head == NULL || node == NULL){
        printf("Invalid node or head\n");
        return NULL;
    }else if(node == *head){
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return *head;
    }else {

        struct Node *cur = *head;
        struct Node *prev;

        struct Node *next = (node->next);

        while (cur != NULL){
            if(cur->next == node){
                prev = cur;
                free(cur->next);
                
                prev->next = next;
                
                return prev->next;
            }
            cur = cur->next;
        }
    
        printf("Couldn't find the node\n");
        return NULL;
    }
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
    
    printf("length %zu\n",len(head));
    
    printf("Index of 0 %zu\n",find(head,0));
    printf("Index of 2 %zu\n",find(head,2));

    
    delNode(&head,head->next);
    delNode(&head,head->next->next); 
    traverse(head);
   
    free_ll(head); 

    /* TODO
     * reverse
     * insert at some index
     * sort
     * insert at beginning
    */

}
