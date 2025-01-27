#include <iostream> 
using namespace std; 

template <typename Type> 
class Node{

    public: 
    Type data; 
    Node*next; 
    Node*prev; 
    Node(Type value):data(value),next(nullptr),prev(nullptr){}
};

template <typename Type> 
class Queue{
    Node<Type>* head; 
    Node<Type>*tail;
    public: 

    Queue():head(nullptr),tail(nullptr){}

    bool isEmpty(){
        return head==nullptr;
    }

    void enQueue(Type data){
        Node<Type>* newNode = new Node<Type>(data);
        if (isEmpty())
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode; 
        newNode->prev = tail; 
        tail= newNode;
    }

    Type deQueue(){
        if(isEmpty()){
            cerr<<"Queue is Empty"<<endl;
            return Type();
        }
        Node<Type>* nodeToDelete = head; 
        head = head->next; 
        head->prev = nullptr; 

        if(head==nullptr){
            tail = nullptr;
        }

        Type value = nodeToDelete->data; 
        delete nodeToDelete;
        return value;
    }

    Type peek(){
        if(isEmpty()){
            cerr<<"Queue is Empty"<<endl;
            return Type();
        }
        return head->data;
    }

    ~Queue(){
        while (!isEmpty())
        {
            Node<Type>* nodeToDelete = head; 
            head = head->next; 
            delete nodeToDelete;
        }
        
    }
};