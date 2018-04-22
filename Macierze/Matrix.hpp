#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

template<typename T, size_t COL, size_t ROW> class Matrix
{
public:
	Matrix();
	~Matrix();
	
//	void setValue(T value, size_t r, size_t c) {matrix[r][c] = value;}
//	void fillRow(size_t r);
//	void fill();
	
	template <typename U, size_t M, size_t N> friend ostream& operator<<(ostream& os, const Matrix<U, M, N>& m);
	T& operator() (const size_t column, const size_t row);
	
private:
	T** matrix;
	size_t numOfRows;
	size_t numOfColumns;
};


template<typename T, size_t COL, size_t ROW>
Matrix<T, COL, ROW>::Matrix()
{
	matrix = new T*[ROW];
	
	for (size_t r = 0; r < ROW; r++) {
		matrix[r] = new T[COL];
		for (size_t c = 0; c < COL; c++) {
			matrix[r][c] = 0;
		}
	}
	
	numOfRows = ROW;
	numOfColumns = COL;
}

template<typename T, size_t COL, size_t ROW>
Matrix<T, COL, ROW>::~Matrix()
{
	for (size_t r = 0; r < ROW; r++) {
		cout << "destroing row " << r+1 << endl;
		delete[] matrix[r];
		}
	delete[] matrix;
	cout << "MATRIX DESTROYED" << endl;
}

//template<typename T, size_t ROW, size_t COL>
//void Matrix<T, ROW, COL>::fillRow(size_t r) {
//	
//	for(size_t i = 0; i<COL; i++) {
//		
//	}
//}

template <typename T, size_t COL, size_t ROW>
T& Matrix<T, COL, ROW>::operator() (const size_t column, const size_t row) {
	
	size_t x = column-1;
	size_t y = row-1;
	
//	try { 
//		if( column<1 || column>COL || row<1 || row>ROW) {
//		throw 1;
//		}
//		return matrix[x][y];
//	}
//	catch(int e) {
//		cout << "Wspolrzedne poza zakresem" << endl;
//	}
	return matrix[y][x];
}

template <typename U, size_t M, size_t N> ostream& operator<<(ostream& os, const Matrix<U, M, N>& m) {
	
	for(size_t i = 0; i<m.numOfRows; i++) {
		os << '|';
		for(size_t j = 0; j<m.numOfColumns; j++) {
			os << setw(3) << m.matrix[i][j];
		}
		os << '|' << endl;
	}
	
	return os;
}

#endif // MATRIX_HPP
