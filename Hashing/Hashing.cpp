#include<iostream>
using namespace std;
#define SIZE 4

struct  DataItem{
    int key;
};
struct  DataItem *hashingArray[SIZE];

int hashCode(int key){


    return key % SIZE ;
}

void insert(int key){
    struct DataItem  *newItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    if(newItem == NULL){
        cout<<"Memory Allocation Error " <<endl;
        return;
    }
    newItem->key = key;

    int hashIndex = hashCode(key);
    while(hashingArray[hashIndex] != NULL){
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashingArray[hashIndex] = newItem;
}   

 void search(int key){
    int hashIndex = hashCode(key);
    int originalIndex = hashIndex;

    while(hashingArray[hashIndex] != NULL){
        if(hashingArray[hashIndex] ->key == key){
            cout<<"Found the Item : "<< key <<endl;
            return;
        }
        ++hashIndex;
        hashIndex %= SIZE;
        if(hashIndex == originalIndex){
            break;
        }
    }

    cout<<"Not found the item in the HashTable . " << endl ;
    return ;
 }




int main (){
    insert(23);
    insert(4);
    insert(5);
    insert(7);
    for(int i=0; i<SIZE ;i++){
        if(hashingArray[i] != NULL){
            cout<<"Index : " << i << " Key " <<hashingArray[i]->key<<endl;
        }
    }
    search(23);
    search(4);
    search(22);


    return 0;
}