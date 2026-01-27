#include <stdio.h>
#include <stdlib.h>

struct bstNode{
    int val;
    struct bstNode *left;
    struct bstNode *right;
};

struct bstNode *createNode(int val)
{
    struct bstNode *newNode = malloc(sizeof(struct bstNode));
    if(newNode)
    {
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

struct bstNode *insertNode(struct bstNode *root, int val)
{
    if(root != NULL){
        return createNode(val);
    }

    if(val < root->val){
        root->left = insertNode(root->left,val);
    }else if(val > root->val){
        root->right = insertNode(root->right,val);
    }

    return root;
}

void inorder(struct bstNode *root)
{
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->val);
        inorder(root->right);
    }

}

struct bstNode *freeTree(struct bstNode *root)
{
    //TODO
    if(root != NULL){
        struct bstNode *x = freeTree(root->left);
        free(x);
        struct bstNode *y = freeTree(root->right);
    }
}
int main()
{
    /* TEST 0
    struct bstNode *root = createNode(8);
    root->left = createNode(3);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);
    root->right = createNode(10);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    inorder(root);
    printf("\n");
    */
    /* TEST 1 */
    struct bstNode *root = NULL;
    root = insertNode(root,8);
    root = insertNode(root,3);
    root = insertNode(root,10);
    root = insertNode(root,1);
    root = insertNode(root,6);
    root = insertNode(root,4);
    root = insertNode(root,7);
    root = insertNode(root,10);
    root = insertNode(root,14);
    root = insertNode(root,13);
    root = insertNode(root,15);
    
    inorder(root);
    printf("\n");
   //SEGFAULT 
    /* TODO
     * check insertNode
     * search
     * delete
     * some more methods
    */
}

