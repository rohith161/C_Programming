#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* endPoint = NULL;  // Initialize endPoint as NULL

void error(Node* list){
    if (list == NULL) {
        perror("\nMemory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}
int getSize(Node* list){
    int size = 0;
    Node* current = list;
    while(current != NULL){
        ++size;
        current = current->next;
        if (current->next == NULL)
        {
            break;
        }
    }
    //printf("\n%d\n",size);
    return size;
}

Node* createNode() {
    Node* list = (Node*)malloc(sizeof(Node));
    error(list);
    list->data = 0; 
    list->next = NULL;

    if (endPoint == NULL) {
        endPoint = list;  // Set endPoint to the first created node
    } 

    return list;
}

void add(Node* list, int data) {
    endPoint->data = data;
    Node* newNode = createNode();
    error(newNode);
    endPoint->next = newNode;
    endPoint = newNode;
}

int insert(Node* list,int data,  int index){
    int size = getSize(list);
    if(index < 0 || index >= size){
        printf("\n Index out of bounds\n");
        return -1;
    }
    Node* newNode = createNode();
    if(index == 0){
        newNode->data = list->data;
        newNode->next = list->next;
        list->data = data;
        list->next = newNode;
        return 0;
    }
    else if(index >0 && index < size){
        if(index == size){
            add(list,data);
            return 0;
        }
        Node* prev = list;
        Node* next = NULL;
        for(int i=0; i<index-1; i++){
            prev= prev->next;
        }
        next = prev->next;
        prev->next = newNode;
        newNode->next = next;
        newNode->data = data;
        return 0;
    }
    
}


void getList(Node* list){
    printf("\n[ ");
    while(list != NULL){
        printf("%d ", list->data);
        list = list->next;
        if (list->next == NULL)
        {
            break;
        }
    }
    printf("]\n");
}



int deleteIndex(Node* list, int index){
    //int size = getSize(list);
   if(index < 0 || index >= getSize(list)){
    printf("\n Index Out of Bounds\n");
   }

    Node* prev = list;
    Node* next = list->next;
    if(index == 0){
        list->data = next->data;
        list->next = next->next;
        free(next);
        return 0;
    }
   for(int i=0; i<index; i++){
    if(list == NULL){
         printf("\n Index Out of Bounds\n");
         return -1;
    }
    prev = list;
    list = list->next;
   }

   if(prev != NULL){
    prev->next = list->next;
   }

   free(list);

}
int main(){
        Node* LinkedList = createNode();
        add(LinkedList,1);
        add(LinkedList,2);
        add(LinkedList,3);
        add(LinkedList,4);
        add(LinkedList,5);
        printf("\n%d",getSize(LinkedList));
        getList(LinkedList);
        insert(LinkedList,122,4);
        printf("\n%d",getSize(LinkedList));
        getList(LinkedList);
        deleteIndex(LinkedList,2);
        getList(LinkedList);

        free(LinkedList);

    return 0;
}