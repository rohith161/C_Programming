#include <stdio.h>
#include <stdlib.h>

typedef struct Link {
    void* data;
    struct Link* left;
    struct Link* right;
}Link;

typedef struct BinarySearchTree {
    Link* node;
}BinarySearchTree;

BinarySearchTree* init_BinarySearchTree(){
    BinarySearchTree* bst = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    if(bst == NULL){
        printf("\nMemory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }
    bst->node = NULL;
    return &(*bst);
}
Link* createLink(void* data){
    Link* newNode = (Link*)malloc(sizeof(Link));
    if(newNode == NULL){
        printf("\nMemory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(BinarySearchTree* root, void* data){
    Link* newNode = createLink(data);;
    if(root->node == NULL){
        root->node = newNode;
        return;
    }
    Link* current = root->node;
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

int search(BinarySearchTree* root, void* data){
    Link* current = root->node;
    while (current != NULL)
    {
        if (current == NULL)
        {
            return 0;
        }
        else if(current->data == data){
            return 1;
        }
        else if(current->data > data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return 0;
}
void* findMin(Link* root){
    if(root == NULL){
        printf("\nEmpty Tree\n");
        return (void*)-1;
    }
    else if(root->left == NULL){
        return root->data;
    }
    return findMin(root->left);
    
}
void* findMax(BinarySearchTree* root){
    if(root->node == NULL){
        printf("\nEmpty Tree\n");
        return (void*)-1;
    }
    Link* current = root->node;
    while (current->right != NULL)
    {
        current = current->right;
    }
    
    return current->data;
}
int max(int l, int r){
    return (l > r)? l : r;
}
int findHeight(Link* root){
    if(root == NULL){
        return -1;
    }
    return max(findHeight(root->left),findHeight(root->right))+1;
}