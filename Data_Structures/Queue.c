#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* node;
    int size;
    int capacity;
}Queue;

Node* endpoint = NULL;

void error(Node* queue){
    if(queue == NULL){
        printf("\nMemory Allocation Failed\n");
        return;
    }
}
Queue* initQueue(int size){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(queue == NULL){
        printf("\nMemory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }
    queue->node = NULL;
    queue->capacity = size;
    queue->size = 0;
    if(endpoint == NULL){
        endpoint = queue->node;
    }
    return queue;
}

Node* createNode(){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 0;
    newNode->next = NULL;
    return newNode;
}

int Peek(Queue* queue){
    return queue->node->data;
}

int isEmpty(Queue* queue){
    return (queue->node == NULL)? 1: 0;
}

void enQueue(Queue* queue, int data){
    if(queue->size == queue->capacity){
        printf("\n Queue is Full\n");
        return;
    }
    Node* newnode = createNode();
    error(newnode);
    newnode->data = data;
    if(queue->node == NULL){
        queue->node = newnode;
        endpoint = newnode;
    }
    else{
        endpoint->next = newnode;
        endpoint = newnode;
    }
    queue->size++;

}

int deQueue(Queue* queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty \n");
        return 0;
    }
    Node* current = queue->node;
    Node* next = queue->node->next;
    int data = current->data;
    queue->node = next;
    free(current);
    queue->size--;
    return data;
}


int main(){
    Queue* q = initQueue(5);
    enQueue(q,1);
    //printf("%d ",Peek(q));
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);
    enQueue(q,5);
    printf(" is empty %d \n",isEmpty(q));
    while (!isEmpty(q))
    {
        printf("%d ",deQueue(q));
    }
    deQueue(q);

   
        printf(" \nis empty %d ",isEmpty(q));
    
    
    return 0;
}