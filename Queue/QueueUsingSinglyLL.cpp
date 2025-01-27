#include <iostream> 
using namespace std; 

template <typename Type> 
class Node{
    public: 
    Type data; 
    Node* next; 

    Node(Type data):data(data),next(nullptr){}
};

template <typename Type> 
class Queue{

    Node<Type>*head;
    Node<Type>*tail;
    int size =0; 
    public: 
    Queue():head(nullptr),tail(nullptr){}

    bool isEmpty(){
        return head==nullptr;
    }
    void enQueue(Type data){
        Node<Type>* newNode = new Node<Type>(data);
        if(isEmpty()){
            head = tail = newNode;
            size++;
            return; 
        }
        tail->next = newNode; 
        tail= newNode; 
        size++;
    }
    Type deQueue(){
        if(isEmpty()){
            cerr<<"Queue is Empty!"<<endl; 
            return Type();
        }

        Node<Type> *nodeToDelete = head; 
        head= head->next; 

        Type value = nodeToDelete->data; 

        delete nodeToDelete; 
        size--;
        return value;
    }

    Type peek(){
        if(isEmpty()){
            cerr<<"Queue is Empty!"<<endl; 
            return Type();
        }
        return head->data;
    }


    ~Queue(){
        while (!isEmpty())
        {
            Node<Type> *nodeToDelete = head; 
            head= head->next; 
            delete nodeToDelete; 
        }
        
    }
    int getSize(){
        return size;
    }
};