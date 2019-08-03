#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class LinkedList{
    private:
        Node *header;
        Node *tail;
        int size;
    public:
        LinkedList(){
            header = NULL;
            tail = NULL;
            size = 0;
        }
        
        int getSize() {
            return size;
        }
        
        void append(int data){
            // Create a new Node
            Node *n = new Node(data);
            //Case 1: Empty List
            if(header == NULL){
                header = n;
                tail = n;
            }
            //Case 2: List is not Empty
            else{
                tail->next = n;
                tail = n;
            }
            //Increment the size counter
            size++;
        }
        
        void prepend(int data) {
            // Create new node 
            Node *n = new Node(data);
            // Case 1: Empty List
            if(header == NULL){
                header = n;
                tail = n;
            }
            //Case 2: List is not Empty
            else{
                Node *temp = header;
                header = n;
                n->next = temp;
            }
            // Increment size counter
            size++;
        }
           
        void printList(){
            //Create a temp pointer 
            // that points to first Node
            Node *temp = header;
            
            // Create Loop that stops when pointer is NULL
            while(temp != NULL){
               //Print data
               cout<< temp->data<<" ";
            //Advance pointer to next Node 
            temp = temp->next;
            }
            
            cout<<endl;
        } 
        
        void removeFirstNode(){
            //Case 1: empty list
            
            //Case 2: not empty list
            if(header != NULL){
                Node *temp = header;
                header = header->next;
                delete temp;
                size--;
            }
        }
        
        void removeLastNode(){
            // Case 1: empty
            // Case 2: 1 Node
            if(header->next == NULL){
                removeFirstNode();
            }
            // Case 3: More than one
            else if(header != NULL){
                Node *cur = header;
                Node *prev;
                while(cur->next != NULL){
                prev = cur;
                cur = cur->next;
            }
            tail = prev;
            prev->next =  NULL;
            delete cur;
            size--;
        }
        }
        
        void removeAt(int pos){
            // Case 1: check for valid pos
            if(pos>size || pos<1)
                return;
            // Case 2: check if Pos is the first Node
            else if(pos==1)
            removeFirstNode();
            // Case 3: check if Pos is the last Node
            else if(pos == size)
            removeLastNode();
            // Case 4: All other cases
            else if(header != NULL){
                Node *cur = header;
                Node *prev;
                for(int i = 1;i<pos;i++){
                    prev = cur;
                    cur = cur->next;
                }
                prev->next = cur->next;
                delete cur;
                size--;
            }
            
        }
        
        void insertAt(int pos,int data){
            // Case 1: check if insertion at begining of list
            if(pos > size + 1 || pos < 1)
            return;
            // Case 2: check if insertion at begining of list
            else if(pos==1){
                prepend(data);
            }
            // Case 3: check if insertion at end of list
            else if(pos == size+1){
                append(data);
            }
            // Case 4: all other cases
            else if(header != NULL){
                Node *n = new Node(data);
                Node *prev;
                Node *cur = header;
                for(int i = 1;i<pos;i++){
                    prev = cur;
                    cur = cur->next;
                }
                
                prev->next = n;
                n->next  = cur;
                size++;
            }
        }
        
        ~LinkedList(){
            Node *next;
            while(header!=NULL){
                next = header->next;
                delete header;
                header = next;
            }
        }  
};

int main(){
    LinkedList list;
    list.prepend(20);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.prepend(10);
    list.printList();
    list.removeFirstNode();
    list.removeLastNode();
    list.printList();
    list.removeAt(1);
    list.printList();
    list.insertAt(4,10);
    list.printList();
}






