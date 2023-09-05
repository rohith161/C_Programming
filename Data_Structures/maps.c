#include <stdio.h>
#include <stdlib.h>

typedef struct elements{
    int keys;
    int values;
}elements;

typedef struct maps{
    elements* keyValues;
    int size;
}maps;


maps* createMap(){
    maps* dic = (maps*) malloc(sizeof(maps));
    if(dic ==NULL){
        perror("Memory Allocation Failed -- map");
        exit(EXIT_FAILURE);
    }
    dic->keyValues = (elements*) malloc(sizeof(dic->keyValues));
    if(dic->keyValues ==NULL){
        perror("Memory Allocation Failed -- key-value");
        exit(EXIT_FAILURE);
    }
    dic->size = 0;
    return dic;
}

void add(maps* dic, int key, int value){
    int size = dic->size;
    dic->keyValues = realloc(dic->keyValues, (size + 1) * sizeof(elements));
    if(dic->keyValues+size == NULL){
        perror("Memory Allocation Failed -- key values");
        exit(EXIT_FAILURE);
    }
   int i=0;
    for( i=0; i<size; i++){
    if(dic->keyValues->keys == key){
        perror("\nDupliacte key\n");
        exit(EXIT_FAILURE);
    }
    else{
        continue;
    }
    }
    if(i >= size){
        dic->keyValues[size].keys = key;
        dic->keyValues[size].values = value;
        dic->size = size+1;
    }
}

void getMaps(maps* dic){
    int size = dic->size;
    printf("\n");
    for(int i=0; i<size; i++){
    printf("\"%d\" -- > %d\n",dic->keyValues[i].keys, dic->keyValues[i].values);
    }
    printf("\n");
}

void getMapsIndex(maps* dic, int index){
    int size = dic->size;
    printf("\n");
    printf("\"%d\" -- > %d",dic->keyValues[index].keys, dic->keyValues[index].values);
    printf("\n");
}
 void getSize(maps* dic){
    printf("\n%d\n",dic->size);

 }

void deleteMap(maps* dic,int index){
    int size = dic->size;
    for(int i=index; i<size; i++){
        dic->keyValues[i].keys = dic->keyValues[i+1].keys;
        dic->keyValues[i].values = dic->keyValues[i+1].values;
    }
    dic->size--;
    dic->keyValues = realloc(dic->keyValues, dic->size * sizeof(elements));
}
int main(){

    maps* map = createMap();
    add(map, 1, 1);
    add(map, 2, 2);
    add(map, 3, 3);
    add(map, 4, 4);
    add(map, 5, 5);
    getSize(map);
    getMaps(map);
    getMapsIndex(map,2);
    deleteMap(map,0);
    getSize(map);
    getMaps(map);
    add(map,6,6);
    getSize(map);
    getMaps(map);
    deleteMap(map,4);
    getSize(map);
    getMaps(map);


    return 0;
}