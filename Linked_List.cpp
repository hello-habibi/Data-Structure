#include <iostream>
#include <cstdlib>
using namespace std;


typedef struct node list;

struct node{
    int value;
    struct node *next;
};

struct node *head = NULL; // Here decleared a head of a list

void addNodeEnd(int num){
    struct node *ptr = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // here decleared a new node heap memory to store new data node
    newNode->value = num;                                              // setted the new node value
    newNode->next = NULL;                                              // setted the end point of the new node
    if(ptr == NULL){
        head = newNode;
        return ; 
    }else{
          while (ptr->next != NULL){
                ptr = ptr->next;
        }
        ptr->next = newNode; // setted the last value of the node as newNode
    }
}

void addFirst(int num)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // here decleared a new node heap memory to store new data node
    newNode->value = num;                                              // setted the new node value
    newNode->next = head;                                              // setted the end point of the new node
    head = newNode;
}

void printList()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void addAfter(int num ,int newValue ){

    list *ptr = head;
    list *newNode = (struct node *) malloc(sizeof(struct node));
    newNode -> value = newValue;
    while (ptr->next != NULL)
    {
        if(ptr->value == num){
            newNode->next = ptr->next;
            ptr->next = newNode;
            break;
        }
        ptr = ptr->next;
    }
}


int listSum (){
    int sum =0;
    list *ptr = head->next;
    while (ptr != NULL)
    {
        sum+= ptr->value;
        ptr = ptr->next;
    }
    return sum;
}
void deletItem(int item){
    if(head->value == item){
        head = head->next;
        return;
    }

    list *ptr = head;
    while (ptr->next->value != item)
    {
        ptr = ptr->next;
    }
    if(ptr->next->next == NULL){
        ptr->next = NULL;
    }else{
        ptr->next = ptr->next->next;
    }
    

}

int main()
{
    addNodeEnd(12);
    addNodeEnd(444);
    addFirst(13);
    addFirst(15);
    deletItem(12);
    addAfter(13 , 33);
    printList();
    cout<< listSum() <<endl;
    cout<<head->value;


    return 0;
}