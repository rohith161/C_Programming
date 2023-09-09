#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct BinarySearchTree {
    Node* node;
}BinarySearchTree;

BinarySearchTree* init_BinarySearchTree(){
    BinarySearchTree* bst = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    if(bst == NULL){
        printf("\nMemory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }
    bst->node = NULL;
    return bst;
}
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("\nMemory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(BinarySearchTree* root, int data){
    Node* newNode = createNode(data);;
    if(root->node == NULL){
        root->node = newNode;
        return;
    }
    Node* current = root->node;
    while (1)
    {
        if(data <= current->data){
            if(current->left == NULL){
                current->left = newNode;
                return;
            }
            current = current->left;
        }
        else {
            if(current->right == NULL){
                current->right = newNode;
                return;
            }
            current = current->right;
        }
    }
    
    
}

int search(BinarySearchTree* root, int data){
    Node* current = root->node;
    while (current != NULL)
    {
        if (current == NULL)
        {
            return 0;
        }
        else if(current->data == data){
            return 1;
        }
        else if(current->data < data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return 0;
}
int findMin(BinarySearchTree* root){
    if(root->node == NULL){
        printf("\nEmpty Tree\n");
        return -1;
    }
    Node* current = root->node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    
    return current->data;
}
int findMax(BinarySearchTree* root){
    if(root->node == NULL){
        printf("\nEmpty Tree\n");
        return -1;
    }
    Node* current = root->node;
    while (current->right != NULL)
    {
        current = current->right;
    }
    
    return current->data;
}
int main(){
    BinarySearchTree* b = init_BinarySearchTree();
    insert(b,15);
    insert(b,10);
    insert(b,20);
    insert(b,25);
    insert(b,14);insert(b,8);
    printf("\n%s",(search(b,15)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,10)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,20)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,25)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,11)) ? "FOUND" : "NOT FOUND");
    printf("\n%d",findMin(b));
    printf("\n%d",findMax(b));
    
    return 0;
}