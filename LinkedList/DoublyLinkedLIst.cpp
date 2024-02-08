#include <iostream>
using namespace std;
typedef struct DoublyLinkedLIst* nodePtr;


nodePtr head = NULL;
nodePtr end = NULL;

struct DoublyLinkedLIst
{
    int data ;
    nodePtr prev=NULL;
    nodePtr next = NULL;
};

void addEnd(int data){
    nodePtr ptrHead = head;
    nodePtr ptrEnd = head;
    nodePtr newNode= (nodePtr)malloc(sizeof(struct DoublyLinkedLIst));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head==NULL){
        head=newNode;
    }else{
        while (ptrHead->next != NULL)
        {
            ptrHead = ptrHead->next;

        }
        newNode->prev = ptrHead;
        ptrHead->next = newNode;
        
    }

}

printList (){
    nodePtr headPtr = head;
    while (headPtr != NULL)
    {
        cout<<headPtr->data<<" ";
        headPtr = headPtr->next;
    }
    cout<<endl;
    
}



int main(){
    addEnd(2);
    addEnd(24);

    printList();



    return 0;
}