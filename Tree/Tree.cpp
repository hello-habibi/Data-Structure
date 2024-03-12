// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};
struct node *root = NULL;


void insert(int data) {

    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;
    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    if (root == NULL)
    {
        root = tempNode;
    }
    else
    {
        current = root;
        parent = NULL;
        while (1)
        {
            parent = current;
            if (data < parent->data)
            {
                current = current->leftChild;

                if (current == NULL)
                {
                    parent->leftChild = tempNode;
                    return;
                }
            }
            else{
                current = current->rightChild;
                if(current == NULL){
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}
void inorder_traversal (struct  node *root){
    if(root != NULL){
        inorder_traversal(root->leftChild);
        cout<<root->data<<" ";
        inorder_traversal(root->rightChild);
    }
}
void preorder_traversal(struct  node *root){
    if(root != NULL){
        cout<<root->data <<" ";
        preorder_traversal(root->leftChild);
        preorder_traversal(root->rightChild);
    }
}
void postorder_traversal(struct node *root){
    if(root !=NULL){
        postorder_traversal(root->leftChild);
        postorder_traversal(root->rightChild);
        cout<<root->data <<" ";
    }
}


int main()
{
    int i;
    int arry[7] = {27 , 14 , 35 , 10 , 19, 31 ,42 };
    for(int num: arry){
        insert(num);
    } 
    cout<<"Inorder Traversal : ";//first left sub-tree , root then right sub-tree
    inorder_traversal(root);
    cout<<"\n";
    cout<<"Preorder Traversal : ";//first root , left sub-tree , right sub-tree
    preorder_traversal(root); cout<<endl;
    cout<<"Postorder Traversal : ";//first left sub-tree , right sub-tree , root 
    postorder_traversal(root);
    return 0;
}