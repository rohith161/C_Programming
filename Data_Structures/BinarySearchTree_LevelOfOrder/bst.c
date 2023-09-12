#include "BST.h"
#include "Queue.h"

void levelOrderTraversal(Link* root) {
    if (root == NULL) {
        return;
    }
    Queue* Q = initQueue();
    enQueue(Q, (Link*)root);
    while (!isEmpty(Q)) {
        Link* current = (Link*)Peek(Q);
        printf("%s ", current->data);
        if (current->left != NULL) {
            enQueue(Q, (Link*)current->left);
        }
        if (current->right != NULL) {
            enQueue(Q, (Link*)current->right);
        }
        deQueue(Q);
    }
}



int main(){
    BinarySearchTree* b = init_BinarySearchTree();
    insert(b,"hello");
    insert(b,"how");
    insert(b,"are");
    float f = 5.7568f;
    insert(b,&f);
    insert(b,"I'm");
    insert(b,"fine .");
    printf("\n%s",(search(b,"hello")) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,10)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,"fine .")) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,5)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",(search(b,123)) ? "FOUND" : "NOT FOUND");
    printf("\n%s",findMin(b->node));
    printf("\n%s",findMax(b));
    printf("\nheight -- > %d",findHeight(b->node));
    levelOrderTraversal(b->node);
    
    return 0;
}