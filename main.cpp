
#include <iostream>
#include "DLinkedList.h"
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
    cll.display();   // 5 10 20 30

    // Acceso a extremos
    cout << "Front: " << cll.front() << ", Back: " << cll.back() << endl;

    // Insertar en posicion
    cll.insert(99, 2);
    cout << "Despues de insert(99, 2): ";
    cll.display();   // 5 10 99 20 30

    // Eliminar al inicio y final
    cll.pop_front();
    cll.pop_back();
    cout << "Despues de pop_front y pop_back: ";
    cll.display();   // 10 99 20

    // Reverse
    cll.reverse();
    cout << "Despues de reverse: ";
    cll.display();   // 20 99 10

    // Clear
    cll.clear();
    cout << "Despues de clear, empty?: " << (cll.empty() ? "Si" : "No") << endl;

    return 0;
}
