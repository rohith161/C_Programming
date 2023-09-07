#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* node;
    int size;
} LinkedList;

/*To keep track of the end of the LinkedList*/
Node* endPoint = NULL;  // Initialize endPoint as NULL 

/* function for Memory allocation failed */
void error(Node* node) {
    if (node == NULL) {
        perror("\nMemory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

/* SIZE of the LinkedList*/
int getSize(LinkedList* list) {
    return list->size;
}

/* To initialize the List */
LinkedList* initLinkedList() {
    LinkedList* list = malloc(sizeof(LinkedList));
    if(list == NULL){
        perror("\nMemory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    list->node = NULL; // Initialize the linked list node to NULL
    list->size = 0;
    
    if (endPoint == NULL) {
        endPoint = list->node;  // Set endPoint to the first created node
    }

    return list;
}

/* To create the new Node every Time the an element is added*/
Node* createNode() {
    Node* node = malloc(sizeof(Node));
    error(node);
    node->data = 0;
    node->next = NULL;
    return node;
}

/* Function to add the new element */
void add(LinkedList* list, int data) {
    Node* newNode = createNode();
    error(newNode);
    newNode->data = data;
    
    if (list->node == NULL) {
        list->node = newNode;
        endPoint = newNode;
    } else {
        endPoint->next = newNode;
        endPoint = newNode;
    }
    
    list->size++;
}

/* function to insert element to particular index */
int insert(LinkedList* list, int data, int index) {
    int size = list->size;
    if (index < 0 || index >= size) {
        printf("\nIndex out of bounds\n");
        return -1;
    }

    Node* newNode = createNode();
    newNode->data = data;

    if (index == 0) {
        newNode->next = list->node;
        list->node = newNode;
    } else {
        Node* current = list->node;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    list->size++;
    return 0;
}


 /* Function to print the element in the list*/
void getList(LinkedList* list) {
    printf("\n[ ");
    Node* current = list->node;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

/* delete the element in the mentioned index */
int deleteIndex(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("\nIndex out of bounds\n");
        return -1;
    }

    if (index == 0) {
        Node* temp = list->node;
        list->node = list->node->next;
        list->size--;
        free(temp);
        return 0;
    } else {  
        Node* current = list->node;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    list->size--;
    return 0;
}

void freeNodes(LinkedList* list){
    Node* current = list->node;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

/* compare function for qsort */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/* To sort the elements in the List in Ascending order*/
void sort(LinkedList* list){
    int* arr = malloc(sizeof(int) * getSize(list));
    if (arr == NULL) {
        perror("\nMemory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    Node* current = list->node;
    for (int i = 0; i < getSize(list); i++) {
        arr[i] = current->data;
        current = current->next;
    }

    // Use qsort to sort the array
    qsort(arr, getSize(list), sizeof(int), compare);

    // Copy the sorted values back into the linked list
    current = list->node;
    for (int i = 0; i < getSize(list); i++) {
        current->data = arr[i];
        current = current->next;
    }

    // Free the temporary array
    free(arr);
}

/* To find the element in the list and return the index*/
int find(LinkedList* list, int object){
    Node* current = list->node;

    for(int i=0; i<getSize(list); i++){
        if(current->data == object){
            return i;
        }
        if((i+1) >= getSize(list)){
            printf("\n Not found\n");
            return -1;
        }
        current = current->next;
    }
}

/* reverse the elements in the list*/
void reverse(LinkedList* list){
    int* arr = malloc(sizeof(int) * getSize(list));
    if (arr == NULL) {
        perror("\nMemory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    Node* current = list->node;
    for (int i = 0; i < getSize(list); i++) {
        arr[i] = current->data;
        current = current->next;
    }

    // Copy the values back into the linked list
    current = list->node;
    for (int i = getSize(list)-1; i>=0;  i--) {
        current->data = arr[i];
        current = current->next;
    }

    // Free the temporary array
    free(arr);
}
int main() {
    LinkedList* list = initLinkedList();
    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);
    add(list, 5);
    printf("\n%d", getSize(list));
    getList(list);
    insert(list, 122, 2);
    printf("\n%d", getSize(list));
    getList(list);
    deleteIndex(list,4);
    printf("\n%d", getSize(list));
    getList(list);
    sort(list);
    getList(list);
    reverse(list);
    getList(list);

    printf("\n found in index %d ",find(list,3));
    // Free all dynamically allocated memory
    freeNodes(list);
    free(list);

    return 0;
}
