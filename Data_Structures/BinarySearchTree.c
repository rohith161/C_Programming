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
        else if(current->data > data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return 0;
}

// recurrsion method
// int findMin(Node* root){
//     if(root == NULL){
//         printf("\nEmpty Tree\n");
//         return -1;
//     }
//     else if(root->left == NULL){
//         return root->data;
//     }
//     return findMin(root->left);
    
// }
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
int max(int l, int r){
    return (l > r)? l : r;
}
int findHeight(Node* root){
    Node* current = root;
    if(current == NULL){
        return -1;
    }
    return max(findHeight(current->left),findHeight(current->right))+1;
}
void inOrderrecurrceive(Node* root){
    if(root == NULL) return;
   
    inOrderrecurrceive(root->left);
    printf("%d ",root->data);
    inOrderrecurrceive(root->right);
}
void preOrderrecurrceive(Node* root){
    if(root == NULL) return;
    printf("%d ",root->data);
    preOrderrecurrceive(root->left);
    preOrderrecurrceive(root->right);
}
void preOrder(BinarySearchTree* root){
    preOrderrecurrceive(root->node);
}
void inOrder(BinarySearchTree* root){
    inOrderrecurrceive(root->node);
}
int main(){
    BinarySearchTree* b = init_BinarySearchTree();
    insert(b,15);
    insert(b,10);
    insert(b,20);
    insert(b,25);
    insert(b,14);
    insert(b,8);
    printf("\n%s",(search(b,15)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,10)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,20)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,25)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,11)) ? "FOUND" : "NOT FOUND");
    printf("\n%d",findMin(b));
    printf("\n%d",findMax(b));
    printf("\nheight -- > %d ",findHeight(b->node));
    printf("\nBinary tree node :");
    preOrder(b);
    printf("\nBinary tree node in sorted :");
    inOrder(b);
    return 0;
}