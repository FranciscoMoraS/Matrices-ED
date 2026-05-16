#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matriz.h"

using std::cin;
using std::ws;
using std::streamsize;
using std::numeric_limits;

void conseguirValor(Matriz<int>* &matriz) {
    int fila;
    int columna;
    cout << "Ingrese el numero de fila: \n";
    while (!(cin >> ws >> fila)||fila<0||fila>=matriz->getRows()) {
        cout << "Fila invalida: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Ingrese el numero de columna: \n";
    while (!(cin >> ws >> columna) || columna<0 || columna>=matriz->getColumns()) {
        cout << "columna invalida: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Valor: "<<matriz->getValue(fila, columna)<<"\n";
}
void cambiarValor(Matriz<int>*& matriz) {
    int fila;
    int columna;
    cout << "Ingrese el numero de fila: \n";
    while (!(cin >> ws >> fila) || fila < 0 || fila >= matriz->getRows()) {
        cout << "Fila invalida: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Ingrese el numero de columna: \n";
    while (!(cin >> ws >> columna) || columna < 0 || columna >= matriz->getColumns()) {
        cout << "columna invalida: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "ingrese el nuevo valor: \n";
    int valor;
    while (!(cin >> ws >> valor) ) {
        cout << "Debe ser un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    matriz->setValue(fila, columna, valor);
}
void cambiarValores(Matriz<int>*& matriz) {
    cout << "ingrese el nuevo valor para toda la matriz: \n";
    int valor;
    while (!(cin >> ws >> valor)) {
        cout << "Debe ser un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    matriz->setAll(valor);
}
void agregarFila(Matriz<int>*& matriz) {
    cout << "Ingrese un valor para iniciar la nueva fila: \n";
    int valor;
    while (!(cin >> ws >> valor)) {
        cout << "Debe ser un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    matriz->addRow(valor);
}
void agregarColumna(Matriz<int>*& matriz) {
    cout << "Ingrese un valor para inicializar la nueva columna: \n";
    int valor;
    while (!(cin >> ws >> valor)) {
        cout << "Debe ser un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    matriz->addColumn(valor);
}
void borrarFila(Matriz<int>*& matriz) {
    int fila;
    cout << "Ingrese el numero de fila que desea borrar: \n";
    while (!(cin >> ws >> fila) || fila < 0 || fila >= matriz->getRows()) {
        cout << "Fila invalida: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    matriz->removeRow(fila);
}
void borrarColumna(Matriz<int>*& matriz) {
    int columna;
    cout << "Ingrese el numero de columna que desea borrar: \n";
    while (!(cin >> ws >> columna) || columna < 0 || columna >= matriz->getColumns()) {
        cout << "columna invalida: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    matriz->removeColumn(columna);
}
void llenarRandom(Matriz<int>*& matriz) {
    srand(time(0));
    for (int i = 0; i < matriz->getRows(); i++) {
        for (int j = 0; j < matriz->getColumns(); j++) {
            matriz->setValue(i, j, rand() % 100);
        }
    }
}

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
    matriz->setAll(0);
    bool salir = false;
    int opcion;
    while (!salir) {
        matriz->print();
        cout << "1-getValue(fila, columna) \n";
        cout << "2-setValue(fila, columna) \n";
        cout << "3-getRows() \n";
        cout << "4-getColumns() \n";
        cout << "5-setAll(valor) \n";
        cout << "6-transpose() \n";
        cout << "7-addRow(valor) \n";
        cout << "8-addColumn(valor) \n";
        cout << "9-removeRow(fila) \n";
        cout << "10-removeColumn(columna) \n";
        cout << "11-Llenar con numeros al azar \n";
        cout << "12-Salir \n";
        while (!(cin >> ws >> opcion)|| opcion<=0||opcion>12) {
            cout << "Opcion no valida: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (opcion == 1) {
            conseguirValor(matriz);
        }
        else if (opcion == 2) {
            cambiarValor(matriz);
        }
        else if (opcion == 3) {
            cout << matriz->getRows() <<"\n";
        }
        else if (opcion == 4) {
            cout << matriz->getColumns()<<"\n";
        }
        else if (opcion == 5) {
            cambiarValores(matriz);
        }
        else if (opcion == 6) {
            matriz->transpose();
        }
        else if (opcion == 7) {
            agregarFila(matriz);
        }
        else if (opcion == 8) {
            agregarColumna(matriz);
        }
        else if (opcion == 9) {
            borrarFila(matriz);
        }
        else if (opcion == 10) {
            borrarColumna(matriz);
        }
        else if (opcion == 11) {
            llenarRandom(matriz);
        }
        else if (opcion == 12) {
            salir = true;
        }

    }
}
