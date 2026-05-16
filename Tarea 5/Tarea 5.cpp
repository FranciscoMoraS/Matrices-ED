#include <iostream>
#include "Matriz.h"

using std::cin;
using std::ws;
using std::streamsize;
using std::numeric_limits;

int main()
{
    cout << "Ingrese el numero de filas: ";
    int filas;
    while (!(cin >> ws >> filas)) {
        cout << "Error, ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Ingrese el numero de columnas: ";
    int columnas;
    while (!(cin >> ws >> columnas)) {
        cout << "Error, ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Matriz<int>* matriz = new Matriz<int>(filas, columnas);
    bool salir = false;
    while (!salir) {
        matriz->print();
        cout << "getValue(fila, columna) \n";
        cout << "setValue(fila, columna) \n";
        cout << "getRows() \n";
        cout << "getColumns() \n";

    }
}
