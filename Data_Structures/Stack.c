#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct Stack
{
    Node* Top;
}Stack;

Stack* initStack(){
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->Top = NULL;

    return newNode;
}
void push(Stack* stack, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->Top;

    stack->Top = newNode;
    
}

int pop(Stack* stack){
    if(stack->Top == NULL){
        printf("\nEmpty Stack\n");
        return -1;
    }
    Node* current = stack->Top;
    int data = current->data;
    stack->Top = stack->Top->next;
    free(current);
    return data;

}
int Top(Stack* stack){
    if(stack->Top == NULL){
        printf("\nEmpty Stack\n");
        return -1;
    }
    return stack->Top->data;

}
bool isEmpty(Stack* stack){
    return (stack->Top)? true : false;

}

void clear(Stack* stack){
    while (stack->Top != NULL)
    {
        Node* next = stack->Top->next;
        free(stack->Top);
        stack->Top = next;
    }
    free(stack);
    
}
int main(){
    Stack* stack = initStack();
    Top(stack);
    int n = 0, d = 0;
    printf("\nEnter the number of times want to stack : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
    printf("\nEnter the Data : ");
    scanf("%d",&d);
    push(stack,d);
    }
    for(int i=0; i<n; i++){
    printf("%d ",pop(stack));
    }
    // for(int i=0 ; i<n; i++){
    //     printf("\n%d --> ",pop(stack));
    //     printf("%d",isEmpty(stack));
    // }

    return 0;
}