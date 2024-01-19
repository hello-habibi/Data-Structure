#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct LinkedList
{
    int value;
    struct LinkedList *next;
};

struct LinkedList *head =  (struct LinkedList *) malloc(sizeof(struct LinkedList));
// struct LinkedList *current = NULL;

void printList()
{
   struct LinkedList *ptr = head->next;

    while (ptr != NULL)
    {
        printf("%d ",ptr->value);
        ptr = ptr->next;
    }
    cout<<endl;
}
void addEnd(int data)
{
    struct LinkedList *ptr = head;
    struct LinkedList *newItem = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    newItem->value = data;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    cout<<"done"<< endl;

    }
    ptr->next = newItem;
    newItem->next = NULL;
}
void addFirst (int data){
    struct LinkedList *ptr = head;
    struct LinkedList *newItem = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    newItem ->value = data;
    newItem ->next = head ;
    head = newItem;
}
int sumList(){
    int sum =0;

    struct LinkedList *ptr = head->next;
    while (ptr != NULL)
    {
        sum += ptr->value;
        ptr= ptr->next;
    }
    return sum;
}

int main()
{
    head->next = NULL;
    cout<<"done"<<endl;
    addEnd(4);
    addEnd(4);

    //addFirst(34);

    //addFirst(43);

    printList();

    cout<<sumList()<<endl;

    return 0;
}