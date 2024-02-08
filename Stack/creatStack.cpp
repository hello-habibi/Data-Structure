#include <iostream>
using namespace std;
int MAX_SIZE = 10;
int stack[10];
int topPointer = -1;

int isFull(){
    if(topPointer == MAX_SIZE){
        return 1;
    }else{
        return 0;
    }
}
int isEmpty(){
    if(topPointer == -1){
        return 1;
    }else{
        return 0;
    }
}
int peek(){

    if(!isEmpty()){
        cout<<"thestack is empty "<<endl;  
        return -1;
    }else{
        return stack[topPointer];

    }
    
}
void push(int value){

    if(isFull()){
        cout<<"The stack is filled up . No value can be added"<<endl;
    }else{
            stack[++topPointer] = value;
    }
    }
int pop(){
    if(isEmpty()){
        cout<<"the stack is full empty "<<endl;
    }else{
        return stack[topPointer--];
    }
   
}



int main(){
    
    push(13);
    push(14);
    push(15);
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;

    return 0;
}