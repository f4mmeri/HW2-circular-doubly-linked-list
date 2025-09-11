#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;

    // Para nodos normales
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}

    // Para el nodo centinela
    Node() : next(this), prev(this) {}
};
 
template<typename T>
class CLinkedList{
private:
    Node<T>* head;   // centinela
    int list_size;

public:
    CLinkedList() : head(new Node<T>()), list_size(0) {}

    // Destructor
    ~CLinkedList(){
        clear();
        delete head;
    }

    T front(){
        if(empty()) {
            static T default_value = T();
            return default_value;
        }
        return head->next->data;
    }

    T back(){
        if(empty()) {
            static T default_value = T();
            return default_value;
        }
        return head->prev->data;
    }

    void push_front(T value){
        Node<T>* n = new Node<T>(value);
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
        ++list_size;
    }

    void push_back(T value){
        Node<T>* n = new Node<T>(value);
        n->next = head;
        n->prev = head->prev;
        head->prev->next = n;
        head->prev = n;
        ++list_size;
    }

    T pop_front(){
        if(empty()) {
            static T default_value = T();
            return default_value;
        }
        Node<T>* temp = head->next;
        T value = temp->data;
        head->next = temp->next;
        temp->next->prev = head;
        delete temp;
        --list_size;
        return value;
    }

    T pop_back(){
        if(empty()) {
            static T default_value = T();
            return default_value;
        }
        Node<T>* temp = head->prev;
        T value = temp->data;
        head->prev = temp->prev;
        head->prev->next = head;
        delete temp;
        --list_size;
        return value;
    }

    void insert(T value, int position){
        if(position < 0 || position > list_size) return;
        if(position == 0){ 
            push_front(value); 
            return; 
        }
        if(position == list_size){ 
            push_back(value); 
            return; 
        }

        Node<T>* n = new Node<T>(value);
        Node<T>* temp = head->next;
        for(int i = 0; i < position; ++i) {
            temp = temp->next;
        }

        n->next = temp;
        n->prev = temp->prev;
        temp->prev->next = n;
        temp->prev = n;
        ++list_size;
    }

    void remove(int position){
        if(position < 0 || position >= list_size) return;
        if(position == 0){ 
            pop_front(); 
            return; 
        }
        if(position == list_size - 1){ 
            pop_back(); 
            return; 
        }

        Node<T>* temp = head->next;
        for(int i = 0; i < position; ++i) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        --list_size;
    }

    T operator[](int position){
        if(position < 0 || position >= list_size) {
            static T default_value = T();
            return default_value;
        }
        Node<T>* temp = head->next;
        for(int i = 0; i < position; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    bool empty(){ 
        return head->next == head; 
    }
    
    int size(){ 
        return list_size; 
    }

    void clear(){
        Node<T>* temp = head->next;
        while(temp != head){
            Node<T>* del = temp;
            temp = temp->next;
            delete del;
        }
        head->next = head;
        head->prev = head;
        list_size = 0;
    }

    void reverse(){
        Node<T>* curr = head;
        do{
            Node<T>* nxt = curr->next;
            curr->next = curr->prev;
            curr->prev = nxt;
            curr = nxt;
        } while(curr != head);
    }
};

#endif //FUNCTIONS_H