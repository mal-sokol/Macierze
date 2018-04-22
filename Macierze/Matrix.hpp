#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

template<typename T, size_t COLS, size_t ROWS> class Matrix
{
public:
	Matrix();
	~Matrix();
	
//	void fillRow(size_t r);
	void fill();
	
	template <typename U, size_t M, size_t N> friend ostream& operator << (ostream& os, const Matrix<U, M, N>& m);
	
    T operator()(size_t col, size_t row) const
    {
        return matrix[row][col];
    }

    T& operator()(size_t col, size_t row)
    {
        return matrix[row][col];
    }

//	T& operator () (const size_t column, const size_t row);
	bool operator == (const Matrix<T, COLS, ROWS>& right);
	bool operator != (const Matrix<T, COLS, ROWS>& right);
	Matrix<T, COLS, ROWS> operator + (const Matrix<T, COLS, ROWS>& right);
	Matrix<T, COLS, ROWS> operator - (const Matrix<T, COLS, ROWS>& right);
	Matrix<T, COLS, ROWS>& operator = (const Matrix<T, COLS, ROWS>& right);
	
	Matrix<T, ROWS, COLS> Transposed();
	
private:
	T** matrix;
	size_t numOfRows;
	size_t numOfColumns;
};



template<typename T, size_t COLS, size_t ROWS>
Matrix<T, COLS, ROWS>::Matrix()
{
	matrix = new T*[ROWS];
	
	for (size_t r = 0; r < ROWS; r++) {
		matrix[r] = new T[COLS];
		for (size_t c = 0; c < COLS; c++) {
			matrix[r][c] = 0;
		}
	}
	
	numOfRows = ROWS;
	numOfColumns = COLS;
}



template<typename T, size_t COLS, size_t ROWS>
Matrix<T, COLS, ROWS>::~Matrix()
{
	for (size_t r = 0; r < ROWS; r++) {
		cout << "destroing row " << r+1 << endl;
		delete[] matrix[r];
		}
	delete[] matrix;
	cout << "MATRIX DESTROYED" << endl;
}



template<typename T, size_t COLS, size_t ROWS>
void Matrix<T, COLS, ROWS>::fill() {
	
	for (size_t r = 0; r < ROWS; r++) {
		for (size_t c = 0; c < COLS; c++) {
			cin >> matrix[r][c];				//wczytywanie niezabezpieczone
//			while(!cin.good()) {
//				cin.ignore(1000, '\n');
//				cin >> matrix[r][c];
//				}
			}
	}
	cin.ignore(1000, '\n');
}




//---------------------------------------< OPERATORS >------------------------------------------//


//template <typename T, size_t COLS, size_t ROWS>
//T& Matrix<T, COLS, ROWS>::operator () (const size_t column, const size_t row) {
//	
//	size_t x = column-1;
//	size_t y = row-1;
//	
////	try { 
////		if( column<1 || column>COL || row<1 || row>ROW) {
////		throw 1;
////		}
////		return matrix[x][y];
////	}
////	catch(int e) {
////		cout << "Wspolrzedne poza zakresem" << endl;
////	}
//	return this->matrix[y][x];
//}



template<typename T, size_t COLS, size_t ROWS>
Matrix<T, COLS, ROWS>& Matrix<T, COLS, ROWS>::operator = (const Matrix<T, COLS, ROWS>& right) {
	
	for (size_t i = 0; i < numOfRows; i++) {
		for (size_t j = 0; j < numOfColumns; j++) {
			this->matrix(i, j) = right(i, j);
		}
	}
	return *this;
}


template<typename T, size_t COLS, size_t ROWS>
bool Matrix<T, COLS, ROWS>::operator == (const Matrix<T, COLS, ROWS>& right) {
	
	for (size_t i = 0; i < numOfRows; i++) {
		for (size_t j = 0; j < numOfColumns; j++) {
			if (this->matrix(i, j) != right(i, j)) {
				return false;
			}
		}
	}
    return true;
}



template<typename T, size_t COLS, size_t ROWS>
bool Matrix<T, COLS, ROWS>::operator != (const Matrix<T, COLS, ROWS>& right) {
	
	return !(*this == left);
}



template<typename T, size_t COLS, size_t ROWS>
Matrix<T, COLS, ROWS> Matrix<T, COLS, ROWS>::operator + (const Matrix<T, COLS, ROWS>& right) {
	
	Matrix<T, COLS, ROWS> result;
	
	for(size_t i = 0; i < ROWS; i++) {
		for(size_t j = 0; j < COLS; j++) {
				result(i, j) = matrix(i, j) + right(i,j);
		}
	}
	return result;
}



template<typename T, size_t COLS, size_t ROWS>
Matrix<T, COLS, ROWS> Matrix<T, COLS, ROWS>::operator - (const Matrix<T, COLS, ROWS>& right) {
	
	Matrix<T, COLS, ROWS> result;
	
	for(size_t i = 0; i < ROWS; i++) {
		for(size_t j = 0; j < COLS; j++) {
				result(i, j) = matrix(i, j) - right(i, j);
		}
	}
	return result;
}



template <typename U, size_t M, size_t N, size_t K>
Matrix<U, K, N> operator * (const Matrix<U, M, N>& left, const Matrix<U, K, M>& right) {
	
	Matrix<U, K, N> result;
	
	for(size_t i = 0; i < N; i++) {
		for(size_t j = 0; j < M; j++) {
			for(size_t k = 0; k < K; k++) {
			result(i, j) += left(i, k) * right(k, j);
			}
		}
	}
	return result;
}



template <typename U, size_t M, size_t N>
ostream& operator << (ostream& os, const Matrix<U, M, N>& m) {
	
	for(size_t i = 0; i<m.numOfRows; i++) {
		os << "| ";
		for(size_t j = 0; j<m.numOfColumns; j++) {
			os << setw(3) << setprecision(2) << m.matrix[i][j] << ' ';
		}
		os << '|' << endl;
	}
	
	return os;
}
//----------------------------------------------------------------------------------------------//


template<typename T, size_t COLS, size_t ROWS>
Matrix<T, ROWS, COLS> Matrix<T, COLS, ROWS>::Transposed() {
	
	Matrix<T, ROWS, COLS> result;
	
	for(size_t i = 0; i<ROWS; i++) {
		for(size_t j = 0; j<COLS; j++) {
			result(j, i) = matrix(i, j);
		}
	}
	
	return result;
}

#endif // MATRIX_HPP
