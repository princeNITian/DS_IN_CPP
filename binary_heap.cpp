#include<iostream>
using namespace std;

class BinaryMinHeap{
    private:
        int *heap;
        int heapSize;
        int arraySize;

        int getLeftChild(int index){
            return 2*index+1;
        }
        int getRightChild(int index){
            return 2*index+2;
        }
        int getParent(int index){
            return (index-1)/2;
        }
        void swap(int i,int j){
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }
        bool hasLeft(int index){
            return getLeftChild(index) < heapSize;
        }
        bool hasRight(int index){
            return getRightChild(index) < heapSize;
        }

    public:
        BinaryMinHeap(int size){
            heap = new int[size];
            heapSize = 0;
            arraySize = size;
        }
        void insert(int data){
            if(heapSize == arraySize)
                return;
            else{
                heapSize++;
                heap[heapSize-1] = data;
                heapifyUp(heapSize-1);
            }
        }
        void heapifyUp(int index){
            if(index != 0){
                int parent = getParent(index);
                if(heap[parent]>heap[index]){
                    swap(parent,index);
                    heapifyUp(parent);
                }
            }
        }
        void printData(){
            for(int i=0;i<heapSize;i++){
                cout<<heap[i]<<" ";
            }
            cout<<endl;
        }
        int removeMin(){
            if(heapSize == 0)
                return -1;
            else{
                int root = heap[0];
                heap[0] = heap[heapSize - 1];
                heapSize--;
                if(heapSize > 1)
                    heapifyDown(0);
                return root;
            }
        }
        void heapifyDown(int index){
            int leftChild = getLeftChild(index);
            int rightChild = getRightChild(index);
            int min = index;
            if(hasLeft(index) && heap[leftChild] < heap[min])
                min = leftChild;
            if(hasRight(index) && heap[rightChild] < heap[min])
                min = rightChild;
            if(min != index){
                swap(index,min);
                heapifyDown(min);
            }
        }
};



int main(){
    BinaryMinHeap heap(7);
    heap.insert(10);
    heap.insert(5);
    heap.insert(3);
    heap.insert(1);
    heap.printData();
    cout<<heap.removeMin()<<endl;
    cout<<heap.removeMin()<<endl;
    heap.printData();
}