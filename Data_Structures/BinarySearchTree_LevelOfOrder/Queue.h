#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    void* data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* node;
}Queue;

Node* endpoint = NULL;

void error(Node* queue){
    if(queue == NULL){
        printf("\nMemory Allocation Failed\n");
        return;
    }
}
Queue* initQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(queue == NULL){
        printf("\nMemory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }
    queue->node = NULL;
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

void* Peek(Queue* queue){
    return queue->node->data;
}

int isEmpty(Queue* queue){
    return (queue->node == NULL)? 1: 0;
}

void enQueue(Queue* queue, void* data){
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

}

void* deQueue(Queue* queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty \n");
        return 0;
    }
    Node* current = queue->node;
    Node* next = queue->node->next;
    void* data = current->data;
    queue->node = next;
    free(current);
    return data;
}
