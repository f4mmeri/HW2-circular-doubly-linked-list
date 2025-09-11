#include <iostream>
#include "DLinkedList.h"  // Cambié el nombre del header
using namespace std;

int main() {
    cout << "\n=== PRUEBAS CIRCULAR DOUBLY LINKED LIST ===" << endl;
    CLinkedList<int> cll;

    // Inserciones
    cll.push_back(10);
    cll.push_back(20);
    cll.push_back(30);
    cll.push_front(5);
    cout << "Lista circular despues de push_front y push_back: ";
    
    // Mostrar usando operator[] y size()
    for(int i = 0; i < cll.size(); i++) {
        cout << cll[i] << " ";
    }
    cout << endl;   // 5 10 20 30

    // Acceso a extremos
    cout << "Front: " << cll.front() << ", Back: " << cll.back() << endl;

    // Insertar en posicion
    cll.insert(99, 2);
    cout << "Despues de insert(99, 2): ";
    for(int i = 0; i < cll.size(); i++) {
        cout << cll[i] << " ";
    }
    cout << endl;   // 5 10 99 20 30

    // Eliminar al inicio y final
    cout << "Removido del frente: " << cll.pop_front() << endl;
    cout << "Removido del final: " << cll.pop_back() << endl;
    cout << "Despues de pop_front y pop_back: ";
    for(int i = 0; i < cll.size(); i++) {
        cout << cll[i] << " ";
    }
    cout << endl;   // 10 99 20

    // Reverse
    cll.reverse();
    cout << "Despues de reverse: ";
    for(int i = 0; i < cll.size(); i++) {
        cout << cll[i] << " ";
    }
    cout << endl;   // 20 99 10

    // Pruebas adicionales
    cout << "Tamano actual: " << cll.size() << endl;
    cout << "Elemento en posicion 1: " << cll[1] << endl;
    
    // Clear
    cll.clear();
    cout << "Despues de clear, empty?: " << (cll.empty() ? "Si" : "No") << endl;
    cout << "Tamano despues de clear: " << cll.size() << endl;

    return 0;
}