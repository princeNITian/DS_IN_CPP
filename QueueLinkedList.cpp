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

class QueueLinkedListImpl{
    private:
    Node *front;
    Node *rear;
    public:
        QueueLinkedListImpl(){
            front = rear = NULL;
        }
        ~QueueLinkedListImpl(){
            Node *next;
            while(front!=NULL){
                next = front->next;
                delete front;
                front = next;
            }
        }
        void enqueue(int data){
            Node *n = new Node(data);
            if(rear == NULL){
                rear = front = n;
            }else{
                rear->next = n;
                rear = n;
            }
        }
        
        int dequeue(){
            if(front==NULL){
                cout<<"Empty Queue"<<endl;
                return -1;
            }
            Node *temp = front;
            int tempData = front->data;
            if(front==rear){
                front = rear = NULL;
            }else{
                front = front->next;
            }
            delete temp;
            return tempData;
        }
        
        void printList(){
            Node *temp = front;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
        
        
        
};

int main(){
    QueueLinkedListImpl q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.printList();
    q.dequeue();
    q.printList();
}





