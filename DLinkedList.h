
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;

    // Para nodos normales
    Node(T value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
    // Para el nodo centinela
    Node(){
        next = this;
        prev = this;
    }
};

template<typename T>
class CLinkedList{
private:
    Node<T>* head;   // centinela
    int size = 0;

public:
    CLinkedList(){
        head = new Node<T>();   // centinela
        head->next = head;
        head->prev = head;
        size = 0;
    }

    void display(){
        Node<T>* temp = head->next;
        while(temp != head){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    T front(){
        if(head->next == head) throw runtime_error("lista vacia");
        return head->next->data;
    }

    T back(){
        if(head->prev == head) throw runtime_error("lista vacia");
        return head->prev->data;
    }

    void push_front(T value){
        Node<T>* n = new Node<T>(value);
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
        ++size;
    }

    void push_back(T value){
        Node<T>* n = new Node<T>(value);
        n->next = head;
        n->prev = head->prev;
        head->prev->next = n;
        head->prev = n;
        ++size;
    }

    T pop_front(){
        if(head->next == head) throw runtime_error("lista vacia");
        Node<T>* temp = head->next;
        T value = temp->data;
        head->next = temp->next;
        temp->next->prev = head;
        delete temp;
        --size;
        return value;
    }

    T pop_back(){
        if(head->prev == head) throw runtime_error("lista vacia");
        Node<T>* temp = head->prev;
        T value = temp->data;
        head->prev = temp->prev;
        head->prev->next = head;
        delete temp;
        --size;
        return value;
    }

    void insert(T value, int position){
        if(position < 0 || position > size) throw runtime_error("Posicion no encontrada");
        if(position == 0){ push_front(value); return; }
        if(position == size){ push_back(value); return; }

        Node<T>* n = new Node<T>(value);
        Node<T>* temp = head->next;
        for(int i=0; i<position; ++i) temp = temp->next;

        n->next = temp;
        n->prev = temp->prev;
        temp->prev->next = n;
        temp->prev = n;
        ++size;
    }

    void remove(int position){
        if(position < 0 || position >= size) throw runtime_error("Posicion no encontrada");
        if(position == 0){ pop_front(); return; }
        if(position == size-1){ pop_back(); return; }

        Node<T>* temp = head->next;
        for(int i=0; i<position; ++i) temp = temp->next;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        --size;
    }

    T operator[](int position){
        if(position < 0 || position >= size) throw runtime_error("Posicion no encontrada");
        Node<T>* temp = head->next;
        for(int i=0; i<position; ++i) temp = temp->next;
        return temp->data; // solo lectura (copia)
    }

    bool empty(){ return head == head->next; }
    int Size(){ return size; }

    void clear(){
        Node<T>* temp = head->next;
        while(temp != head){
            Node<T>* del = temp;
            temp = temp->next;
            delete del;
        }
        head->next = head;
        head->prev = head;
        size = 0;
    }

    void reverse(){
        Node<T>* curr = head;
        do{
            Node<T>* nxt = curr->next;
            curr->next = curr->prev;
            curr->prev = nxt;
            curr = nxt;
        }while(curr != head);
    }

};

#endif //FUNCTIONS_H
