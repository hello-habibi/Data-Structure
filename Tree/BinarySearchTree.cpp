#include <iostream>
using namespace std;
struct node {
    int data;
    struct node *leftChild , *rightChild;
};

struct node *root = NULL;

struct node *newNode(int item){
    struct node *temp = (struct node *) malloc(sizeof(struct node)) ;
    temp->data = item;
    temp->rightChild = temp->leftChild = NULL;
    return temp; 
}
void insert(int data){
    struct node *tempNode = (struct node*) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->leftChild = tempNode->rightChild = NULL;
    if(root == NULL){
        root = tempNode;
    }
    else{
        current = root ;
        parent = NULL;
        while (1)
        {
            parent = current;

            if(data < parent->data){
                current =  current->leftChild;

                if(current == NULL){
                    parent ->leftChild = tempNode;
                    return;
                }
            }
            else{
                current = current->rightChild;
                if (current == NULL)
                {
                    parent ->rightChild = tempNode;
                    return;
                }
                
            }
        }
        
    }
}


void printTree(struct node* node){
    if(node == NULL) return;
    printTree(node->leftChild);
    cout << node->data << " ";
    printTree(node->rightChild);
}

int main(){

  insert(55);
   insert(20);
   insert(90);
   insert(50);
   insert(35);
   insert(15);
   insert(65);
   printf("Insertion done");
   printTree(root);
    return 0;
}