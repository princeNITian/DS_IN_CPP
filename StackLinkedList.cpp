

#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class StackLinkedlistImpl{
    private:
        Node *top;
    public:
        StackLinkedlistImpl(){
            top = NULL;
        }
        
        void push(int data){
            Node *n = new Node(data);
            if(top==NULL){
                top = n;
            }else{
                n->next = top;
                top = n;
            }
        }
        
        int pop(){
            if(top==NULL){
                cout<<"Stack is Empty"<<endl;
                return -1;
            }else{
                int tempData = top->data;
                Node *temp = top;
                top = top->next;
                delete temp;
                return tempData;
            }
        }
        
        void printList(){
            Node *temp = top;
            if(top == NULL){
                cout<<"Stack is empty!"<<endl;
            }
            else{
                
                while(temp!=NULL){
                    cout<<temp->data<<endl;
                    temp = temp->next;
                }
            }
        }
};

int main()
{
    StackLinkedlistImpl stack;
    stack.printList();
    stack.push(5);
    stack.push(10);
    stack.push(20);
    stack.printList();
    cout<<"Popped: "<<stack.pop()<<endl;
    cout<<"Popped: "<<stack.pop()<<endl;
    stack.printList();
    return 0;
}
