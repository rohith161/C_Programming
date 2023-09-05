#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct ArrayList{
    int* element;
    int size ;

}ArrayList;

ArrayList * createArrayList(){
    ArrayList * list;
    list->element = calloc(0,sizeof(int));
    list->size = 0;
    return list;
}

int append(ArrayList* list,int num){
    list->element = realloc(list->element,(list->size+1)*sizeof(int));
    list->element[list->size] = num;
    list->size++;
}
void getList(ArrayList* list){
    printf("\n");
    for(int i=0; i<list->size; i++){
        printf("%d ",list->element[i]);
    }
    printf("\n");
    
}
int getSize(ArrayList* list){
    return list->size;
}

int getindex(ArrayList* list,int index){
    if(index >= list->size){
        printf("\nIndex Out of Bound\n");
        return -1;
    }
    printf("\n%d\n",list->element[index]);
}

int delete(ArrayList* list,int index){
    if(index >= list->size){
        printf("\nIndex Out of Bound\n");
        return -1;
    }
    for(int i = index; i<list->size; i++){
        list->element[i] = list->element[i+1];
    }
    list->size--;
    free(list);
}

int addFirst(ArrayList* list, int num){
    list->element = realloc(list->element,(list->size+1)*sizeof(int));
    for(int i=list->size; i>=1; i--){
        list->element[i] = list->element[i-1];
    }
    list->element[0] = num;
    list->size++;
}

int insert(ArrayList* list,int data, int index){
    if(index <0 || index >= list->size){
        printf("\nIndex out of bound\n");
        return -1;
    }
    list->element = realloc(list->element, (list->size+1) * sizeof(int));
    for(int i = list->size; i>index; i--){
       list->element[i] = list->element[i-1];
        
    }
    list->size++;

    list->element[index] = data;
    return 0;
}
int main(){
    ArrayList* list = createArrayList();
    append(list,12);
    append(list,23);
    append(list,26);
    append(list,13);
    append(list,67);
    printf("\n%d\n",getSize(list));
    getList(list);
    delete(list,1);
    printf("\n%d\n",getSize(list));
    getList(list);
    addFirst(list,12333);
    printf("\n%d\n",getSize(list));
    getList(list);
    insert(list,11,4);
    getList(list);
    
    return 0;
}