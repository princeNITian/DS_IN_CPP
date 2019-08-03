#include<iostream>
using namespace std;


class StackArrayImpl{
    private:
        int size;
        int *stackArr;
        int top;
        
        void resize(){
            int tempSize = size*2;
            int *temp = new int[tempSize];
            for(int i=0;i<size;i++)
                temp[i] = stackArr[i];
            delete [] stackArr;
            stackArr = temp;
            size = tempSize;
        }
        
    public:
        StackArrayImpl(int size){
            this->size = size;
            stackArr = new int[size];
            top = -1;
        }
        
        ~StackArrayImpl(){
            delete [] stackArr;
        }
        
        void push(int data){
            if(top == size-1)
                resize();
                stackArr[++top] = data;
            
        }
        
        int pop(){
            if(top==-1){
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            return stackArr[top--];
        }
        
        void printStack(){
            cout<<"Printed From top: "<<endl;
            for(int i = top;i>=0;i--)
                cout<< stackArr[i]<<endl;
        }
        
        
};


int main(){
    StackArrayImpl  stack(10);
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.printStack();
    cout<<"Popped "<<stack.pop()<<endl;
    stack.printStack();
    
    
    
}
