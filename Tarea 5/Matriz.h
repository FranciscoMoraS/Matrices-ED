#pragma once

#include <stdexcept>
#include <iostream>

using std::runtime_error;
using std::cout;

template <typename E>
class Matriz{
private:
	int rows;
	int columns;
	E** matriz;

public:
	Matriz(int rows, int columns) {
		if (rows <= 0 || columns <= 0)
			throw runtime_error("Numero de filas y columnas debe ser mayor a cero");
		this->rows = rows;
		this->columns = columns;
		matriz = new E * [rows];
		for (int i = 0; i < rows; i++) {
			matriz[i] = new E[columns];
		}
	}
	~Matriz() {
		for (int i = 0; i < rows; i++) {
			delete[]matriz[i];
		}
		delete[] matriz;
	}
	E getValue(int row, int column) {
		if (row < 0 || row >= rows)
			throw runtime_error("Fila invalida.");
		if (column < 0 || column >= columns)
			throw runtime_error("Columns invalida.");
		return matriz[row][column];
	}
	void setValue(int row, int column, E value) {
		if (row < 0 || row >= rows)
			throw runtime_error("Fila invalida.");
		if (column < 0 || column >= columns)
			throw runtime_error("Columns invalida.");
		matriz[row][column] = value;
	}
	int getRows() {
		return rows;
	}
	int getColumns() {
		return columns;
	}
	void setAll(E value) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matriz[i][j]=value
			}
		}
	}
	void transpose() {
		E** temp = new E * [columns];
		for (int i = 0; i < columns; i++) {
			temp[i] = new E[rows];
		}
		for (int m = 0; m < columns; m++) {
			for (int j = 0; j < rows; j++) {
				temp[m][j] = matriz[j][m];
			}
		}
		for (int i = 0; i < rows; i++) {
			delete[]matriz[i];
		}
		delete[] matriz;
		matriz = temp;
		int t = rows;
		rows = columns;
		columns = t;
	}
	void addRow(E value) {
		E** temp = new E * [rows + 1];
		for (int i = 0; i < rows; i++) {
			temp[i] = matriz[i];
		}
		temp[rows] = new E[columns];
		for (int j = 0; j < columns; j++) {
			temp[rows][j] = value;
		}
		for (int i = 0; i < rows; i++) {
			delete[]matriz[i];
		}
		delete[] matriz;
		matriz = temp;
		rows += 1;
	}
	void addColumn(E value) {
		E** temp = new E * [rows];
		for (int i = 0; i < rows; i++) {
			temp[i] = new E[columns+1];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temp[i][j] = matriz[i][j];
			}
			temp[i][columns] = value;
		}
		for (int i = 0; i < rows; i++) {
			delete[]matriz[i];
		}
		delete[] matriz;
		matriz = temp;
		columns += 1;
	}
	void removeRow(int row) {
		
	}
	void removeColumn(int column) {

	}
	void print() {

	}
};

